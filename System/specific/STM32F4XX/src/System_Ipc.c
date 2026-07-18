/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: System_Ipc.c
 *
 * Description: Implementation of System_Ipc High Level layer
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
#include "System_Ipc.h"
#include "Systick_System_Ip.h"
#include "OsIf_Internal.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

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
static const System_TimerConfigType* s_c_g_System_TimerConfig_ptr;
/***********************************************************************************************************************
 *                                             LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL FUNCTION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  GLOBAL FUNCTION
 **********************************************************************************************************************/
#define START_CODE
#include "MemMap.h"

Std_ReturnType System_Ipc_Init(const System_ConfigType *p_SystemConfig_ptr) 
{
    Std_ReturnType l_Return_Value_u8 = (Std_ReturnType)E_OK;
    uint8 l_Number_Of_Config_u8 = 0U;
    uint8 l_Config_Index_u8 = 0U;
    const System_InterruptConfigSetElementCoreType *l_Interrupt_Config_Set_Element_ptr = NULL_PTR;

    if ((p_SystemConfig_ptr->SystemInterruptConfigSet_ptr != NULL_PTR) && ((p_SystemConfig_ptr->SystemInterruptConfigSet_ptr->NumberOfInteruptConfigSet_u8) != 0U))
    {
        /* Default use configset 0 */
        l_Interrupt_Config_Set_Element_ptr = p_SystemConfig_ptr->SystemInterruptConfigSet_ptr->InterruptConfigSetElement_ptr[0U].InterruptConfigSetElementCore_ptr;
        l_Number_Of_Config_u8 = p_SystemConfig_ptr->SystemInterruptConfigSet_ptr->InterruptConfigSetElement_ptr[0U].ConfigNumberOfConfigset_u8;

        if (l_Interrupt_Config_Set_Element_ptr != NULL_PTR)
        {
            for (l_Config_Index_u8 = 0U; l_Config_Index_u8 < l_Number_Of_Config_u8; l_Config_Index_u8++)
            {
                /* Initialize configurations for interrupt */
                Interrupt_System_Ip_Init(l_Interrupt_Config_Set_Element_ptr[l_Config_Index_u8].InterruptConfigSetElementCoreMem_ptr);
            }
        }
    }
    else
    {
        l_Return_Value_u8 = (Std_ReturnType)E_NOT_OK;
    }
    
    return l_Return_Value_u8;
}

Std_ReturnType System_Ipc_InterruptUpdateConfigSet(const System_InterruptConfigSetType* p_InterruptConfig_ptr, uint8 p_Interrupt_CfgSet_Index_u8)
{
    Std_ReturnType l_Return_Value_u8 = (Std_ReturnType)E_OK;
    uint8 l_ConfigNumber_Of_ConfigSet_u8 = 0U;
    uint8 l_Index_u8 = 0U;

    const System_InterruptConfigSetElementCoreType *Interrupt_ConfigSet_Element_HLD_ptr = NULL_PTR;
    const Interrupt_System_IP_InterruptConfigSetElementType *Interrupt_ConfigSet_Element_IP_ptr = NULL_PTR;
    
    /* The update index of configurations set should be smaller than the number of Interrupt configuration set  */
    if ((p_InterruptConfig_ptr->NumberOfInteruptConfigSet_u8 != 0U) && (p_Interrupt_CfgSet_Index_u8 < (p_InterruptConfig_ptr->NumberOfInteruptConfigSet_u8)))
    {
        Interrupt_ConfigSet_Element_HLD_ptr = p_InterruptConfig_ptr->InterruptConfigSetElement_ptr[0U].InterruptConfigSetElementCore_ptr;
        l_ConfigNumber_Of_ConfigSet_u8 = p_InterruptConfig_ptr->InterruptConfigSetElement_ptr[p_Interrupt_CfgSet_Index_u8].ConfigNumberOfConfigset_u8;

        for (l_Index_u8 = 0U; l_Index_u8 < l_ConfigNumber_Of_ConfigSet_u8; l_Index_u8++)
        {
            Interrupt_ConfigSet_Element_IP_ptr = Interrupt_ConfigSet_Element_HLD_ptr[l_Index_u8].InterruptConfigSetElementCoreMem_ptr;
            /* Updating configuraitons for Interrupt */
            Interrupt_System_Ip_InterruptUpdateConfig(Interrupt_ConfigSet_Element_IP_ptr);
        }
    }
    else
    {
        l_Return_Value_u8 = (Std_ReturnType)E_NOT_OK;
    }
    
    return l_Return_Value_u8;
}

