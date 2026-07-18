/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Ip.c
 *
 * Description: Implementation of Dio_Ip IP Level layer
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

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES
 **********************************************************************************************************************/

#include "Dio_Ip.h"
#include "Dio_Ip_VersionInfo.h"
#include "Common.h"

#if(STD_ON == Dio_IP_USERMODE_SUPPORT)
#include "OsIf_Internal.h"
#endif

/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

#ifndef DISABLE_EXTERNAL_VERSION_CHECK
/**
 * @brief Check if Dio_Ip.c and Dio_Ip_Cfg.h are of the same version
 */
#if ((Dio_IP_SW_MAJOR_VERSION != Dio_IP_CFG_SW_MAJOR_VERSION) || \
     (Dio_IP_SW_MINOR_VERSION != Dio_IP_CFG_SW_MINOR_VERSION) || \
     (Dio_IP_SW_PATCH_VERSION != Dio_IP_CFG_SW_PATCH_VERSION))
#error "Inconsistent Software Versions of Dio_Ip.c and Dio_Ip_Cfg.h"
#endif
#endif

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

#define START_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

static Dio_Ip_ConfigType *Dio_Ip_s_c_Config_ptr;

#define STOP_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/***********************************************************************************************************************
 *                                                 GLOBAL VARIABLES
 **********************************************************************************************************************/
#define START_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* Event Tx Complete callback */
void (*EventTxCompleteCallback)(Dio_Ip_ConfigType *para_DioConfig_ptr);       

/* Event Rx Complete callbackk */
void (*EventRxCompleteCallback)(Dio_Ip_ConfigType *para_DioConfig_ptr);   

/* Event Idle callback */
void (*EventIdleCallback)(Dio_Ip_ConfigType *para_DioConfig_ptr);      

/* Event CTS callback */
void (*EventCTSCallback)(Dio_Ip_ConfigType *para_DioConfig_ptr);  

/* Event Parity Error callback  */
void (*EventParityErrorCallback)(Dio_Ip_ConfigType *para_DioConfig_ptr);      

/* Event Framing Error callback */
void (*EventFramingErrorCallback)(Dio_Ip_ConfigType *para_DioConfig_ptr); 

/* Event Noise Detect Error callback */
void (*EventNoiseDetectErrorCallback)(Dio_Ip_ConfigType *para_DioConfig_ptr); 

/* Event Overrun Error callback */
void (*EventOverrunErrorCallback)(Dio_Ip_ConfigType *para_DioConfig_ptr); 

boolean g_SetDmaConfigFlag_b = FALSE;

#define STOP_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/***********************************************************************************************************************
 *                                             LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define START_CODE
#include "MemMap.h"

static void Mcu_Ip_StartTimeout
(
    uint32 *para_StartTimeOut_ptr,
    uint32 *para_ElapsedTimeOut_ptr,
    uint32 *para_TimeoutTicksOut_ptr,
    uint32  para_TimeoutUs_u32
);

static boolean Mcu_Ip_TimeoutExpired
(
    uint32 *para_StartTimeInOut_ptr,
    uint32 *para_ElapsedTimeInOut_ptr,
    uint32 para_TimeoutTicks_u32
);

static void Dio_Ip_SetBaudrate
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    Dio_Ip_BaudrateType para_Baudrate_e
);

static boolean Dio_Ip_UpdateDioConfigset
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr
);

static uint8 Dio_Ip_StartSendDataUsingInterrupt
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);

static uint8 Dio_Ip_StartSendDataUsingDma
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);

static uint8 Dio_Ip_StartReceiveDataUsingInterrupt
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);

static uint8 Dio_Ip_StartReceiveDataUsingDma
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);

static void Dio_Ip_AssignFunctionInterruptCallBack(void);

static void Dio_Ip_ResetStateErrorStruct(void);

#define STOP_CODE
#include "MemMap.h"

/***********************************************************************************************************************
 *                                                  LOCAL FUNCTION
 **********************************************************************************************************************/


#define START_CODE
#include "MemMap.h"


static void Mcu_Ip_StartTimeout
(
    uint32 *para_StartTimeOut_ptr,
    uint32 *para_ElapsedTimeOut_ptr,
    uint32 *para_TimeoutTicksOut_ptr,
    uint32  para_TimeoutUs_u32
)
{
    (void)GetCounterValue(0,para_StartTimeOut_ptr);
    *para_ElapsedTimeOut_ptr  = 0U;
    *para_TimeoutTicksOut_ptr = para_TimeoutUs_u32;
}

static boolean Mcu_Ip_TimeoutExpired
(
    uint32 *para_StartTimeInOut_ptr,
    uint32 *para_ElapsedTimeInOut_ptr,
    uint32 para_TimeoutTicks_u32
)
{
   (void)GetElapsedValue(0,para_StartTimeInOut_ptr,para_ElapsedTimeInOut_ptr);
    
    return ((*para_ElapsedTimeInOut_ptr >= para_TimeoutTicks_u32)? TRUE : FALSE);
}

