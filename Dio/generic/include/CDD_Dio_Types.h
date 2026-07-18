/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: CDD_Dio_Types.h
 *
 * Description: Implementation of CDD_Dio_Types High Level layer
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

#ifndef CDD_Dio_TYPES_H
#define CDD_Dio_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "Dio_Ipc_Types.h"

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
 * @brief   Type of the external data structure containing the initialization data for this module.
 * @details SRS ID:    SWS_Dio_Hula_XXXXX
 *          Design ID: CDD_Dio_ConfigType_Class
 */
typedef struct
{
    Dio_Ipc_ConfigType (*CDDDioIpcConfig_ptr);   /* Structure contain information of CDD Dio Ipc config set. */
    const uint8 *CoreList_ptr;                 /* Core Index. */
} CDD_Dio_ConfigType;


/**
 *  @brief   Type of the Controller.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_ControllerType_Class
 */
typedef Dio_Ipc_ControllerType Dio_ControllerType;

/**
 *  @brief   Type of the Direction.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_DirectionType_Class
 */
typedef Dio_Ipc_DirectionType Dio_DirectionType;

/**
 *  @brief   Type of the Baudrate Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_BaudrateType_Class
 */
typedef Dio_Ipc_BaudrateType Dio_BaudrateType;

/**
 *  @brief   Type of the Word Length Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_WordLengthType_Class
 */
typedef Dio_Ipc_WordLengthType Dio_WordLengthType;

/**
 *  @brief   Type of the NumberOfStopBit Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_NumberOfStopBitType_Class
 */
typedef Dio_Ipc_NumberOfStopBitType Dio_NumberOfStopBitType;

/**
 *  @brief   Type of the Over Sampling Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_OverSamplingType_Class
 */
typedef Dio_Ipc_OverSamplingType Dio_OverSamplingType;

/**
 *  @brief   Type of the Transfer Method Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_TransferMethodType_Class
 */
typedef Dio_Ipc_TransferMethodType Dio_TransferMethodType;

/**
 *  @brief   Type of the ConfigSet Number Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_ConfigSetNumberType_Class
 */
typedef Dio_Ipc_ConfigSetNumberType Dio_ConfigSetNumberType;

/**
 *  @brief   Type of the CallBackID Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_CallBackIDType_Class
 */
typedef Dio_Ipc_CallBackIDType Dio_CallBackIDType;

/**
 *  @brief   Type of the Application Error Code Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_ErrorCodeType_Class
 */
typedef Dio_Ipc_ErrorCodeType Dio_ErrorCodeType;

/**
 *  @brief   Type of the State Machine Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_StateMachineType_Class
 */
typedef Dio_Ipc_StateMachineType Dio_StateMachineType;

/**
 *  @brief   Type of the One Config Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_OneConfigType_Class
 */
typedef Dio_Ipc_OneConfigType Dio_OneConfigType;

/**
 *  @brief   Type of the EachConfig Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_EachConfigType_Class
 */
typedef Dio_Ipc_EachConfigType Dio_EachConfigType;


/**
 *  @brief   Type of the State Type.
 *  @details SRS ID:     SWS_Dio_Hula_XXXXX
 *           Design ID:  Dio_StateType_Class
 */
typedef Dio_Ipc_StateType Dio_StateType;


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

#endif /* CDD_Dio_TYPES_H */

/*--------------------------------------------------- EOF -----------------------------------------------------*/