Std_ReturnType System_Ipc_SetIrqPriority(IRQn_Type p_Irq_Number_en, Interrupt_System_Ip_IntPriorityType p_Irq_Priority_en)
{
    Std_ReturnType l_Return_Value_u8 = (Std_ReturnType)E_OK;
    
    /* Setting IRQ priority for interrupts */
    Interrupt_System_Ip_SetIrqPriority(p_Irq_Number_en, p_Irq_Priority_en);
    
    return l_Return_Value_u8;
}

Std_ReturnType System_Ipc_EnableIrq(Interrupt_System_Ip_InterruptConfigSetElementMemberType *p_InterruptConfig_ptr)
{
    Std_ReturnType l_Return_Value_u8 = (Std_ReturnType)E_OK;
    
    /* Enable irq for interrupts */
    Interrupt_System_Ip_EnableIrq(p_InterruptConfig_ptr);
    
    return l_Return_Value_u8;
}

Std_ReturnType System_Ipc_DisableIrq(IRQn_Type p_IrqNumber_en)
{
    Std_ReturnType l_Return_Value_u8 = (Std_ReturnType)E_OK;
    
    /* Disable irq for interrupts */
    Interrupt_System_Ip_DisableIrq(p_IrqNumber_en);
    
    return l_Return_Value_u8;
}

Std_ReturnType System_Ipc_ClearPendingIrq(IRQn_Type p_IrqNumber_en)
{
    Std_ReturnType l_Return_Value_u8 = (Std_ReturnType)E_OK;
    
    /* Clear pending irq for interrupts */
    Interrupt_System_Ip_ClearPendingIrq(p_IrqNumber_en);
    
    return l_Return_Value_u8;
}

Std_ReturnType System_Ipc_SetPendingIrq(IRQn_Type p_IrqNumber_en)
{
    Std_ReturnType l_Return_Value_u8 = (Std_ReturnType)E_OK;
    
    /* Setting pending IRQ for interrupts */
    Interrupt_System_Ip_SetPendingIrq(p_IrqNumber_en);
    
    return l_Return_Value_u8;
}

boolean System_Ipc_GetPendingIrq(IRQn_Type p_IrqNumber_en)
{
    boolean l_Status_u8 = FALSE;
    
    /* Getting pending IRQ status */
    l_Status_u8 = Interrupt_System_Ip_GetPendingIrq(p_IrqNumber_en);
    
    return l_Status_u8;
}

void SystemTimer_Ipc_Init(System_TimerConfigType *p_SystemTimerConfig_ptr)
{
    s_c_g_System_TimerConfig_ptr = p_SystemTimerConfig_ptr;

    SysTick_Ip_Init(p_SystemTimerConfig_ptr->SystemTimerFrequency_u32);
}

uint32 System_Ipc_GetCounter(void)
{
    uint32 Counter_32 = 0u;
    return Counter_32 = SysTick_Ip_GetCounter();
}

uint32 System_Ipc_GetElapsed(uint32 *const p_CurrentRef_ptr)
{
    uint32 Elapsed_32 = 0u;
    return Elapsed_32 = SysTick_Ip_GetElapsed(p_CurrentRef_ptr);
}

void System_Ipc_SetFrequency(uint32 p_Freq_u32)
{
    if (s_c_g_System_TimerConfig_ptr->SYSTEM_USE_SYSTEM_TIMER == TRUE)
    {
        SysTick_Ip_SetFreq(p_Freq_u32);
    }
    else if (s_c_g_System_TimerConfig_ptr->SYSTEM_USE_FREERTOS == TRUE)
    {
        (void)p_Freq_u32;
    }
}

uint32 System_Ipc_UsToTicks(uint32 p_Micros_u32)
{
    uint32 Ticks_u32 = 0u;
    return Ticks_u32 = SysTick_Ip_UsToTick(p_Micros_u32);
}

uint32 System_Ipc_msToTicks(uint32 p_Milli_u32)
{
    uint32 Ticks_u32 = 0u;
    return Ticks_u32 = SysTick_Ip_MsToTick(p_Milli_u32);
}

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/