static void Dio_Ip_AssignFunctionInterruptCallBack(void)
{ 
     /* Interrupt Handler */
     #if (Dio_IP_ENABLE_INTERRUPT == STD_ON)
          /**
          *@brief  Interrupt of Dio_EventTxComplete_cbk.
          */
          #if (Dio_EVENTTXCOMPLETE_CBK_ENABLE == STD_ON)
               EventTxCompleteCallback = &Dio_EventTxComplete_cbk;
          #else 
               EventTxCompleteCallback = NULL_PTR;
          #endif

          /**
          *@brief  Interrupt of Dio_EventRxComplete_cbk.
          */
          #if (Dio_EVENTRXCOMPLETE_CBK_ENABLE == STD_ON)
               EventRxCompleteCallback = &Dio_EventRxComplete_cbk;
          #else 
               EventTxCompleteCallback = NULL_PTR;
          #endif

          /**
          *@brief  Interrupt of Dio_EventIdle_cbk.
          */
          #if (Dio_EVENTIDLE_CBK_ENABLE == STD_ON)
               EventIdleCallback = &Dio_EventIdle_cbk;
          #else 
               EventIdleCallback = NULL_PTR;
          #endif

          /**
          *@brief  Interrupt of Dio_EventCTS_cbk.
          */
          #if (Dio_EVENTCTS_CBK_ENABLE == STD_ON)
               EventCTSCallback = &Dio_EventCTS_cbk;
          #else 
               EventCTSCallback = NULL_PTR;
          #endif

          /**
          *@brief  Interrupt of Dio_EventParityError_cbk.
          */
          #if (Dio_EVENTPARITYERROR_CBK_ENABLE == STD_ON)
               EventParityErrorCallback = &Dio_EventParityError_cbk;
          #else 
               EventParityErrorCallback = NULL_PTR;
          #endif

          /**
          *@brief  Interrupt of Dio_EventFramingError_cbk.
          */
          #if (Dio_EVENTFRAMINGERROR_CBK_ENABLE == STD_ON)
               EventFramingErrorCallback = &Dio_EventFramingError_cbk;
          #else 
               EventFramingErrorCallback = NULL_PTR;
          #endif

          /**
          *@brief  Interrupt of Dio_EventNoiseDetectError_cbk.
          */
          #if (Dio_EVENTNOISEDETECTERROR_CBK_ENABLE == STD_ON)
               EventNoiseDetectErrorCallback = &Dio_EventNoiseDetectError_cbk;
          #else 
               EventNoiseDetectErrorCallback = NULL_PTR;
          #endif

          /**
          *@brief  Interrupt of Dio_EventOverrunError_cbk.
          */
          #if (Dio_EVENTOVERRUNERROR_CBK_ENABLE == STD_ON)
               EventOverrunErrorCallback = &Dio_EventOverrunError_cbk;
          #else 
               EventOverrunErrorCallback = NULL_PTR;
          #endif
     #endif
}

static void Dio_Ip_SetBaudrate
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    Dio_Ip_BaudrateType para_Baudrate_e
)
{
     uint32 l_PeripheralClock_u32 = 0;
     uint32 l_USARTDIV_u32 = 0;
     uint32 l_Mantissa_u32 = 0;
     uint32 l_Fraction_u32 = 0;
     uint32 l_BaudRate_u32 = 0;
     uint32 l_BRR_u32 = 0;
     Dio_Ip_ControllerType l_Controller_e;

     l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;
     l_BaudRate_u32 = (uint32)para_Baudrate_e;

     l_PeripheralClock_u32 = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.ClockFrequencyFromMcu_u32;

     if (Dio_Hw_GetOverSampling(l_Controller_e) == USART_OVER_SAMPLING_16)
     {
          l_USARTDIV_u32 = ((25 * l_PeripheralClock_u32) / (4 *l_BaudRate_u32));
     }
     else if (Dio_Hw_GetOverSampling(l_Controller_e) == USART_OVER_SAMPLING_8)
     {
          l_USARTDIV_u32 = ((25 * l_PeripheralClock_u32) / (2 *l_BaudRate_u32));
     }

     /* Mantissa */
     l_Mantissa_u32 = l_USARTDIV_u32 / 100U;
     l_BRR_u32 |= (l_Mantissa_u32 << 4U);

     /* Fraction */
     l_Fraction_u32 = (l_USARTDIV_u32 - (l_Mantissa_u32 * 100U));

     if (Dio_Hw_GetOverSampling(l_Controller_e) == USART_OVER_SAMPLING_16)
     {
          l_Fraction_u32 = ((( l_Fraction_u32 * 16U) + 50U) / 100U) & ((uint8_t)0x0FU);
     }
     else if (Dio_Hw_GetOverSampling(l_Controller_e) == USART_OVER_SAMPLING_8)
     {
          l_Fraction_u32 = ((( l_Fraction_u32 * 8U) + 50U) / 100U)& ((uint8_t)0x07U);
     }
     l_BRR_u32 |=  l_Fraction_u32;

     /* Setting Baudrate */
     Dio_Hw_SettingBaudrate(l_Controller_e, l_BRR_u32);
}


static boolean Dio_Ip_UpdateDioConfigset
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr
)
{
     Dio_Ip_ControllerType l_Controller_e;
     boolean l_ReturnValue_b = TRUE;

     if (NULL_PTR != para_DioConfig_ptr)
     {
          l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;

          /* Setting for Begin CR1 */
          /* Setting Direction */
          if (USART_MODE_ONLY_TX == para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioDirection_e)
          {
               Dio_Hw_SettingDirectionTx(l_Controller_e);
          }
          else if (USART_MODE_ONLY_RX == para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioDirection_e)
          {
               Dio_Hw_SettingDirectionRx(l_Controller_e);
          }
          else if (USART_MODE_TXRX == para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioDirection_e)
          {
               Dio_Hw_SettingDirectionTx(l_Controller_e);
               Dio_Hw_SettingDirectionRx(l_Controller_e);
          }
          
          /* Setting Word length */ 
          Dio_Hw_SettingWordLength(l_Controller_e, para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioWordLength_e);

          /* Setting Setting Parity */ 
          Dio_Hw_SettingParity(l_Controller_e, para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioParityControl_e);

          /* Setting OverSampling */ 
          Dio_Hw_SettingOverSampling(l_Controller_e, para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioOverSampling_e);


          /* Setting for Begin CR2 */
          /* Setting Stop bit */ 
          Dio_Hw_SettingStopBit(l_Controller_e, para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioNumberOfStopBits_e);


          /* Setting for Begin CR3 */
          /* Setting HW Flow Control */ 
          Dio_Hw_SettingHWFlowControl(l_Controller_e, para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioHWFlowControl_e);

          
          /* Set Baudrate */
          Dio_Ip_SetBaudrate(para_DioConfig_ptr, para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioBaudrate_e);

          /* Enable Dio */
          Dio_Hw_EnableDio(l_Controller_e);
          

          /* Clean all flag in SR register */
          Dio_Hw_CleanAllFlag(l_Controller_e);

          l_ReturnValue_b = TRUE;
     }
     else
     {
          l_ReturnValue_b = FALSE;
     }
     
     return l_ReturnValue_b;
}

