/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: System.h
 *
 * Description: Implementation of SYSTEM High Level layer
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

#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES AND 
 **********************************************************************************************************************/
#include "System_Types.h"
#include "System_Ipc.h"
#include "System_Cfg.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define SYSTEM_VENDOR_ID                    15
#define SYSTEM_MODULE_ID                    54
#define SYSTEM_AR_RELEASE_MAJOR_VERSION     4
#define SYSTEM_AR_RELEASE_MINOR_VERSION     4
#define SYSTEM_AR_RELEASE_REVISION_VERSION  0
#define SYSTEM_SW_MAJOR_VERSION             1
#define SYSTEM_SW_MINOR_VERSION             0
#define SYSTEM_SW_PATCH_VERSION             0
/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/
typedef enum System_CounterType_t
{
    SYSTEM_COUNTER_DUMMY, 
    SYSTEM_COUNTER_SYSTEM 
} System_CounterType;
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

/**
 *  @brief          This service performs initialization of the System Driver component.
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            System_ConfigType*    
 *  @param[in]      p_SystemConfig_ptr    System config.
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK               successfully         
 *  @retval         E_NOT_OK           unsuccessfully         
 *
 *  @note           None
 *
 **/
Std_ReturnType System_Init(const System_ConfigType *p_SystemConfig_ptr);

/**
 *  @brief          This service to set priority for IRQ.
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            IRQn_Type  
 *  @param[in]      p_Irq_Number_en      Enum IRQ.
 *  @arg            Interrupt_System_Ip_IntPriorityType  
 *  @param[in]      p_Irq_Priority_en    Priority enum.
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK               Set interrupt request priority successfully         
 *  @retval         E_NOT_OK           Set interrupt request priority unsuccessfully         
 *
 *  @note           None
 *
 **/
Std_ReturnType System_SetIrqPriority(IRQn_Type p_Irq_Number_en, Interrupt_System_Ip_IntPriorityType p_Irq_Priority_en);

/**
 *  @brief          This service to enable interrupt request.
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Interrupt_System_Ip_InterruptConfigSetElementMemberType *
 *  @param[in]      InterruptConfig_ptr      Interrupt Configurations.
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK               Enable IRQ successfully       
 *  @retval         E_NOT_OK           Enable IRQ unsuccessfully      
 *
 *  @note           None
 *
 **/
Std_ReturnType System_EnableIrq(Interrupt_System_Ip_InterruptConfigSetElementMemberType *p_InterruptConfig_ptr);  

/**
 *  @brief          This service to disable interrupt request.
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            IRQn_Type
 *  @param[in]      IrqNumber_en       IRQ Number
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK               Disable IRQ successfully       
 *  @retval         E_NOT_OK           Disable IRQ unsuccessfully      
 *
 *  @note           None
 *
 **/
Std_ReturnType System_DisableIrq(IRQn_Type p_IrqNumber_en);

/**
 *  @brief          This service to clear pending IRQ.
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            IRQn_Type
 *  @param[in]      IrqNumber_en       IRQ Number
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK               Clear pending IRQ successfully       
 *  @retval         E_NOT_OK           Clear pending IRQ unsuccessfully      
 *
 *  @note           None
 *
 **/
Std_ReturnType System_ClearPendingIrq(IRQn_Type p_IrqNumber_en);

/**
 *  @brief          This service to set pending IRQ.
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            IRQn_Type
 *  @param[in]      IrqNumber_en       IRQ Number
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK               Set pending IRQ successfully       
 *  @retval         E_NOT_OK           Set pending IRQ unsuccessfully      
 *
 *  @note           None
 *
 **/
Std_ReturnType System_SetPendingIrq(IRQn_Type p_IrqNumber_en);

/**
 *  @brief          This service to get pending IRQ.
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            IRQn_Type
 *  @param[in]      IrqNumber_en       IRQ Number
 *
 *  @return         boolean     
 *  @retval         TRUE:              Pending IRQ set       
 *  @retval         FALSE:             Pending IRQ not set      
 *
 *  @note           None
 *
 **/
