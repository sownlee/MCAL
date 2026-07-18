/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Interrupt_Ip.c
 *
 * Description: Implementation of Interrupt_Ip High Level layer
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
#include "Interrupt_System_Ip.h"
#include "OsIf_Internal.h"
#include "Interrupt_System_Ip_Cfg.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
/* Common Published Information */
#define INTERRUPT_SYSTEM_IP_VENDOR_ID_C                      15
#define INTERRUPT_SYSTEM_IP_MODULE_ID_C                      255

/* AUTOSAR release version information */
#define INTERRUPT_SYSTEM_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define INTERRUPT_SYSTEM_IP_AR_RELEASE_MINOR_VERSION_C       4
#define INTERRUPT_SYSTEM_IP_AR_RELEASE_REVISION_VERSION_C    0

/* File version information */
#define INTERRUPT_SYSTEM_IP_SW_MAJOR_VERSION_C               0
#define INTERRUPT_SYSTEM_IP_SW_MINOR_VERSION_C               9
#define INTERRUPT_SYSTEM_IP_SW_PATCH_VERSION_C               0
/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/

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

/***********************************************************************************************************************
 *                                             LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL FUNCTION
 **********************************************************************************************************************/
#define START_CODE
#include "MemMap.h"

static void Interrupt_System_Ip_EnableIRQPrivilege(Interrupt_System_Ip_InterruptConfigSetElementMemberType *p_InterruptConfig_ptr)
{
    IRQn_Type IrqNumber_en = NonMaskableInt_IRQn;
    Interrupt_System_Ip_IntPriorityType IrqPriority_en = INTERRUPT_SYSTEM_IP_PRIORITY_0;
    func_ptr_t *VectorRam_ptr = (func_ptr_t *)SCB->VTOR;

    IrqNumber_en = p_InterruptConfig_ptr->IrqNum;
    IrqPriority_en = (Interrupt_System_Ip_IntPriorityType )(p_InterruptConfig_ptr->IntPriority);
    /* The IRQ handlers are written to vector table */
    VectorRam_ptr[(sint32)IrqNumber_en + 16] = p_InterruptConfig_ptr->IrqHandler;

    /* Clear pending Irq before enable IRQ */
    if((sint32)(IrqNumber_en) >= 0)
    {
        Interrupt_Hw_NvicClearPendingIrq((uint32)IrqNumber_en);
    }

    /* Set IRQ priority before enable IRQ */ 
    if ((uint32)IrqPriority_en < INTERRUPT_SYSTEM_IP_PRIORITY_NONE)
    {
        Interrupt_Hw_NvicSetIrqPriority((sint32)IrqNumber_en, (uint32)IrqPriority_en);
    }

    /* Enable IRQ */ 
    if((sint32)(IrqNumber_en) >= 0)
    {
        Interrupt_Hw_NvicEnableIrq((uint32)IrqNumber_en);
    }
}

static void Interrupt_System_Ip_DisableIRQPrivilege(IRQn_Type p_IrqNumber_en)
{
    Interrupt_Hw_NvicDisableIrq((uint32)p_IrqNumber_en);
}

#define STOP_CODE
#include "MemMap.h"
/***********************************************************************************************************************
 *                                                  GLOBAL FUNCTION
 **********************************************************************************************************************/
#define START_CODE
#include "MemMap.h"

void Interrupt_System_Ip_Init(const Interrupt_System_IP_InterruptConfigSetElementType *p_InterruptConfig_ptr)
{
    INTC_SYSTEM_IP_DEV_ASSERT(p_InterruptConfig_ptr != NULL_PTR);
    Interrupt_System_Ip_InterruptUpdateConfig(p_InterruptConfig_ptr);
}