static void Dio_Ip_ResetStateErrorStruct(void)
{
     Dio_IP_DEV_ASSERT(NULL_PTR != Dio_Ip_s_c_Config_ptr);

     /* Reset State machine */
     Dio_Ip_s_c_Config_ptr->DioState_st.StateMachine_e = Dio_DRIVER_UNINIT;

     /* Reset Error of Driver */
     Dio_Ip_s_c_Config_ptr->DioState_st.ErrorCode_e = Dio_ERRORCODE_NO_ERROR;

     /* Reset Struct Interrupt */
     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b = FALSE;
     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b = FALSE;
}

static uint8 Dio_Ip_StartSendDataUsingInterrupt
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
)
{
     Dio_Ip_ControllerType l_Controller_e;
     l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;
               

     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxLength_u32 = para_BufferSize_u32;
     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxBuff_ptr = para_Buffer_ptr;
     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b = TRUE;

     /* Enable interrupt for TXE (Transmit Data Register Empty) */
     Dio_Hw_EnableTXE(l_Controller_e);

     /* Enable interrupt for TC (Transmission Complete) */
     Dio_Hw_EnableTC(l_Controller_e);

     return E_OK;
}

static uint8 Dio_Ip_StartSendDataUsingDma
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
)
{
     Dio_Ip_ControllerType l_Controller_e;
     l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;
               
     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b = TRUE;

     #if (Dio_IP_ENABLE_DMA == STD_ON)
     /* Set config for DMA */
     Mcl_SetDmaConfig(para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DmaConfigNumberTx_u32);

     /* Start transfer from Buffer to DR register */
     Mcl_StartDmaTransfer(para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DmaConfigNumberTx_u32, (uint32)para_Buffer_ptr, (uint32)(Dio_Hw_GetBaseAddressDR(l_Controller_e)), para_BufferSize_u32);

     /* Enable DMA Request for TX send data */
     Dio_Hw_EnableRequestTxDMA(l_Controller_e);
     #endif

     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b = FALSE;

     return E_OK;
}


static uint8 Dio_Ip_StartReceiveDataUsingInterrupt
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
)
{
     Dio_Ip_ControllerType l_Controller_e;
     l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;
               

     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxLength_u32 = para_BufferSize_u32;
     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxBuff_ptr = para_Buffer_ptr;
     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b = TRUE;

     /* Read DR register to RXNE is SET */
     Dio_Hw_ReadDataFromDR(l_Controller_e);

     /* Enable interrupt for RXNE (Receive Data Ready to be Read) */
     Dio_Hw_EnableRXNE(l_Controller_e);

     return (E_OK);
}

static uint8 Dio_Ip_StartReceiveDataUsingDma
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
)
{
     Dio_Ip_ControllerType l_Controller_e;
     l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;
               
     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b = TRUE;

     #if (Dio_IP_ENABLE_DMA == STD_ON)

     if (g_SetDmaConfigFlag_b == FALSE)
     {
          /* Set config for DMA */
          Mcl_SetDmaConfig(para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DmaConfigNumberRx_u32);

          g_SetDmaConfigFlag_b = TRUE;
     }

     /* Start transfer from DR to Buffer register */
     Mcl_StartDmaTransfer(para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DmaConfigNumberRx_u32, (uint32)(Dio_Hw_GetBaseAddressDR(l_Controller_e)), (uint32)para_Buffer_ptr , para_BufferSize_u32);

     /* Enable DMA Request for RX send data */
     Dio_Hw_EnableRequestRxDMA(l_Controller_e);
     #endif

     Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b = FALSE;

     return E_OK;
}

#define STOP_CODE
#include "MemMap.h"

/***********************************************************************************************************************
 *                                                  GLOBAL FUNCTION
 **********************************************************************************************************************/
#define START_CODE
#include "MemMap.h"



/**
 *  @brief          Initializes the Dio Driver module.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            Dio_IP_XXXXX
 *                  Design ID:         Dio_Ipc_Init_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            const Dio_Dma_Ip_ConfigType *  
 *  @param[in]      para_DioIpConfig_ptr         Pointer to configuration structure.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Ip_Init
(
    Dio_Ip_ConfigType *para_DioIpConfig_ptr
)
{
     Dio_IP_DEV_ASSERT(NULL_PTR != para_DioIpConfig_ptr);

     /* Assign config for local ip config */
     Dio_Ip_s_c_Config_ptr = para_DioIpConfig_ptr;

     /* Assing Function Interrupt Callback */
     Dio_Ip_AssignFunctionInterruptCallBack();

     /* Reset State machine and Error */
     Dio_Ip_ResetStateErrorStruct();

     /* Init for configset Zero */
     (void)Dio_Ip_UpdateDioConfigset(&(*Dio_Ip_s_c_Config_ptr->c_ConfigSet_ptr)[0]);

     /* Change StateMachine driver to INIT */
     Dio_Ip_s_c_Config_ptr->DioState_st.StateMachine_e = Dio_DRIVER_INIT;
}


