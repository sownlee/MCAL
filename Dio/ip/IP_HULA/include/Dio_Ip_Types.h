/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Ip_Types.h
 *
 * Description: Implementation of Dio_Ip_Types IP Level layer
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

#ifndef Dio_IP_TYPES_H
#define Dio_IP_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Dio_Ip_Devassert.h"
#include "Dio_Ip_Types_Cfg.h"

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
 *  @brief   Type of the Controller Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_ControllerType_Enumeration
 */
typedef enum 
{
    CONTROLLER_USART1 = 0x00U,    
    CONTROLLER_USART2,           
    CONTROLLER_USART3,         
    CONTROLLER_Dio4,         
    CONTROLLER_Dio5,         
    CONTROLLER_USART6  
} Dio_Ip_ControllerType;

/**
 *  @brief   Type of the Direction Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_DirectionType_Enumeration
 */
typedef enum 
{
    USART_MODE_ONLY_TX = 0x00U,    
    USART_MODE_ONLY_RX,           
    USART_MODE_TXRX
} Dio_Ip_DirectionType;

/**
 *  @brief   Type of the Baudrate Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_BaudrateType_Enumeration
 */
typedef enum 
{
    USART_BAUDRATE_1200 = 1200U,    
    USART_BAUDRATE_2400 = 2400U,    
    USART_BAUDRATE_9600 = 9600U,    
    USART_BAUDRATE_19200 = 19200U,    
    USART_BAUDRATE_38400 = 38400U,    
    USART_BAUDRATE_57600 = 57600U,    
    USART_BAUDRATE_115200 = 115200U,    
    USART_BAUDRATE_230400 = 230400U,    
    USART_BAUDRATE_460800 = 460800U,    
    USART_BAUDRATE_921600 = 921600U,    
    USART_BAUDRATE_2M = 2000000U,    
    USART_BAUDRATE_3M = 3000000U   
} Dio_Ip_BaudrateType;

/**
 *  @brief   Type of the Parity Control Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_ParityControlType_Enumeration
 */
typedef enum 
{
    USART_PARITY_DISABLE = 0U,    
    USART_PARITY_EN_EVEN,    
    USART_PARITY_EN_ODD 
} Dio_Ip_ParityControlType;

/**
 *  @brief   Type of the Word Length Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_WordLengthType_Enumeration
 */
typedef enum 
{
    USART_WORDLENGTH_8BITS = 0U,    
    USART_WORDLENGTH_9BITS
} Dio_Ip_WordLengthType;

/**
 *  @brief   Type of the Number Of Stop Bit Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_NumberOfStopBitType_Enumeration
 */
typedef enum 
{
    USART_STOP_BIT_1 = 0U,    
    USART_STOP_BIT_0_POINT_5,
    USART_STOP_BIT_2,
    USART_STOP_BIT_1_POINT_5
} Dio_Ip_NumberOfStopBitType;

/**
 *  @brief   Type of the HW Flow Control Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_HWFlowControlType_Enumeration
 */
typedef enum 
{
    USART_HW_FLOW_CTRL_NONE = 0U,    
    USART_HW_FLOW_CTRL_CTS,
    USART_HW_FLOW_CTRL_RTS,
    USART_HW_FLOW_CTRL_CTS_RTS
} Dio_Ip_HWFlowControlType;

/**
 *  @brief   Type of the Over Sampling Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_OverSamplingType_Enumeration
 */
typedef enum 
{
    USART_OVER_SAMPLING_16 = 0U,    
    USART_OVER_SAMPLING_8
} Dio_Ip_OverSamplingType;

/**
 *  @brief   Type of the Transfer Method Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_TransferMethodType_Enumeration
 */
typedef enum 
{
    USART_TRANSFER_METHOD_POLLING = 0U,    
    USART_TRANSFER_METHOD_INTERRUPT,
    USART_TRANSFER_METHOD_DMA
} Dio_Ip_TransferMethodType;


/**
 *  @brief   Defines the identification (ID) for Dio setting.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_ConfigSetNumberType_Class
 */
typedef uint32 Dio_Ip_ConfigSetNumberType;


/**
 *  @brief   Type of Call back ID.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_CallBackIDType_Enumeration
 */
typedef enum
{
  Dio_STATUS_TX_COMPLETE_CB_ID              = 0x00U,  
  Dio_STATUS_EVENT_CTS_CB_ID                = 0x01U,  
  Dio_STATUS_TRANSMITCOMPLETE_CB_ID         = 0x02U,  
  Dio_STATUS_RX_COMPLETE_CB_ID              = 0x03U,  
  Dio_STATUS_OVERRUN_ERROR_CB_ID            = 0x04U,  
  Dio_STATUS_EVENT_IDLE_CB_ID               = 0x05U,  
  Dio_STATUS_PARITY_ERROR_CB_ID             = 0x06U,  
  Dio_STATUS_BREAKFLAG_CB_ID                = 0x07U,  
  Dio_STATUS_NOISE_ERROR_CB_ID              = 0x08U,
  Dio_STATUS_FRAMING_ERROR_CB_ID            = 0x09U,
  Dio_STATUS_TIMING_ERROR_CB_ID             = 0x0AU,
  Dio_STATUS_DMA_ERROR_CB_ID                = 0x0BU,
  Dio_STATUS_BUSY_ERROR_CB_ID               = 0x0CU,
  Dio_STATUS_ABORTED_CB_ID                  = 0x0DU,
}Dio_Ip_CallBackIDType;


