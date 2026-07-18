/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Ipc.h
 *
 * Description: Implementation of Dio_Ipc IPC Level layer
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

#ifndef Dio_IPC_H
#define Dio_IPC_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "Dio_Ip.h"
#include "Dio_Ipc_Cfg.h"

/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/

#define START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/**
 * @brief   Export IPC configurations.
 */
Dio_IPC_CONFIG_EXT
#define STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

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
 *  @brief          Initializes the Dio Driver module.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            N/A
 *                  Design ID:         Dio_Ipc_Init_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dio_Ipc_ConfigType *  
 *  @param[in]      para_DioIpcConfig_ptr         Pointer to configuration structure.
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
void Dio_Ipc_Init
(
    Dio_Ipc_ConfigType *para_DioIpcConfig_ptr
);

/**
 *  @brief          This function sets config Dio.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            N/A
 *                  Design ID:         Dio_Ipc_SetConfig_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ipc_EachConfigType *
 *  @param[in]      para_DioConfig_ptr            Config structure to be set.
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
void Dio_Ipc_SetConfig
(
    const Dio_Ipc_EachConfigType *para_DioConfig_ptr
);

/**
 *  @brief          This function to Async Send.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            N/A
 *                  Design ID:         Dio_Ipc_AsyncSend_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ipc_EachConfigType*
 *  @param[in]      para_DioConfig_ptr              Pointer to config set.
 *  @arg            uint8*
 *  @param[in]      para_Buffer_ptr                  Pointer to Buffer.
 *  @arg            uint32
 *  @param[in]      para_BufferSize_u32              Size of Bufer.
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
Std_ReturnType Dio_Ipc_AsyncSend
(
    const Dio_Ipc_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);

/**
 *  @brief          This function to Async Receive.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            N/A
 *                  Design ID:         Dio_Ipc_AsyncReceive_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ipc_EachConfigType*
 *  @param[in]      para_DioConfig_ptr              Pointer to config set.
 *  @arg            uint8*
 *  @param[in]      para_Buffer_ptr                  Pointer to Buffer.
 *  @arg            uint32
 *  @param[in]      para_BufferSize_u32              Size of Bufer.
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
Std_ReturnType Dio_Ipc_AsyncReceive
(
    const Dio_Ipc_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);


/**
 *  @brief          This function to Sync Send.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            N/A
 *                  Design ID:         Dio_Ipc_SyncSend_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ipc_EachConfigType*
 *  @param[in]      para_DioConfig_ptr              Pointer to config set.
 *  @arg            uint8*
 *  @param[in]      para_Buffer_ptr                  Pointer to Buffer.
 *  @arg            uint32
 *  @param[in]      para_BufferSize_u32              Size of Bufer.
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
Std_ReturnType Dio_Ipc_SyncSend
(
    const Dio_Ipc_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);


/**
 *  @brief          This function to Sync Receive.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            N/A
 *                  Design ID:         Dio_Ipc_SyncReceive_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ipc_EachConfigType*
 *  @param[in]      para_DioConfig_ptr              Pointer to config set.
 *  @arg            uint8*
 *  @param[in]      para_Buffer_ptr                  Pointer to Buffer.
 *  @arg            uint32
 *  @param[in]      para_BufferSize_u32              Size of Bufer.
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
Std_ReturnType Dio_Ipc_SyncReceive
(
    const Dio_Ipc_EachConfigType *para_DioConfig_ptr,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);

/**
 *  @brief          This function to Change Baudrate.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            N/A
 *                  Design ID:         Dio_Ipc_ChangeBaudrate_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ipc_EachConfigType*
 *  @param[in]      para_DioConfig_ptr              Pointer to config set.
 *  @arg            Dio_Ipc_BaudrateType
 *  @param[in]      para_Baudrate_e                  New baudrate.
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
Std_ReturnType Dio_Ipc_ChangeBaudrate
(
    const Dio_Ipc_EachConfigType *para_DioConfig_ptr,
    Dio_Ipc_BaudrateType para_Baudrate_e
);

/**
 *  @brief          This function to Abort.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            N/A
 *                  Design ID:         Dio_Ipc_Abort_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ipc_EachConfigType*
 *  @param[in]      para_DioConfig_ptr              Pointer to config set.
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
Std_ReturnType Dio_Ipc_Abort
(
    const Dio_Ipc_EachConfigType *para_DioConfig_ptr
);

/**
 *  @brief          This function to DeInit.
 *
 *  @details
 *                  Service ID:        N/A
 *                  SRS ID:            N/A
 *                  Design ID:         Dio_Ipc_DeInit_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            const Dio_Ipc_EachConfigType*
 *  @param[in]      para_DioConfig_ptr              Pointer to config set.
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
Std_ReturnType Dio_Ipc_DeInit
(
    const Dio_Ipc_EachConfigType *para_DioConfig_ptr
);

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* Dio_IPC_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