/**
 *  @brief          This function sets config for Dio.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            Dio_IP_XXXXX
 *                  Design ID:         Dio_Ip_SetDioConfig_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ip_EachConfigType *  
 *  @param[in]      para_DioConfig_ptr         Pointer to configuration structure.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Ip_SetDioConfig
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr
)
{
     Dio_IP_DEV_ASSERT(NULL_PTR != para_DioConfig_ptr);

     if (NULL_PTR != Dio_Ip_s_c_Config_ptr)
     {
          (void)Dio_Ip_UpdateDioConfigset(para_DioConfig_ptr);
     }
}


/**
 *  @brief          This function to Async Send.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            Dio_IP_XXXXX
 *                  Design ID:         Dio_Ip_AsyncSend_Activity
 *                  Sync/Async:        Asynchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ip_EachConfigType *  
 *  @param[in]      para_DioConfig_ptr              Pointer to configuration structure.
 *  @arg            uint8 *
 *  @param[in]      para_Buffer_ptr                  Pointer to Buffer.
 *  @arg            uint32
 *  @param[in]      para_BufferSize_u32              Size of Bufer.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *
 **/
Std_ReturnType Dio_Ip_AsyncSend
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
)
{
     Std_ReturnType l_ReturnValue_u8 = E_OK;

     Dio_IP_DEV_ASSERT(NULL_PTR != para_DioConfig_ptr);
     Dio_IP_DEV_ASSERT(NULL_PTR != para_Buffer_ptr);
     Dio_IP_DEV_ASSERT(0U != para_BufferSize_u32);

     if (Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b == TRUE)
     {
          Dio_Ip_s_c_Config_ptr->DioState_st.ErrorCode_e = Dio_ERRORCODE_BUSY_ERROR;
          Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_BUSY_ERROR_CB_ID);
          l_ReturnValue_u8 = E_NOT_OK;
     }

     if (l_ReturnValue_u8 == E_OK)
     {
          Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b = TRUE;

          if (USART_TRANSFER_METHOD_INTERRUPT == para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioTransferMethod_e)
          {
               /* Start the transmission process using interrupts */
               l_ReturnValue_u8 = Dio_Ip_StartSendDataUsingInterrupt(para_DioConfig_ptr, para_Buffer_ptr, para_BufferSize_u32);
          }
          #if (Dio_IP_ENABLE_DMA == STD_ON)
          else if (USART_TRANSFER_METHOD_DMA == para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioTransferMethod_e)
          {
               /* Start the transmission process using DMA */
               l_ReturnValue_u8 = Dio_Ip_StartSendDataUsingDma(para_DioConfig_ptr, para_Buffer_ptr, para_BufferSize_u32);
          }
          #endif /* (Dio_IP_ENABLE_DMA == STD_ON) */
     }

     return l_ReturnValue_u8;
}


/**
 *  @brief          This function to Async Receive.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            Dio_IP_XXXXX
 *                  Design ID:         Dio_Ip_AsyncReceive_Activity
 *                  Sync/Async:        Asynchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ip_EachConfigType *  
 *  @param[in]      para_DioConfig_ptr              Pointer to configuration structure.
 *  @arg            uint8 *
 *  @param[in]      para_Buffer_ptr                  Pointer to Buffer.
 *  @arg            uint32
 *  @param[in]      para_BufferSize_u32              Size of Bufer.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *
 **/
Std_ReturnType Dio_Ip_AsyncReceive
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
)
{
     Std_ReturnType l_ReturnValue_u8 = E_NOT_OK;

     Dio_IP_DEV_ASSERT(NULL_PTR != para_DioConfig_ptr);
     Dio_IP_DEV_ASSERT(NULL_PTR != para_Buffer_ptr);
     Dio_IP_DEV_ASSERT(0U != para_BufferSize_u32);

     if (USART_TRANSFER_METHOD_INTERRUPT == para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioTransferMethod_e)
     {
          if (Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b == FALSE)
          {
               Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b = TRUE;

               /* Start the receive process using interrupts */
               l_ReturnValue_u8 = Dio_Ip_StartReceiveDataUsingInterrupt(para_DioConfig_ptr, para_Buffer_ptr, para_BufferSize_u32);
          }
          else
          {
               l_ReturnValue_u8 = E_NOT_OK;
          }
     }
     #if (Dio_IP_ENABLE_DMA == STD_ON)
     else if (USART_TRANSFER_METHOD_DMA == para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioTransferMethod_e)
     {
          /* Start the receive process using DMA */
          l_ReturnValue_u8 = Dio_Ip_StartReceiveDataUsingDma(para_DioConfig_ptr, para_Buffer_ptr, para_BufferSize_u32);
     }
     #endif /* (Dio_IP_ENABLE_DMA == STD_ON) */

     return l_ReturnValue_u8;
}


/**
 *  @brief          This function to Sync Send.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            Dio_IP_XXXXX
 *                  Design ID:         Dio_Ip_SyncSend_Activity
 *                  Sync/Async:        Asynchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ip_EachConfigType *  
 *  @param[in]      para_DioConfig_ptr              Pointer to configuration structure.
 *  @arg            uint8 *
 *  @param[in]      para_Buffer_ptr                  Pointer to Buffer.
 *  @arg            uint32
 *  @param[in]      para_BufferSize_u32              Size of Bufer.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *
 **/
