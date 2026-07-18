/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: System_Types.h
 *
 * Description: Implementation of System_Types High Level layer
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

#ifndef SYSTEM_TYPES_H
#define SYSTEM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES AND 
 **********************************************************************************************************************/
#include "Std_Types.h"
#include "Interrupt_System_Ip_Types.h"
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
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/
#define SYSTEM_E_INVALID_PARAMETER                   ((uint8)0x01U)
#define SYSTEM_E_INVALID_POINTER                     ((uint8)0x02U)
#define SYSTEM_E_INVALID_CHANNEL                     ((uint8)0x03U)
#define SYSTEM_E_NOT_CONFIGURED                      ((uint8)0x04U)
#define SYSTEM_ENABLEIRQ_ID                          ((uint8)0x05U)
#define SYSTEM_DISABLEIRQ_ID                         ((uint8)0x06U)
#define SYSTEM_INIT_ID                               ((uint8)0x07U)
#define SYSTEM_VERSIONINFO_ID                        ((uint8)0x08U)

/**
 * @brief  The structure for interrupt configuration set element.
 */
typedef struct  System_InterruptConfigSetElementCoreType_t
{
    const Interrupt_System_IP_InterruptConfigSetElementType *InterruptConfigSetElementCoreMem_ptr;  /* Pointer to Interrupt configure set element. */
}  System_InterruptConfigSetElementCoreType;


/**
 * @brief  The structure for interrupt configuration set element.
 */
typedef struct  System_InterruptConfigSetElement_t
{
	uint8 ConfigNumberOfConfigset_u8;                                                         /* Config number of config set */
    const System_InterruptConfigSetElementCoreType *InterruptConfigSetElementCore_ptr;        /* Pointer to Interrupt configure set element. */
}  System_InterruptConfigSetElementType;

/**
 * @brief  The structure for interrupt configuration set.
 */
typedef struct System_InterruptConfigSet_t
{
    uint8 NumberOfInteruptConfigSet_u8;                                         /* Number of Interrupt Config Set. */
    System_InterruptConfigSetElementType *InterruptConfigSetElement_ptr;        /* Pointer to Interrupt configure set element. */    
}  System_InterruptConfigSetType;

/**
 * @brief  System Timer Configuration type structure
 */
typedef struct
{
    uint32 SystemTimerFrequency_u32;      /* The clock frequency. */
    uint8 SYSTEM_USE_SYSTEM_TIMER;        /* config using system timer. */
    uint8 SYSTEM_USE_FREERTOS;            /* config using system FreeRTOS. */
}System_TimerConfigType;

/**
 * @brief  System Configuration type structure
 */
typedef struct System_Config_t
{
  const System_InterruptConfigSetType *SystemInterruptConfigSet_ptr;        /* Pointer to Interrupt configures set. */            
} System_ConfigType;

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


#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_TYPES_H */

/*--------------------------------------------------- EOF -----------------------------------------------------*/