/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: System_Ipc.h
 *
 * Description: Implementation of SYSTEM_IPC High Level layer
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

#ifndef SYSTEM_IPC_H
#define SYSTEM_IPC_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES AND 
 **********************************************************************************************************************/
#include "Interrupt_System_Ip.h"
#include "System_Types.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define SYSTEM_IPC_VENDOR_ID                    15
#define SYSTEM_IPC_MODULE_ID                    54
#define SYSTEM_IPC_AR_RELEASE_MAJOR_VERSION     4
#define SYSTEM_IPC_AR_RELEASE_MINOR_VERSION     4
#define SYSTEM_IPC_AR_RELEASE_REVISION_VERSION  0
#define SYSTEM_IPC_SW_MAJOR_VERSION             1
#define SYSTEM_IPC_SW_MINOR_VERSION             0
#define SYSTEM_IPC_SW_PATCH_VERSION             0
/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                      EXTERN
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

/***********************************************************************************************************************
 *                                                  GLOBAL FUNCTION
 **********************************************************************************************************************/
#define START_CODE
#include "MemMap.h"

Std_ReturnType System_Ipc_Init(const System_ConfigType *p_SystemConfig_ptr);
Std_ReturnType System_Ipc_InterruptUpdateConfigSet(const System_InterruptConfigSetType* p_InterruptConfig_ptr, uint8 p_Interrupt_CfgSet_Index_u8);
Std_ReturnType System_Ipc_SetIrqPriority(IRQn_Type p_Irq_Number_en, Interrupt_System_Ip_IntPriorityType p_Irq_Priority_en);
Std_ReturnType System_Ipc_EnableIrq(Interrupt_System_Ip_InterruptConfigSetElementMemberType *p_InterruptConfig_ptr); 
Std_ReturnType System_Ipc_DisableIrq(IRQn_Type p_IrqNumber_en);
Std_ReturnType System_Ipc_ClearPendingIrq(IRQn_Type p_IrqNumber_en);
Std_ReturnType System_Ipc_SetPendingIrq(IRQn_Type p_IrqNumber_en);
boolean System_Ipc_GetPendingIrq(IRQn_Type p_IrqNumber_en);

void SystemTimer_Ipc_Init(System_TimerConfigType *p_SystemTimerConfig_ptr);
uint32 System_Ipc_GetCounter(void);
uint32 System_Ipc_GetElapsed(uint32 * const p_CurrentRef_ptr);
void System_Ipc_SetFrequency(uint32 p_Freq_u32);
uint32 System_Ipc_UsToTicks(uint32 p_Microsu_32);
uint32 System_Ipc_msToTicks(uint32 p_Milli_u32);


#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_IPC_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