boolean System_GetPendingIrq(IRQn_Type p_IrqNumber_en);

/**
 *  @brief          This service performs initialization of the System Driver component.
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            System_InterruptConfigSetType*
 *  @param[in]      InterruptConfig_ptr             Interrupt Config
 *  @arg            uint8
 *  @param[in]      Interrupt_CfgSet_Index_u8       Cfg set index
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK               Update successfylly      
 *  @retval         E_NOT_OK           Update unsuccessfylly    
 *
 *  @note           None
 *
 **/
Std_ReturnType System_InterruptUpdateConfigSet(const System_InterruptConfigSetType* p_InterruptConfig_ptr, uint8 p_Interrupt_CfgSet_Index_u8);

#if (STD_ON == SYSTEM_VERSION_INFO_API)
/**
 *  @brief          Returns the version information of this module.
 *
 *  @details        The version information includes:
 *                       - Two bytes for the Vendor ID
 *                       - Two bytes for the Module ID
 *                       - One byte  for the Instance ID
 *                       - Three bytes version number. The numbering shall be vendor specific. it consists of:
 *                       - The major, the minor and the patch version number of the module.
 *                       - The AUTOSAR specification version number shall not be included.
 *                         The AUTOSAR specification version number is checked during compile time and therefore not required in this API.
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Std_VersionInfoType*
 *  @param[in]      SystemVersionInfo_ptr            
 *
 *  @return         
 *  @retval         
 *  @retval         
 *
 *  @note           None
 *
 **/
void  System_GetVersionInfo(Std_VersionInfoType* p_SystemVersionInfo_ptr);
#endif /* SYSTEM_VERSION_INFO_API */


/**
 *  @brief          Init system timer
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            System_TimerConfigType*
 *  @param[in]      SystemTimerConfig_ptr            
 *
 *  @return         Void     
 *  @retval         None                    
 *
 *  @note           None
 *
 **/
void SystemTimer_Init(System_TimerConfigType *p_SystemTimerConfig_ptr);

/**
 *  @brief          Get the current counter
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            System_CounterType
 *  @param[in]      SelectedCounter_en            
 *
 *  @return         Void     
 *  @retval         None                    
 *
 *  @note           None
 *
 **/
uint32 System_GetCounter(System_CounterType p_SelectedCounter_en);

/**
 *  @brief          Get the elapsed value from a reference point
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32 * const
 *  @param[in]      CurrentRef_ptr            
 *  @arg            System_CounterType
 *  @param[in]      SelectedCounter_en            
 *
 *  @return         Void     
 *  @retval         None                    
 *
 *  @note           None
 *
 **/
uint32 System_GetElapsed(uint32 * const p_CurrentRef_ptr, System_CounterType p_SelectedCounter_en);

/**
 *  @brief          Set a new frequency used for time conversion (microseconds to ticks)
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32
 *  @param[in]      Freq_u32            
 *  @arg            System_CounterType
 *  @param[in]      SelectedCounter_en            
 *
 *  @return         Void     
 *  @retval         None                    
 *
 *  @note           None
 *
 **/
void System_SetFrequency(uint32 p_Freq_u32, System_CounterType p_SelectedCounter_en);

/**
 *  @brief          Convert microseconds to ticks
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32
 *  @param[in]      Micros_u32            
 *  @arg            System_CounterType
 *  @param[in]      SelectedCounter_en            
 *
 *  @return         Void     
 *  @retval         None                    
 *
 *  @note           None
 *
 **/
uint32 System_UsToTicks(uint32 p_Micros_u32, System_CounterType p_SelectedCounter_en);

/**
 *  @brief          Convert milliseconds to ticks
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32
 *  @param[in]      Milli_u32            
 *  @arg            System_CounterType
 *  @param[in]      SelectedCounter_en            
 *
 *  @return         Void     
 *  @retval         None                    
 *
 *  @note           None
 *
 **/
uint32 System_msToTicks(uint32 p_Milli_u32, System_CounterType p_SelectedCounter_en);

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
