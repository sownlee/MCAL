/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: System.c
 *
 * Description: Implementation of System High Level layer
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
#include "System.h"
#if (STD_ON == SYSTEM_DEV_ERROR_DETECT)
  #include "Det.h"
#endif /* (STD_ON == SYSTEM_DEV_ERROR_DETECT) */
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
/* Common Published Information */
#define SYSTEM_VENDOR_ID_C                      15
#define SYSTEM_MODULE_ID_C                      255

/* AUTOSAR release version information */
#define SYSTEM_AR_RELEASE_MAJOR_VERSION_C       4
#define SYSTEM_AR_RELEASE_MINOR_VERSION_C       4
#define SYSTEM_AR_RELEASE_REVISION_VERSION_C    0

/* File version information */
#define SYSTEM_SW_MAJOR_VERSION_C               0
#define SYSTEM_SW_MINOR_VERSION_C               9
#define SYSTEM_SW_PATCH_VERSION_C               0
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
/**
* @brief   Driver initialization status.
*/
typedef enum 
{
  SYSTEM_UNINIT = 0U,
  SYSTEM_INITIALIZED 
} System_DriverStatusType;
/***********************************************************************************************************************
 *                                                  LOCAL CONSTANTS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL VARIABLES
 **********************************************************************************************************************/
#define START_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
static const System_ConfigType* s_SystemConfig_ptr;
static const System_TimerConfigType* s_System_TimerConfig_ptr;
#define STOP_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define START_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
static System_DriverStatusType s_SystemDrvStatus_en = SYSTEM_UNINIT;
#define STOP_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/***********************************************************************************************************************
 *                                                 GLOBAL VARIABLES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                             LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define START_CODE
#include "MemMap.h"

static inline uint32 System_Ipc_GetDummyCounter(void);
static inline uint32 System_Ipc_GetDummyElapsed(const uint32 * const p_CurrentRef_ptr);
static inline void System_Ipc_SetDummyFrequency(uint32 p_Freq_u32);
static inline uint32 System_Ipc_DummyUsToTick(uint32 p_Micros_u32);
static inline uint32 System_Ipc_DummymsToTick(uint32 p_Milli_u32);

#define STOP_CODE
#include "MemMap.h"
/***********************************************************************************************************************
 *                                                  LOCAL FUNCTION
 **********************************************************************************************************************/
#define START_CODE
#include "MemMap.h"
static inline uint32 System_Ipc_GetDummyCounter(void)
{
    return 0u;
}
static inline uint32 System_Ipc_GetDummyElapsed(const uint32 * const p_CurrentRef_ptr)
{
    (void)p_CurrentRef_ptr;
    return 1u;
}
static inline void System_Ipc_SetDummyFrequency(uint32 p_Freq_u32)
{
    (void)p_Freq_u32;
}
static inline uint32 System_Ipc_DummyUsToTick(uint32 p_Micros_u32)
{
    return p_Micros_u32;
}
static inline uint32 System_Ipc_DummymsToTick(uint32 p_Milli_u32)
{
    return p_Milli_u32;
}
#define STOP_CODE
#include "MemMap.h"
/***********************************************************************************************************************
 *                                                  GLOBAL FUNCTION
 **********************************************************************************************************************/
#define START_CODE
#include "MemMap.h"

Std_ReturnType System_Init(const System_ConfigType *p_SystemConfig_ptr)
 {
    Std_ReturnType Return_Value = (Std_ReturnType)E_NOT_OK;

    if (p_SystemConfig_ptr == NULL_PTR) 
    {
        #if(STD_ON == SYSTEM_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)SYSTEM_MODULE_ID, (uint8)0U, (uint8)SYSTEM_INIT_ID, (uint8)SYSTEM_E_INVALID_POINTER);
        #endif /* (STD_ON == SYSTEM_DEV_ERROR_DETECT) */
        Return_Value = (Std_ReturnType)E_NOT_OK;
    } 
    else 
    {
        s_SystemConfig_ptr = p_SystemConfig_ptr;
        s_SystemDrvStatus_en = SYSTEM_INITIALIZED;
        (void)System_Ipc_Init(s_SystemConfig_ptr);
        Return_Value = (Std_ReturnType)E_OK;
    }

    return Return_Value;
}

Std_ReturnType System_SetIrqPriority(IRQn_Type p_Irq_Number_en, Interrupt_System_Ip_IntPriorityType p_Irq_Priority_en) 
{

    Std_ReturnType  Return_Value = (Std_ReturnType)E_NOT_OK;

    if (p_Irq_Priority_en >= INTERRUPT_SYSTEM_IP_PRIORITY_NONE)
    {
        #if(STD_ON == SYSTEM_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)SYSTEM_MODULE_ID, (uint8)0U, (uint8)SYSTEM_INIT_ID, (uint8)SYSTEM_E_INVALID_PARAMETER);
        #endif /* (STD_ON == SYSTEM_DEV_ERROR_DETECT) */
        Return_Value = (Std_ReturnType)E_NOT_OK;
    } 
    else 
    {
        /* Setting IRQ priority for interrupts */
        Return_Value = System_Ipc_SetIrqPriority(p_Irq_Number_en, p_Irq_Priority_en);
    }

    return Return_Value;
}

