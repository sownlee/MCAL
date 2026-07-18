/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: system.c
 *
 * Description: Implementation of system High Level layer
 *              
 * AutoSAR Version:         4.4.0
 *
 * Compiler: GCC IAR
 *
 * Revision:
 *              Version         Date                Change History
 *              0.9.0          23/02/2024           Initial version
 *
 **********************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES
 **********************************************************************************************************************/
#include "system_init.h"
#include "Header.h"
#include "Common.h"
#include "Platform_Types.h"
#include "Compiler.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/
#define SVC_GoToSupervisor()                  ASM_KEYWORD("svc 0x0")
#define SVC_GoToUser()                        ASM_KEYWORD("svc 0x1")

#define SCB_CPACR_CPx_MASK(CpNum)             (0x3U << SCB_CPACR_CPx_SHIFT(CpNum))
#define SCB_CPACR_CPx_SHIFT(CpNum)            ((uint32)(2U*((uint32)CpNum)))
#define SCB_CPACR_CPx(CpNum, x)               (((uint32)(((uint32)(x))<<SCB_CPACR_CPx_SHIFT((CpNum))))&SCB_CPACR_CPx_MASK((CpNum)))

#define CODE_CACHE             0u
#define CACHE_OK               0u
#define CACHE_INVALID_PARAM    1u

/***********************************************************************************************************************
 *                                                      EXTERN
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL CONSTANTS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL VARIABLES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 GLOBAL VARIABLES
 **********************************************************************************************************************/
#define START_VAR_CLEARED_32
#include "MemMap.h"
uint32 RESET_CATCH_CORE=0x00U;
#define STOP_VAR_CLEARED_32
#include "MemMap.h"
/***********************************************************************************************************************
 *                                             LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define START_CODE
#include "MemMap.h"

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
LOCAL_INLINE void Direct_GoToUser(void);
#endif

#ifdef I_CACHE_ENABLE  
static uint8 sys_m4_cache_init(uint8 cache);
#endif
/***********************************************************************************************************************
 *                                                  LOCAL FUNCTION
 **********************************************************************************************************************/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
LOCAL_INLINE void Direct_GoToUser(void)
{
    ASM_KEYWORD("push {r0}");
    ASM_KEYWORD("ldr r0, =0x1");
    ASM_KEYWORD("msr CONTROL, r0");
    ASM_KEYWORD("pop {r0}");
}
#endif

/***********************************************************************************************************************
 *                                                  GLOBAL FUNCTION
 **********************************************************************************************************************/
void *memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++)
    {
        ((char*)dest)[i] = ((char*)src)[i];
    }
}


/**
* @brief    startup_go_to_user_mode
* @details  Function called from startup.s to switch to user mode if MCAL_ENABLE_USER_MODE_SUPPORT is defined
*/

void startup_go_to_user_mode(void)
{
    #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        ASM_KEYWORD("svc 0x1");
    #endif
}

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT

uint32 Sys_GoToSupervisor(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;
    uint32 u32SwitchToSupervisor;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    /* if core is already in supervisor mode for Thread mode, or running form Handler mode, there is no need to make the switch */
    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        u32SwitchToSupervisor = 0U;
    }
    else
    {
        u32SwitchToSupervisor = 1U;
        SVC_GoToSupervisor();
    }

    return u32SwitchToSupervisor;
}

#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
/**
* @brief Sys_GoToUser_Return
* @details function used to switch back to user mode for Thread mode, return a uint32 value passed as parameter
*/
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue)
{
    if (1UL == u32SwitchToSupervisor)
    {
        Direct_GoToUser();
    }

    return u32returnValue;
}

uint32 Sys_GoToUser(void)
{
    Direct_GoToUser();
    return 0UL;
}

void Sys_SuspendInterrupts(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        Suspend_Interrupts();
    }
    else
    {
        ASM_KEYWORD(" svc 0x3");
    }
}

void Sys_ResumeInterrupts(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        Resume_Interrupts();
    }
    else
    {
        ASM_KEYWORD(" svc 0x2");
    }
}
#endif


#if !defined(USING_OS_AUTOSAROS)
uint32 System_GetCoreId(void)
{
    volatile uint32 coreID_u32 = 0UL;
    volatile uint32 *pAddr_CPUID_ptr = (volatile uint32 *)0x4001FF00;
    coreID_u32 = *pAddr_CPUID_ptr;

    return coreID_u32;
}
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
void SVCHandler_main(uint32 * svc_args)
{
    uint32 svc_number;    /* Stack contains:    * r0, r1, r2, r3, r12, r14, the return address and xPSR   */
                          /* First argument (r0) is svc_args[0]  */
    /* svc_args[6] =  SP + 0x18  PC(r15) */
    /* ((char *)svc_args[6])[-2]; = first two bytes, lsb, of the instruction which caused the SVC */
    /* this will no work if optimization compiler options are changed*/
    svc_number = ((uint8 *)svc_args[6])[-2];
    switch(svc_number)
    {
        case 1:
            /* Handle SVC 01*/
            ASM_KEYWORD("mov   r0, #0x1");   /* Set User mode for Thread mode */
            ASM_KEYWORD("msr   CONTROL, r0");
            break;
        case 0:
            /* Handle SVC 00*/
            ASM_KEYWORD("mov   r0, #0x0");   /* Set Supervisor mode for Thread mode */
            ASM_KEYWORD("msr   CONTROL, r0");
            break;
        case 2:
            /* Handle SVC 02*/
            Resume_Interrupts();
            break;
        case 3:
            /* Handle SVC 03*/
            Suspend_Interrupts();

            break;
        default:
            /* Unknown SVC*/
            break;
    }
}

void SVC_Handler(void) __attribute__((naked, weak));
void SVC_Handler(void)
{
    ASM_KEYWORD("tst lr, #4\n"\
                "ite eq\n" \
                "mrseq   r0, MSP\n" \
                "mrsne   r0, PSP\n");
    /* stack pointer is passed to SVCHandler_main, it will be used to extract the parameter given to svc call*/
    ASM_KEYWORD("b       SVCHandler_main");
}

void Suspend_Interrupts(void)
{
    ASM_KEYWORD("push {r0}");
    ASM_KEYWORD("mov   r0, #0x10");
    ASM_KEYWORD("msr BASEPRI, r0");
    ASM_KEYWORD("pop {r0}");
}

void Resume_Interrupts(void)
{
    ASM_KEYWORD("push {r0}");
    ASM_KEYWORD("mov   r0, #0x0");
    ASM_KEYWORD("msr BASEPRI, r0");
    ASM_KEYWORD("pop {r0}");
}
#endif

#ifdef _IAR_HULA_ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 
void SystemInit(void)
{
    #ifdef ENABLE_FPU
        /* Enable CP10 and CP11 coprocessors */
        SCB->CPACR |= (SCB_CPACR_CPx(10U, 3U) | SCB_CPACR_CPx(11U, 3U)); 

        /* Sync instructions */
        MCAL_DATA_SYNC_BARRIER();
        MCAL_INSTRUCTION_SYNC_BARRIER();
    #endif /* ENABLE_FPU */

    #ifdef ENABLE_THREAD_MODE_ENTRY_CONFIGURATION
        SCB->CCR    |=  1u;       /* processor can enter Thread mode from any level under the control of an EXC_RETURN value, PendSV priority set to 0*/
    #endif

    /* Sync instructions */
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

    #ifdef I_CACHE_ENABLE  
        /* ENABLE CACHE */
        (void)sys_m4_cache_init(CODE_CACHE);    
    #endif

}

#ifdef _IAR_HULA_ 
    #pragma default_function_attributes = 
#endif

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/