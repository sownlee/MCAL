/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Ipc_Types.h
 *
 * Description: Implementation of Dio_Ipc_Types IP Level layer
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

#ifndef Dio_IPC_TYPES_H
#define Dio_IPC_TYPES_H

#ifdef __cplusplus
extern "C" {
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
/**
 * @brief  Dio configuration struct
 * @details Design ID: Dio_Ipc_ConfigType_Class
 */
typedef struct
{
  Dio_Ip_ConfigType (*DioIpConfig_ptr); /* Structure contain information of Dio IP config set. */
} Dio_Ipc_ConfigType;


/**
 *  @brief   Type of the Controller.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_ControllerType_Class
 */
typedef Dio_Ip_ControllerType Dio_Ipc_ControllerType;

/**
 *  @brief   Type of the Direction.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_DirectionType_Class
 */
typedef Dio_Ip_DirectionType Dio_Ipc_DirectionType;

/**
 *  @brief   Type of the Baudrate Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_BaudrateType_Class
 */
typedef Dio_Ip_BaudrateType Dio_Ipc_BaudrateType;

/**
 *  @brief   Type of the Word Length Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_WordLengthType_Class
 */
typedef Dio_Ip_WordLengthType Dio_Ipc_WordLengthType;

/**
 *  @brief   Type of the NumberOfStopBit Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_NumberOfStopBitType_Class
 */
typedef Dio_Ip_NumberOfStopBitType Dio_Ipc_NumberOfStopBitType;

/**
 *  @brief   Type of the Over Sampling Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_OverSamplingType_Class
 */
typedef Dio_Ip_OverSamplingType Dio_Ipc_OverSamplingType;

/**
 *  @brief   Type of the Transfer Method Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_TransferMethodType_Class
 */
typedef Dio_Ip_TransferMethodType Dio_Ipc_TransferMethodType;

/**
 *  @brief   Type of the ConfigSet Number Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_ConfigSetNumberType_Class
 */
typedef Dio_Ip_ConfigSetNumberType Dio_Ipc_ConfigSetNumberType;

/**
 *  @brief   Type of the CallBackID Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_CallBackIDType_Class
 */
typedef Dio_Ip_CallBackIDType Dio_Ipc_CallBackIDType;

/**
 *  @brief   Type of the Application Error Code Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_ErrorCodeType_Class
 */
typedef Dio_Ip_ErrorCodeType Dio_Ipc_ErrorCodeType;

/**
 *  @brief   Type of the State Machine Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_StateMachineType_Class
 */
typedef Dio_Ip_StateMachineType Dio_Ipc_StateMachineType;

/**
 *  @brief   Type of the One Config Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_OneConfigType_Class
 */
typedef Dio_Ip_OneConfigType Dio_Ipc_OneConfigType;

/**
 *  @brief   Type of the EachConfig Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_EachConfigType_Class
 */
typedef Dio_Ip_EachConfigType Dio_Ipc_EachConfigType;


/**
 *  @brief   Type of the State Type.
 *  @details SRS ID:     N/A
 *           Design ID:  Dio_Ipc_StateType_Class
 */
typedef Dio_Ip_StateType Dio_Ipc_StateType;



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

#endif /* Dio_IPC_TYPES_H */

/*--------------------------------------------------- EOF -----------------------------------------------------*/