Std_ReturnType System_EnableIrq (Interrupt_System_Ip_InterruptConfigSetElementMemberType *p_InterruptConfig_ptr)
{
    Std_ReturnType  Return_Value = (Std_ReturnType)E_NOT_OK;

    if (p_InterruptConfig_ptr == NULL_PTR)
    {
        #if(STD_ON == SYSTEM_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)SYSTEM_MODULE_ID, (uint8)0U, (uint8)SYSTEM_INIT_ID, (uint8)SYSTEM_E_INVALID_POINTER);
        #endif /* (STD_ON == SYSTEM_DEV_ERROR_DETECT) */
        Return_Value = (Std_ReturnType)E_NOT_OK;
    } 
    else 
    {
        /* Enable irq for interrupts */
        Return_Value = System_Ipc_EnableIrq(p_InterruptConfig_ptr);
    }

    return Return_Value;
}

Std_ReturnType System_DisableIrq(IRQn_Type p_IrqNumber_en)
{
    Std_ReturnType  Return_Value = (Std_ReturnType)E_NOT_OK;

    if ((sint32)p_IrqNumber_en < 0)
    {
        #if(STD_ON == SYSTEM_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)SYSTEM_MODULE_ID, (uint8)0U, (uint8)SYSTEM_INIT_ID, (uint8)SYSTEM_E_INVALID_PARAMETER);
        #endif /* (STD_ON == SYSTEM_DEV_ERROR_DETECT) */
        Return_Value = (Std_ReturnType)E_NOT_OK;
    } 
    else 
    {
        /* Disable irq for interrupts */
        Return_Value = System_Ipc_DisableIrq(p_IrqNumber_en);
    }

    return Return_Value;
}

Std_ReturnType System_ClearPendingIrq(IRQn_Type p_IrqNumber_en)
{
    Std_ReturnType  Return_Value = (Std_ReturnType)E_NOT_OK;

    if ((sint32)p_IrqNumber_en < 0)
    {
        #if(STD_ON == SYSTEM_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)SYSTEM_MODULE_ID, (uint8)0U, (uint8)SYSTEM_INIT_ID,(uint8)SYSTEM_E_INVALID_PARAMETER);
        #endif /* (STD_ON == SYSTEM_DEV_ERROR_DETECT) */
        Return_Value = (Std_ReturnType)E_NOT_OK;
    } 
    else 
    {
        /* Clear pending irq for interrupts */
        Return_Value = System_Ipc_ClearPendingIrq(p_IrqNumber_en);
    }

    return Return_Value;
}

Std_ReturnType System_SetPendingIrq(IRQn_Type p_IrqNumber_en)
{
    Std_ReturnType  Return_Value = (Std_ReturnType)E_NOT_OK;

    if ((sint32)p_IrqNumber_en < 0)
    {
        #if(STD_ON == SYSTEM_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)SYSTEM_MODULE_ID, (uint8)0U, (uint8)SYSTEM_INIT_ID, (uint8)SYSTEM_E_INVALID_PARAMETER);
        #endif /* (STD_ON == SYSTEM_DEV_ERROR_DETECT) */
        Return_Value = (Std_ReturnType)E_NOT_OK;
    } 
    else 
    {
        /* Setting pending IRQ for interrupts */
        Return_Value = System_Ipc_SetPendingIrq(p_IrqNumber_en);
    }

    return Return_Value;
}

boolean System_GetPendingIrq(IRQn_Type p_IrqNumber_en)
{
    boolean Return_Value = FALSE;

    if ((sint32)p_IrqNumber_en < 0)
    {
        #if(STD_ON == SYSTEM_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)SYSTEM_MODULE_ID, (uint8)0U, (uint8)SYSTEM_INIT_ID, (uint8)SYSTEM_E_INVALID_PARAMETER);
        #endif /* (STD_ON == SYSTEM_DEV_ERROR_DETECT) */
    } 
    else 
    {
        /* Getting pending IRQ status */
        Return_Value = System_Ipc_GetPendingIrq(p_IrqNumber_en);
    }

    return Return_Value;
}

Std_ReturnType System_InterruptUpdateConfigSet(const System_InterruptConfigSetType* p_InterruptConfig_ptr, uint8 p_Interrupt_CfgSet_Index_u8)
{
    Std_ReturnType  Return_Value = (Std_ReturnType)E_NOT_OK;

    if (p_InterruptConfig_ptr == NULL_PTR)
    {
        #if(STD_ON == SYSTEM_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)SYSTEM_MODULE_ID,(uint8)0U,(uint8)SYSTEM_INIT_ID,(uint8)SYSTEM_E_INVALID_POINTER);
        #endif /* (STD_ON == SYSTEM_DEV_ERROR_DETECT) */
        Return_Value = (Std_ReturnType)E_NOT_OK;
    } 
    else 
    {
        /* Updating configuraitons for Interrupt */
        Return_Value = System_Ipc_InterruptUpdateConfigSet(p_InterruptConfig_ptr, p_Interrupt_CfgSet_Index_u8);
    }

    return Return_Value;
}