/**
 *  @brief   Type of Error Code Type.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_ErrorCodeType_Enumeration
 */
typedef enum
{
  Dio_ERRORCODE_NO_ERROR              = 0x00U,
  Dio_ERRORCODE_TX_COMPLETE           = 0x01U,
  Dio_ERRORCODE_EVENT_CTS             = 0x02U,
  Dio_ERRORCODE_TRANSMITCOMPLETE      = 0x03U,
  Dio_ERRORCODE_RX_COMPLETE           = 0x04U,
  Dio_ERRORCODE_OVERRUN_ERROR         = 0x05U,
  Dio_ERRORCODE_EVENT_IDLE            = 0x06U,
  Dio_ERRORCODE_PARITY_ERROR          = 0x07U,
  Dio_ERRORCODE_BREAKFLAG             = 0x08U,
  Dio_ERRORCODE_NOISE_ERROR           = 0x09U,
  Dio_ERRORCODE_FRAMING_ERROR         = 0x10U,
  Dio_ERRORCODE_TIMING_ERROR          = 0x11U,
  Dio_ERRORCODE_ABORTED               = 0x12U,
  Dio_ERRORCODE_DMA_ERROR             = 0x13U,
  Dio_ERRORCODE_BUSY_ERROR            = 0x14U
}Dio_Ip_ErrorCodeType;


/**
 *  @brief   Type of the State machine.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_StateMachineType_Enumeration
 */
typedef enum
{
  Dio_DRIVER_UNINIT   = 0x00U,            /* Dio not yet initialized or disabled */
  Dio_DRIVER_INIT,                        /* Dio initialized and ready for use   */
  Dio_DRIVER_ABORT                        /* Dio abort   */
}Dio_Ip_StateMachineType;


/**
 *  @brief   Definition of only a Dio configuration structure.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_OneConfigType_Class
 */
typedef struct 
{
    /* The Controller */
    Dio_Ip_ControllerType DioController_e;
    /* The DioTransferMethod */
    Dio_Ip_TransferMethodType DioTransferMethod_e;
    /* The DioDirection */
    Dio_Ip_DirectionType DioDirection_e;
    /* The DioBaudrate */
    Dio_Ip_BaudrateType DioBaudrate_e;
    /* The DioParityControl */
    Dio_Ip_ParityControlType DioParityControl_e;
    /* The DioWordLength */
    Dio_Ip_WordLengthType DioWordLength_e;
    /* The DioNumberOfStopBits */
    Dio_Ip_NumberOfStopBitType DioNumberOfStopBits_e;
    /* The DioHWFlowControl */
    Dio_Ip_HWFlowControlType DioHWFlowControl_e;
    /* The DioOverSampling */
    Dio_Ip_OverSamplingType DioOverSampling_e;
    /* The ClockFrequencyFromMcu */
    uint32 ClockFrequencyFromMcu_u32;
    /* The DmaConfigNumberTx */
    uint32 DmaConfigNumberTx_u32;
    /* The DmaConfigNumberRx */
    uint32 DmaConfigNumberRx_u32;
} Dio_Ip_OneConfigType;

/**
 *  @brief   Definition of a One configuration structure.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_EachConfigType_Class
 */
typedef struct 
{
    /* The ID for Dio configuration */
    Dio_Ip_ConfigSetNumberType DioConfigId_u32;      
    /* The config Peripheral */
    const Dio_Ip_OneConfigType c_Ip_ConfigDio_ptr;
} Dio_Ip_EachConfigType;

/**
 *  @brief   Type of state and error of Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_StateType_Class
 */
typedef struct
{
    /* Dio State Machine */
    volatile Dio_Ip_StateMachineType StateMachine_e;
    /* Dio Application Error Code */
    volatile Dio_Ip_ErrorCodeType ErrorCode_e;
} Dio_Ip_StateType;

/**
 *  @brief   Type of State Structure of Dio.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_StateStructureType_Class
 */
typedef struct
{
    /* Dio Tx buffer */
    uint8 * DioTxBuff_ptr;
    /* Dio Rx buffer */
    uint8 * DioRxBuff_ptr;
    /* Dio Tx length */
    volatile uint32  DioTxLength_u32;
    /* Dio Rx length */
    volatile uint32  DioRxLength_u32;
    /* Dio Tx busy */
    volatile boolean IsTxBusy_b;
    /* Dio Rx busy */
    volatile boolean IsRxBusy_b;
} Dio_Ip_StateStructureType;

/**
 *  @brief   Type of the external data structure containing the initialization data for Dio module.
 *  @details SRS ID:     Dio_IP_HuLa_XXXXX
 *           Design ID:  Dio_Ip_ConfigType_Class
 */
typedef struct
{
    /* Number Dio configuration. */
    const Dio_Ip_ConfigSetNumberType c_ConfigNumber_u32;

    /* State and Error of Dio driver. */
    Dio_Ip_StateType DioState_st;

    /* State Structure Dio. */
    Dio_Ip_StateStructureType DioStateStruct_ptr;

    /* Dio data configuration. */
    const Dio_Ip_EachConfigType (*c_ConfigSet_ptr)[Dio_TYPES_MAX_CONFIGSET];     
} Dio_Ip_ConfigType;
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

#endif /* Dio_IP_TYPES_H */

/*--------------------------------------------------- EOF -----------------------------------------------------*/