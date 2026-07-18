#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "Std_Types.h"
#include "STM32F4.h"
/* #include "System_Cfg.h" */


#ifdef MCAL_ENABLE_USER_MODE_SUPPORT  
extern uint32 startup_getControlRegisterValue(void);
extern uint32 startup_getAipsRegisterValue(void);
extern void Suspend_Interrupts(void);
extern void Resume_Interrupts(void);

/* Switch to user mode and return the value passed by u32returnValue */
extern uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue);

/* Switch to supervisor mode */
extern uint32 Sys_GoToSupervisor(void);

/* Switch to user mode */
extern uint32 Sys_GoToUser(void);

extern void Sys_SuspendInterrupts(void);
extern void Sys_ResumeInterrupts(void);

extern void startup_go_to_user_mode(void);
#endif

/* 
 * @brief Get the hardware id of the currently executing core
 * @param: None
 * 
 * @return: coreId
 */
extern uint8 Sys_GetCoreID(void);

/* 
 * @brief Early platform initialization for interrupts, cache and core MPU
 * @param: None
 * 
 * @return: None
 */
extern void SystemInit(void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_H */