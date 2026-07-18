/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Hw.h
 *
 * Description: Implementation of Dio_Hw HW Level layer
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

#ifndef Dio_HW_H
#define Dio_HW_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "STM32F4.h"
#include "Common.h"

/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/

#define GET_CONTROLLER(Controller) ((Controller == 0) ? USART1  : (Controller == 1) ? USART2 \
                                                                : (Controller == 2) ? USART3 \
                                                                : (Controller == 3) ? Dio4 \
                                                                : (Controller == 4) ? Dio5 \
                                                                : (Controller == 5) ? USART6 \
                                                                : 0)

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

/**
 *  @brief          Set direction is TX.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_SettingDirectionTx_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_SettingDirectionTx
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Set direction is RX.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_SettingDirectionRx_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_SettingDirectionRx
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Set word length for Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_SettingWordLength_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *  @arg            uint32   
 *  @param[in]      para_ValueConfig_u32   Config value
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_SettingWordLength
(
    uint32 para_Controller_u32,
    uint32 para_ValueConfig_u32
);

/**
 *  @brief          Set Parity for Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_SettingParity_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *  @arg            uint32   
 *  @param[in]      para_ValueConfig_u32   Config value
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_SettingParity
(
    uint32 para_Controller_u32,
    uint32 para_ValueConfig_u32
);

/**
 *  @brief          Set stop bit for Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_SettingStopBit_Activity
 *                  Hardware Register: CR2
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *  @arg            uint32   
 *  @param[in]      para_ValueConfig_u32   Config value
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_SettingStopBit
(
    uint32 para_Controller_u32,
    uint32 para_ValueConfig_u32
);

/**
 *  @brief          Set HW Flow Control for Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_SettingHWFlowControl_Activity
 *                  Hardware Register: CR3
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *  @arg            uint32   
 *  @param[in]      para_ValueConfig_u32   Config value
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_SettingHWFlowControl
(
    uint32 para_Controller_u32,
    uint32 para_ValueConfig_u32
);

/**
 *  @brief          Set HW Over Sampling for Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_SettingOverSampling_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *  @arg            uint32   
 *  @param[in]      para_ValueConfig_u32   Config value
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_SettingOverSampling
(
    uint32 para_Controller_u32,
    uint32 para_ValueConfig_u32
);

/**
 *  @brief          Set Baudrate for Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_SettingBaudrate_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *  @arg            uint32   
 *  @param[in]      para_ValueConfig_u32   Config value
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_SettingBaudrate
(
    uint32 para_Controller_u32,
    uint32 para_ValueConfig_u32
);

/**
 *  @brief          Get HW Over Sampling for Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_GetOverSampling_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
uint8 Dio_Hw_GetOverSampling
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Enable TXE for Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_EnableTXE_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_EnableTXE
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Enable TXE for Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_EnableTC_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_EnableTC
(
    uint32 para_Controller_u32
);


/**
 *  @brief          Get SR Register.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_GetSRRegister_Activity
 *                  Hardware Register: SR
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
uint32 Dio_Hw_GetSRRegister
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Get CR1 Register.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_GetCR1Register_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
uint32 Dio_Hw_GetCR1Register
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Get CR3 Register.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_GetCR3Register_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
uint32 Dio_Hw_GetCR3Register
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Clean TC Flag.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_CleanTCFlag_Activity
 *                  Hardware Register: SR
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_CleanTCFlag
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Clean TCIE Control Bit.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_CleanTCIEControlBit_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_CleanTCIEControlBit
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Write Data To DR.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_WriteDataToDR_Activity
 *                  Hardware Register: DR
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *  @arg            uint8   
 *  @param[in]      para_Data_u8           Data
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_WriteDataToDR
(
    uint32 para_Controller_u32,
    uint8 para_Data_u8
);

/**
 *  @brief          Clean TXEIE.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_CleanTXEIE_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_CleanTXEIE
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Clean RXNE Control Bit.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_CleanRXNEControlBit_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_CleanRXNEControlBit
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Clean RXNE Flag.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_CleanRXNEFlag_Activity
 *                  Hardware Register: SR
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_CleanRXNEFlag
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Read Data From DR.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_ReadDataFromDR_Activity
 *                  Hardware Register: DR
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
uint32 Dio_Hw_ReadDataFromDR
(
    uint32 para_Controller_u32
);


/**
 *  @brief          Clean CTS Flag.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_CleanCTSFlag_Activity
 *                  Hardware Register: SR
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_CleanCTSFlag
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Clean IDLE Flag.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_CleanIDLEFlag_Activity
 *                  Hardware Register: SR
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_CleanIDLEFlag
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Enable RXNE.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_EnableRXNE_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_EnableRXNE
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Clean All Flag in SR register.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_CleanAllFlag_Activity
 *                  Hardware Register: SR
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_CleanAllFlag
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Enable Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_EnableDio_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_EnableDio
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Enable Request DMA TX Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_EnableRequestTxDMA_Activity
 *                  Hardware Register: CR3
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_EnableRequestTxDMA
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Enable Request DMA RX Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_EnableRequestRxDMA_Activity
 *                  Hardware Register: CR3
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_EnableRequestRxDMA
(
    uint32 para_Controller_u32
);

/**
 *  @brief          Disable Dio.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_DisableDio_Activity
 *                  Hardware Register: CR1
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Hw_DisableDio
(
    uint32 para_Controller_u32
);

/**
 *  @brief          get baseaddress DR register.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            Dio_HW_XXXXX
 *                  Design ID:         Dio_Hw_GetBaseAddressDR_Activity
 *                  Hardware Register: DR
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint32   
 *  @param[in]      para_Controller_u32    Controller
 *
 *  @return         None     
 *  @retval         None                                           
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
uint32 Dio_Hw_GetBaseAddressDR
(
    uint32 para_Controller_u32
);

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* Dio_HW_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