Std_ReturnType Dio_Ip_SyncSend
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
)
{
     Std_ReturnType l_ReturnValue_u8 = E_OK;
     uint32 l_Counter_u32;
     uint32 l_StartTime_u32;
     uint32 l_ElapsedTime_u32;
     uint32 l_TimeoutTicks_u32;
     boolean l_Timeout_b = FALSE;
     uint32 l_FlagStatus_u32;
     Dio_Ip_ControllerType l_Controller_e;
     l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;

     Dio_IP_DEV_ASSERT(NULL_PTR != para_DioConfig_ptr);
     Dio_IP_DEV_ASSERT(NULL_PTR != para_Buffer_ptr);
     Dio_IP_DEV_ASSERT(0U != para_BufferSize_u32);

     if (TRUE == Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b)
     {
          l_ReturnValue_u8 = E_NOT_OK;
          Dio_Ip_s_c_Config_ptr->DioState_st.ErrorCode_e = Dio_ERRORCODE_BUSY_ERROR;
          Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_BUSY_ERROR_CB_ID);
     }
     else
     {
          Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b = TRUE;

          for (l_Counter_u32 = 0; l_Counter_u32 < para_BufferSize_u32; l_Counter_u32++)
          {
               /* Wait until TXE flag is SET in SR Register */
               Mcu_Ip_StartTimeout(&l_StartTime_u32, &l_ElapsedTime_u32, &l_TimeoutTicks_u32, 100000);
               do
               {
                    l_Timeout_b = Mcu_Ip_TimeoutExpired(&l_StartTime_u32, &l_ElapsedTime_u32, l_TimeoutTicks_u32);
                    l_FlagStatus_u32 = (Dio_Hw_GetSRRegister(l_Controller_e) & (1U << USART_SR_TXE));
               } while ((RESET == l_FlagStatus_u32) && (FALSE == l_Timeout_b));

               if (para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioWordLength_e == USART_WORDLENGTH_9BITS)
               {
                    Dio_Hw_WriteDataToDR(l_Controller_e, (*para_Buffer_ptr & (uint8)0xFFU));
                    para_Buffer_ptr++;
               }
               else /* USART_WORDLENGTH_8BITS */
               {
                    Dio_Hw_WriteDataToDR(l_Controller_e, (*para_Buffer_ptr & (uint8)0xFFU));
                    para_Buffer_ptr++;
               }
          }

          Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b = FALSE;

          l_ReturnValue_u8 = E_OK;
     }

     /* Wait until TC flag is SET in SR Register */
     Mcu_Ip_StartTimeout(&l_StartTime_u32, &l_ElapsedTime_u32, &l_TimeoutTicks_u32, 100000);
     do
     {
          l_Timeout_b = Mcu_Ip_TimeoutExpired(&l_StartTime_u32, &l_ElapsedTime_u32, l_TimeoutTicks_u32);
          l_FlagStatus_u32 = (Dio_Hw_GetSRRegister(l_Controller_e) & (1U << USART_SR_TC));
     } while ((RESET == l_FlagStatus_u32) && (FALSE == l_Timeout_b));

     Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_TX_COMPLETE_CB_ID);

     return l_ReturnValue_u8;
}


/**
 *  @brief          This function to Sync Receive.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            Dio_IP_XXXXX
 *                  Design ID:         Dio_Ip_SyncReceive_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ip_EachConfigType *  
 *  @param[in]      para_DioConfig_ptr              Pointer to configuration structure.
 *  @arg            uint8 *
 *  @param[in]      para_Buffer_ptr                  Pointer to Buffer.
 *  @arg            uint32
 *  @param[in]      para_BufferSize_u32              Size of Bufer.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *
 **/
Std_ReturnType Dio_Ip_SyncReceive
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
)
{
     Std_ReturnType l_ReturnValue_u8 = E_OK;
     uint32 l_Counter_u32;
     uint32 l_StartTime_u32;
     uint32 l_ElapsedTime_u32;
     uint32 l_TimeoutTicks_u32;
     boolean l_Timeout_b = FALSE;
     uint32 l_FlagStatus_u32;
     Dio_Ip_ControllerType l_Controller_e;
     l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;

     Dio_IP_DEV_ASSERT(NULL_PTR != para_DioConfig_ptr);
     Dio_IP_DEV_ASSERT(NULL_PTR != para_Buffer_ptr);
     Dio_IP_DEV_ASSERT(0U != para_BufferSize_u32);

     if (TRUE == Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b)
     {
          l_ReturnValue_u8 = E_NOT_OK;
          Dio_Ip_s_c_Config_ptr->DioState_st.ErrorCode_e = Dio_ERRORCODE_BUSY_ERROR;
          Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_BUSY_ERROR_CB_ID);
     }
     else
     {
          Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b = TRUE;

          for (l_Counter_u32 = 0; l_Counter_u32 < para_BufferSize_u32; l_Counter_u32++)
          {
               /* Wait until RXNE flag be SET in SR Register */
               Mcu_Ip_StartTimeout(&l_StartTime_u32, &l_ElapsedTime_u32, &l_TimeoutTicks_u32, 100000000U);
               do
               {
                    l_Timeout_b = Mcu_Ip_TimeoutExpired(&l_StartTime_u32, &l_ElapsedTime_u32, l_TimeoutTicks_u32);
                    l_FlagStatus_u32 = (Dio_Hw_GetSRRegister(l_Controller_e) & (1U << USART_SR_RXNE));
               } while ((RESET == l_FlagStatus_u32) && (FALSE == l_Timeout_b));


               if (para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioWordLength_e == USART_WORDLENGTH_9BITS)
               {
                    if (para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioParityControl_e == USART_PARITY_DISABLE)
                    {
                         /* Don't care 9th bit */
                         *para_Buffer_ptr = (uint8)(Dio_Hw_ReadDataFromDR(l_Controller_e) & (uint8)0x1FFU);
                    }
                    else
                    {
                         *para_Buffer_ptr = (uint8)(Dio_Hw_ReadDataFromDR(l_Controller_e) & (uint8)0xFFU);
                    }

                    para_Buffer_ptr++;
               }
               else /* USART_WORDLENGTH_8BITS */
               {
                    if (para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioParityControl_e == USART_PARITY_DISABLE)
                    {
                         *para_Buffer_ptr = (uint8)((Dio_Hw_ReadDataFromDR(l_Controller_e)) & (uint8)0xFFU);
                    }
                    else
                    {
                         *para_Buffer_ptr = (uint8)(Dio_Hw_ReadDataFromDR(l_Controller_e) & (uint8)0x7FU);
                    }

                    para_Buffer_ptr++;
               }
          }

          Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_RX_COMPLETE_CB_ID);

          Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b = FALSE;

          l_ReturnValue_u8 = E_OK;
     }

     return l_ReturnValue_u8;
}