void Interrupt_System_Ip_InterruptUpdateConfig(const Interrupt_System_IP_InterruptConfigSetElementType *p_InterruptConfig_ptr)
{
    uint8 l_Index_u8 = 0U;

    INTC_SYSTEM_IP_DEV_ASSERT(p_InterruptConfig_ptr != NULL_PTR);

    if (p_InterruptConfig_ptr->InterruptConfigSetElementMem_ptr != NULL_PTR)
    {
        /* Every IRQ can be set */
        for(l_Index_u8 = 0U; l_Index_u8 < p_InterruptConfig_ptr->NumberOfConfigIrq_u8; l_Index_u8++)
        {
            Interrupt_System_Ip_EnableIrq(&p_InterruptConfig_ptr->InterruptConfigSetElementMem_ptr[l_Index_u8]); 
        }
    }
}

void Interrupt_System_Ip_EnableIrq(Interrupt_System_Ip_InterruptConfigSetElementMemberType *p_InterruptConfig_ptr)
{
    INTC_SYSTEM_IP_DEV_ASSERT(p_InterruptConfig_ptr != NULL_PTR);

    #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        (void)OsIf_Trusted_Call1param(Interrupt_System_Ip_EnableIRQPrivilege, p_InterruptConfig_ptr);
    #else
        Interrupt_System_Ip_EnableIRQPrivilege(p_InterruptConfig_ptr);
    #endif
}

void Interrupt_System_Ip_DisableIrq(IRQn_Type p_IrqNumber_en)
{
    INTC_SYSTEM_IP_DEV_ASSERT((sint32)p_IrqNumber_en >= 0);

    #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        (void)OsIf_Trusted_Call1param(Interrupt_System_Ip_DisableIRQPrivilege, p_IrqNumber_en);
    #else
        Interrupt_System_Ip_DisableIRQPrivilege(p_IrqNumber_en);
    #endif
}

void Interrupt_System_Ip_SetIrqPriority(IRQn_Type p_IrqNumber_en,Interrupt_System_Ip_IntPriorityType p_IrqPriority_en)
{
    INTC_SYSTEM_IP_DEV_ASSERT(p_IrqPriority_en < INTERRUPT_SYSTEM_IP_PRIORITY_NONE);   

    #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Interrupt_Hw_NvicSetIrqPriority, (sint32)p_IrqNumber_en, (uint32)p_IrqPriority_en);
    #else
        Interrupt_Hw_NvicSetIrqPriority((sint32)p_IrqNumber_en, (uint32)p_IrqPriority_en);
    #endif
}

void Interrupt_System_Ip_ClearPendingIrq(IRQn_Type p_IrqNumber_en)
{
    INTC_SYSTEM_IP_DEV_ASSERT((sint32)p_IrqNumber_en >= 0);

    #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Interrupt_Hw_NvicClearPendingIrq, (uint32)p_IrqNumber_en);
    #else
        Interrupt_Hw_NvicClearPendingIrq((uint32)p_IrqNumber_en);
    #endif
}

void Interrupt_System_Ip_SetPendingIrq(IRQn_Type p_IrqNumber_en)
{
    INTC_SYSTEM_IP_DEV_ASSERT((sint32)p_IrqNumber_en >= 0);

    #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Interrupt_Hw_NvicSetPendingIrq, (uint32)p_IrqNumber_en);
    #else
        /* Setting pending IRQ for interrupts */
        Interrupt_Hw_NvicSetPendingIrq((uint32)p_IrqNumber_en);
    #endif
}

boolean Interrupt_System_Ip_GetPendingIrq(IRQn_Type p_IrqNumber_en)
{
    boolean l_Status_b = FALSE;

    if ((sint32)p_IrqNumber_en >= 0)
    {
        #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
            l_Status_b = OsIf_Trusted_Call_Return1param(Interrupt_Hw_NvicGetPendingIrq, (uint32)p_IrqNumber_en);
        #else
            /* Getting pending IRQ status */
            l_Status_b = Interrupt_Hw_NvicGetPendingIrq((uint32)p_IrqNumber_en);
        #endif
    }

    return l_Status_b;
}

#define STOP_CODE
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/