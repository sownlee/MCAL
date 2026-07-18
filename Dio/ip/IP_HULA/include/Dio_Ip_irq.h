/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Ip_irq.h
 *
 * Description: Implementation of Dio_Ip_irq IP Level layer
 *              
 * AutoSAR Version:         4.4.0
 *
 * Compiler: GCC IAR
 *
 * Revision:
 *              Version         Date                Change History
 *              0.9.0          07/04/2024           Initial version
 *
 **********************************************************************************************************************/

#ifndef Dio_IP_IRQ_H
#define Dio_IP_IRQ_H

#ifdef __cplusplus
 "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "Dio_Ip_Types.h"


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


#if (Dio_IP_ENABLE_INTERRUPT == STD_ON)

/**
*@brief  Interrupt of Dio_EventTxComplete_cbk.
*/
#if (Dio_EVENTTXCOMPLETE_CBK_ENABLE == STD_ON)
void Dio_EventTxComplete_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr);
#endif

/**
*@brief  Interrupt of Dio_EventRxComplete_cbk.
*/
#if (Dio_EVENTRXCOMPLETE_CBK_ENABLE == STD_ON)
void Dio_EventRxComplete_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr);
#endif

/**
*@brief  Interrupt of Dio_EventIdle_cbk.
*/
#if (Dio_EVENTIDLE_CBK_ENABLE == STD_ON)
void Dio_EventIdle_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr);
#endif

/**
*@brief  Interrupt of Dio_EventCTS_cbk.
*/
#if (Dio_EVENTCTS_CBK_ENABLE == STD_ON)
void Dio_EventCTS_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr);
#endif

/**
*@brief  Interrupt of Dio_EventParityError_cbk.
*/
#if (Dio_EVENTPARITYERROR_CBK_ENABLE == STD_ON)
void Dio_EventParityError_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr);
#endif

/**
*@brief  Interrupt of Dio_EventFramingError_cbk.
*/
#if (Dio_EVENTFRAMINGERROR_CBK_ENABLE == STD_ON)
void Dio_EventFramingError_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr);
#endif

/**
*@brief  Interrupt of Dio_EventNoiseDetectError_cbk.
*/
#if (Dio_EVENTNOISEDETECTERROR_CBK_ENABLE == STD_ON)
void Dio_EventNoiseDetectError_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr);
#endif

/**
*@brief  Interrupt of Dio_EventOverrunError_cbk.
*/
#if (Dio_EVENTOVERRUNERROR_CBK_ENABLE == STD_ON)
void Dio_EventOverrunError_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr);
#endif

#endif

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* Dio_IP_IRQ_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