/**
 *  @brief          This function to Change Baudrate.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            Dio_IP_XXXXX
 *                  Design ID:         Dio_Ip_ChangeBaudrate_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ip_EachConfigType *  
 *  @param[in]      para_DioConfig_ptr              Pointer to configuration structure.
 *  @arg            Dio_Ip_BaudrateType
 *  @param[in]      para_Baudrate_e                  New baudrate.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *
 **/
Std_ReturnType Dio_Ip_ChangeBaudrate
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr,
    Dio_Ip_BaudrateType para_Baudrate_e
)
{
     Std_ReturnType l_ReturnValue_u8 = E_OK;
     Dio_IP_DEV_ASSERT(NULL_PTR != para_DioConfig_ptr);

     if (NULL_PTR != Dio_Ip_s_c_Config_ptr)
     {
          Dio_Ip_SetBaudrate(para_DioConfig_ptr, para_Baudrate_e);

          l_ReturnValue_u8 = E_OK;
     }
     else
     {
          l_ReturnValue_u8 = E_NOT_OK;

          (void)para_DioConfig_ptr;
          (void)para_Baudrate_e;
     }
     
     return l_ReturnValue_u8;
}


/**
 *  @brief          This function to Abort.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            Dio_IP_XXXXX
 *                  Design ID:         Dio_Ip_Abort_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ip_EachConfigType *  
 *  @param[in]      para_DioConfig_ptr              Pointer to configuration structure.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *
 **/
Std_ReturnType Dio_Ip_Abort
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr
)
{
     Std_ReturnType l_ReturnValue_u8 = E_OK;
     Dio_Ip_ControllerType l_Controller_e;
     l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;
     Dio_IP_DEV_ASSERT(NULL_PTR != para_DioConfig_ptr);

     if (NULL_PTR != Dio_Ip_s_c_Config_ptr)
     {
          Dio_Ip_s_c_Config_ptr->DioState_st.StateMachine_e = Dio_DRIVER_ABORT;
          Dio_Ip_s_c_Config_ptr->DioState_st.ErrorCode_e = Dio_ERRORCODE_ABORTED;

          /* Disable Dio */
          Dio_Hw_DisableDio(l_Controller_e);

          Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_ABORTED_CB_ID);

          l_ReturnValue_u8 = E_OK;
     }
     else
     {
          l_ReturnValue_u8 = E_NOT_OK;
          (void)para_DioConfig_ptr;
     }
     
     return l_ReturnValue_u8;
}


/**
 *  @brief          This function to DeInit.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            Dio_IP_XXXXX
 *                  Design ID:         Dio_Ip_DeInit_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ip_EachConfigType *  
 *  @param[in]      para_DioConfig_ptr              Pointer to configuration structure.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *
 **/
Std_ReturnType Dio_Ip_DeInit
(
    const Dio_Ip_EachConfigType *para_DioConfig_ptr
)
{
     Std_ReturnType l_ReturnValue_u8 = E_OK;
     Dio_Ip_ControllerType l_Controller_e;
     l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;
     Dio_IP_DEV_ASSERT(NULL_PTR != para_DioConfig_ptr);

     if (NULL_PTR != Dio_Ip_s_c_Config_ptr)
     {
          Dio_Ip_s_c_Config_ptr->DioState_st.StateMachine_e = Dio_DRIVER_UNINIT;
          Dio_Ip_s_c_Config_ptr->DioState_st.ErrorCode_e = Dio_ERRORCODE_NO_ERROR;

          Dio_Ip_s_c_Config_ptr = NULL_PTR;

          EventTxCompleteCallback = NULL_PTR;
          EventTxCompleteCallback = NULL_PTR;
          EventIdleCallback = NULL_PTR;
          EventCTSCallback = NULL_PTR;
          EventParityErrorCallback = NULL_PTR;
          EventFramingErrorCallback = NULL_PTR;
          EventNoiseDetectErrorCallback = NULL_PTR;
          EventOverrunErrorCallback = NULL_PTR;

          /* Disable Dio */
          Dio_Hw_DisableDio(l_Controller_e);

          l_ReturnValue_u8 = E_OK;
     }
     else
     {
          l_ReturnValue_u8 = E_NOT_OK;
          (void)l_Controller_e;
     }
     
     return l_ReturnValue_u8;
}