#if (STD_ON == SYSTEM_VERSION_INFO_API)
void  System_GetVersionInfo(Std_VersionInfoType* p_SystemVersionInfo_ptr)
{
    if (NULL_PTR == p_SystemVersionInfo_ptr) 
    {
        #if (STD_ON == SYSTEM_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)SYSTEM_MODULE_ID,(uint8)0U,(uint8)SYSTEM_VERSIONINFO_ID,(uint8)SYSTEM_E_INVALID_POINTER);
        #endif /* STD_ON == SYSTEM_DEV_ERROR_DETECT */
    } 
    else 
    {
        p_SystemVersionInfo_ptr->vendorID = (uint16) SYSTEM_VENDOR_ID;
        p_SystemVersionInfo_ptr->moduleID = (uint8) SYSTEM_MODULE_ID;
        p_SystemVersionInfo_ptr->sw_major_version = (uint8) SYSTEM_SW_MAJOR_VERSION;
        p_SystemVersionInfo_ptr->sw_minor_version = (uint8) SYSTEM_SW_MINOR_VERSION;
        p_SystemVersionInfo_ptr->sw_patch_version = (uint8) SYSTEM_SW_PATCH_VERSION;
    }
}
#endif /* STD_ON == SYSTEM_VERSION_INFO_API */

void SystemTimer_Init(System_TimerConfigType *p_SystemTimerConfig_ptr)
{
    SystemTimer_Ipc_Init(p_SystemTimerConfig_ptr);
}

uint32 System_GetCounter(System_CounterType p_SelectedCounter_en)
{
    uint32 Value = 0u;
    if (p_SelectedCounter_en == SYSTEM_COUNTER_DUMMY )
    {
        Value = System_Ipc_GetDummyCounter();
    }
    else if (p_SelectedCounter_en == SYSTEM_COUNTER_SYSTEM )
    {
        if(s_System_TimerConfig_ptr->SYSTEM_USE_SYSTEM_TIMER==TRUE)
        {
            Value = System_Ipc_GetCounter();
        }
    }

    return Value;
}

uint32 System_GetElapsed(uint32 * const p_CurrentRef_ptr, System_CounterType p_SelectedCounter_en)
{
    uint32 Value = 0u;
    if (p_SelectedCounter_en == SYSTEM_COUNTER_DUMMY )
    {
        Value = System_Ipc_GetDummyElapsed(p_CurrentRef_ptr);
    }
    else if (p_SelectedCounter_en == SYSTEM_COUNTER_SYSTEM )
    {
        if(s_System_TimerConfig_ptr->SYSTEM_USE_SYSTEM_TIMER == TRUE)
        {
            Value = System_Ipc_GetElapsed(p_CurrentRef_ptr);
        }
    }
    return Value;
}

void System_SetFrequency(uint32 p_Freq_u32, System_CounterType p_SelectedCounter_en)
{
    if (p_SelectedCounter_en == SYSTEM_COUNTER_DUMMY )
    {
            System_Ipc_SetDummyFrequency(p_Freq_u32);
    }
    else if (p_SelectedCounter_en == SYSTEM_COUNTER_SYSTEM )
    {
        if(s_System_TimerConfig_ptr->SYSTEM_USE_SYSTEM_TIMER==TRUE)
        {
            System_Ipc_SetFrequency(p_Freq_u32);
        }
    }
}

uint32 System_UsToTicks(uint32 p_Micros_u32, System_CounterType p_SelectedCounter_en)
{
    uint32 Value = 0u;

    if (p_SelectedCounter_en == SYSTEM_COUNTER_DUMMY )
    {
        Value = System_Ipc_DummyUsToTick(p_Micros_u32);
    }
    else if (p_SelectedCounter_en == SYSTEM_COUNTER_SYSTEM )
    {
        if(s_System_TimerConfig_ptr->SYSTEM_USE_SYSTEM_TIMER==TRUE)
        {
            Value = System_Ipc_UsToTicks(p_Micros_u32);
        }
    }

    return Value;
}

uint32 System_msToTicks(uint32 p_Milli_u32, System_CounterType p_SelectedCounter_en)
{
    uint32 Value = 0u;
    if (p_SelectedCounter_en == SYSTEM_COUNTER_DUMMY )
    {
        Value = System_Ipc_DummymsToTick(p_Milli_u32);
    }
    else if (p_SelectedCounter_en == SYSTEM_COUNTER_SYSTEM )
    {
        if(s_System_TimerConfig_ptr->SYSTEM_USE_SYSTEM_TIMER==TRUE)
        {
            Value = System_Ipc_msToTicks(p_Milli_u32);
        }
    }
    return Value;
}

#define STOP_CODE
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/