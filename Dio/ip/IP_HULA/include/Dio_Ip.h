/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Ip.h
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

#ifndef Dio_IP_H
#define Dio_IP_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "Dio_Hw.h"
#include "Dio_Ip_Cfg.h"
#include "SchM_Dio.h"
#include "Os.h"

#include "Dio_Ip_irq.h"

#if (Dio_IP_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif /* (Dio_IP_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON) */

#if (Dio_IP_ENABLE_DMA == STD_ON)
#include "CDD_Mcl.h"
#endif /* (Dio_IP_ENABLE_DMA == STD_ON) */



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

#define START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/**
 * @brief   Export IPC configurations.
 */
Dio_IP_CONFIG_EXT
#define STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

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
);

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
);

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
);

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
);


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
);


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
);

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
);

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
);

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
);

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
);

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* Dio_IP_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