/**
 *  @brief          This function is call in ISR handle.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            Dio_IP_XXXXX
 *                  Design ID:         Dio_Ip_InterruptISRHandling_Activity
 *                  Sync/Async:        Asynchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            Dio_ConfigSetNumberType
 *  @param[in]      para_ConfigNumber_u32            Config setting ID from config structure to be set.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Dio_Ip_InterruptISRHandling
(
    const Dio_Ip_ConfigSetNumberType para_ConfigNumber_u32
)
{
     Dio_Ip_ControllerType l_Controller_e;
     const Dio_Ip_EachConfigType *para_DioConfig_ptr = &(*Dio_Ip_s_c_Config_ptr->c_ConfigSet_ptr)[para_ConfigNumber_u32];
     l_Controller_e = para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioController_e;
     uint32 l_SRRegister_u32 = Dio_Hw_GetSRRegister(l_Controller_e);
     uint32 l_CR1Register_u32 = Dio_Hw_GetCR1Register(l_Controller_e);
     uint32 l_CR3Register_u32 = Dio_Hw_GetCR3Register(l_Controller_e);
     uint16 *l_TempData_ptr;

     /* TXE (Transmit Data Register Empty) */
     if ((l_SRRegister_u32 & (1U << USART_SR_TXE)) && (l_CR1Register_u32 & (1U << USART_CR1_TXEIE)))
     {
          /* Interrupt because of TXE flag */
          if (TRUE == Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b)
          {
               if (Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxLength_u32 > 0U)
               {
                    if (para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioWordLength_e == USART_WORDLENGTH_9BITS)
                    {
                         Dio_Hw_WriteDataToDR(l_Controller_e, (*Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxBuff_ptr & (uint8)0xFFU));
                         Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxBuff_ptr++;
                         Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxLength_u32 -=1;
                    }
                    else /* USART_WORDLENGTH_8BITS */
                    {
                         Dio_Hw_WriteDataToDR(l_Controller_e, (*Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxBuff_ptr & (uint8)0xFFU));
                         Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxBuff_ptr++;
                         Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxLength_u32 -=1;
                    }
               }

               if (Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxLength_u32 == 0U)
               {
                    /* Clean TXEIE bit */
                    Dio_Hw_CleanTXEIE(l_Controller_e);
               }
          }
     }

     /* TC (Transmit Complete Flag) */
     if ((l_SRRegister_u32 & (1U << USART_SR_TC)) && (l_CR1Register_u32 & (1U << USART_CR1_TCIE)))
     {
          /* Interrupt because of TC flag, if TxLength is Zero, close transmit and call notification */
          if (TRUE == Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b)
          {
               if (Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxLength_u32 == 0U)
               {
                    /* Clean the TC Flag */
                    Dio_Hw_CleanTCFlag(l_Controller_e);

                    /* Clean the TCIE control bit */
                    Dio_Hw_CleanTCIEControlBit(l_Controller_e);

                    /* Reset Structure Interrupt */
                    Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsTxBusy_b = FALSE;
                    Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxBuff_ptr = NULL_PTR;
                    Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioTxLength_u32 = 0U;

                    #if (Dio_EVENTTXCOMPLETE_CBK_ENABLE == STD_ON)
                         if (EventTxCompleteCallback != NULL_PTR)
                         {
                              EventTxCompleteCallback(Dio_Ip_s_c_Config_ptr);
                         }    
                    #endif
               }
          }
     }

     /* RXNE (Received Data Ready to be Read) */
     if ((l_SRRegister_u32 & (1U << USART_SR_RXNE)) && (l_CR1Register_u32 & (1U << USART_CR1_RXNEIE)))
     {
          /* Interrupt because of RXNE flag */
          if (TRUE == Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b)
          {
               if (Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxLength_u32 > 0U)
               {
                    if (para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioWordLength_e == USART_WORDLENGTH_9BITS)
                    {
                         if (para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioParityControl_e == USART_PARITY_DISABLE)
                         {
                              /* Don't care 9th bit */
                              *Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxBuff_ptr = (uint8)(Dio_Hw_ReadDataFromDR(l_Controller_e) & (uint8)0x1FFU);
                         }
                         else
                         {
                              *Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxBuff_ptr = (uint8)(Dio_Hw_ReadDataFromDR(l_Controller_e) & (uint8)0xFFU);
                         }
                         Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxBuff_ptr++;
                         Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxLength_u32 -= 1U;
                    }
                    else /* USART_WORDLENGTH_8BITS */
                    {
                         if (para_DioConfig_ptr->c_Ip_ConfigDio_ptr.DioParityControl_e == USART_PARITY_DISABLE)
                         {
                              *Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxBuff_ptr = (uint8)(Dio_Hw_ReadDataFromDR(l_Controller_e) & (uint8)0xFFU);
                         }
                         else
                         {
                              *Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxBuff_ptr = (uint8)(Dio_Hw_ReadDataFromDR(l_Controller_e) & (uint8)0x7FU);
                         }

                         Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxBuff_ptr++;
                         Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxLength_u32 -= 1U;
                    }
               }

               if (Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.DioRxLength_u32 == 0U)
               {
                    /* Clean RXNE (Received Data Ready to be Read) */
                    Dio_Hw_CleanRXNEControlBit(l_Controller_e);

                    /* Clean RXNE Flag */
                    Dio_Hw_CleanRXNEFlag(l_Controller_e);

                    Dio_Ip_s_c_Config_ptr->DioStateStruct_ptr.IsRxBusy_b = FALSE;

                    #if (Dio_EVENTRXCOMPLETE_CBK_ENABLE == STD_ON)
                         if (EventRxCompleteCallback != NULL_PTR)
                         {
                              EventRxCompleteCallback(Dio_Ip_s_c_Config_ptr);
                         }    
                    #endif

               }
          }
     }

     /* CTS Flag (not use for Dio4 and Dio5) */
     if ((l_SRRegister_u32 & (1U << USART_SR_CTS)) && (l_CR3Register_u32 & (1U << USART_CR3_CTSE)))
     {
          /* Clean CTS Flag */
          Dio_Hw_CleanCTSFlag(l_Controller_e);

          #if (Dio_EVENTCTS_CBK_ENABLE == STD_ON)
               if (EventCTSCallback != NULL_PTR)
               {
                    EventCTSCallback(Dio_Ip_s_c_Config_ptr);
               }    
          #endif
     }

     /* IDLE Flag */
     if ((l_SRRegister_u32 & (1U << USART_SR_IDLE)) && (l_CR1Register_u32 & (1U << USART_CR1_IDLEIE)))
     {
          /* IDLE detection Flag */
          Dio_Hw_CleanIDLEFlag(l_Controller_e);

          #if (Dio_EVENTIDLE_CBK_ENABLE == STD_ON)
               if (EventIdleCallback != NULL_PTR)
               {
                    EventIdleCallback(Dio_Ip_s_c_Config_ptr);
               }    
          #endif
     }

     /* Other Error Flag */
     if (l_CR3Register_u32 & (1U << USART_CR3_EIE))
     {
          if (l_SRRegister_u32 & (1U << USART_SR_FE))
          {
               #if (Dio_EVENTFRAMINGERROR_CBK_ENABLE == STD_ON)
                    if (EventFramingErrorCallback != NULL_PTR)
                    {
                         EventFramingErrorCallback(Dio_Ip_s_c_Config_ptr);
                    }    
               #endif
          }

          if (l_SRRegister_u32 & (1U << USART_SR_NE))
          {
               #if (Dio_EVENTNOISEDETECTERROR_CBK_ENABLE == STD_ON)
                    if (EventNoiseDetectErrorCallback != NULL_PTR)
                    {
                         EventNoiseDetectErrorCallback(Dio_Ip_s_c_Config_ptr);
                    }    
               #endif
          }

          if (l_SRRegister_u32 & (1U << USART_SR_ORE))
          {
               #if (Dio_EVENTOVERRUNERROR_CBK_ENABLE == STD_ON)
                    if (EventOverrunErrorCallback != NULL_PTR)
                    {
                         EventOverrunErrorCallback(Dio_Ip_s_c_Config_ptr);
                    }    
               #endif
          }

          if (l_SRRegister_u32 & (1U << USART_SR_PE))
          {
               #if (Dio_EVENTPARITYERROR_CBK_ENABLE == STD_ON)
                    if (EventParityErrorCallback != NULL_PTR)
                    {
                         EventParityErrorCallback(Dio_Ip_s_c_Config_ptr);
                    }    
               #endif
          }
          
     }
}


/* Interrupt Handler */
#if (Dio_IP_ENABLE_INTERRUPT == STD_ON)
/**
*@brief  Interrupt of Dio_EventTxComplete_cbk.
*/
#if (Dio_EVENTTXCOMPLETE_CBK_ENABLE == STD_ON)
void Dio_EventTxComplete_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr)
{
     Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_TX_COMPLETE_CB_ID);
}
#endif

/**
*@brief  Interrupt of Dio_EventRxComplete_cbk.
*/
#if (Dio_EVENTRXCOMPLETE_CBK_ENABLE == STD_ON)
void Dio_EventRxComplete_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr)
{
     Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_RX_COMPLETE_CB_ID);
}
#endif

/**
*@brief  Interrupt of Dio_EventIdle_cbk.
*/
#if (Dio_EVENTIDLE_CBK_ENABLE == STD_ON)
void Dio_EventIdle_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr)
{
     Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_EVENT_IDLE_CB_ID);
}
#endif

/**
*@brief  Interrupt of Dio_EventCTS_cbk.
*/
#if (Dio_EVENTCTS_CBK_ENABLE == STD_ON)
void Dio_EventCTS_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr)
{
     Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_EVENT_CTS_CB_ID);
}
#endif

/**
*@brief  Interrupt of Dio_EventParityError_cbk.
*/
#if (Dio_EVENTPARITYERROR_CBK_ENABLE == STD_ON)
void Dio_EventParityError_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr)
{
     Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_PARITY_ERROR_CB_ID);
}
#endif

/**
*@brief  Interrupt of Dio_EventFramingError_cbk.
*/
#if (Dio_EVENTFRAMINGERROR_CBK_ENABLE == STD_ON)
void Dio_EventFramingError_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr)
{
     Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_TIMING_ERROR_CB_ID);
}
#endif

/**
*@brief  Interrupt of Dio_EventNoiseDetectError_cbk.
*/
#if (Dio_EVENTNOISEDETECTERROR_CBK_ENABLE == STD_ON)
void Dio_EventNoiseDetectError_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr)
{
     Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_NOISE_ERROR_CB_ID);
}
#endif

/**
*@brief  Interrupt of Dio_EventOverrunError_cbk.
*/
#if (Dio_EVENTOVERRUNERROR_CBK_ENABLE == STD_ON)
void Dio_EventOverrunError_cbk( Dio_Ip_ConfigType *para_DioConfig_ptr)
{
     Dio_IP_ERROR_ISR_NOTIFICATION(Dio_STATUS_OVERRUN_ERROR_CB_ID);
}
#endif

#endif

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/