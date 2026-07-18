/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: CDD_Dio.h
 *
 * Description: Implementation of CDD Dio High Level layer
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

#ifndef Dio_H
#define Dio_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/
#include "Dio_Ipc.h"
#include "CDD_Dio_Cfg.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/
/**
 * @brief  Dio_GetCoreID
 *
 */
#if (STD_ON == Dio_MULTICORE_SUPPORT)
    #define Dio_GetCoreID() ((uint8)OsIf_GetCoreID())
#else
    #define Dio_GetCoreID() ((uint8)0UL)
#endif


#if (Dio_DEV_ERROR_DETECT == STD_ON)
/*
* API is called with with a NULL value
*/
#define Dio_E_PARAM_POINTER             ((uint8)0x0A)

/*
* API service used without module initialization
*/
#define Dio_E_UNINIT                    ((uint8)0x0B)

/*
* API service called with wrong parameter
*/
#define Dio_E_PARAM_CONFIG              ((uint8)0x0C)

/*
* API service called with wrong init
*/
#define Dio_E_INIT_FAILED              ((uint8)0x0D)

/*
* API service called with wrong core
*/
#define Dio_E_WRONG_CORE               ((uint8)0x0E)

/*
* API service called with wrong config number DMA
*/
#define Dio_E_PARAM_CONFIG_NUMBER     ((uint8)0x0F)

/*
* API service called with wrong parameter
*/
#define Dio_E_INVALID_PARAMETER     ((uint8)0x1F)


/**
 * @brief  API service ID for Dio_Init function
 */
#define Dio_SID_INIT (uint8)(0U)

/**
 * @brief  API service ID for CDD_Dio_SetConfig function
 */
#define Dio_SID_SETCONFIG (uint8)(2U)

/**
 * @brief  API service ID for CDD_Dio_AsyncSend function
 */
#define Dio_SID_ASYNCSEND (uint8)(3U)

/**
 * @brief  API service ID for CDD_Dio_AsyncReceive function
 */
#define Dio_SID_ASYNCRECEIVE (uint8)(4U)

/**
 * @brief  API service ID for CDD_Dio_SyncSend function
 */
#define Dio_SID_SYNCSEND (uint8)(5U)

/**
 * @brief  API service ID for CDD_Dio_SyncReceive function
 */
#define Dio_SID_SYNCRECEIVE (uint8)(6U)

/**
 * @brief  API service ID for CDD_Dio_ChangeBaudrate function
 */
#define Dio_SID_CHANGEBAUDRATE (uint8)(7U)

/**
 * @brief  API service ID for Dio_GetErrorStatus function
 */
#define Dio_SID_GETERRORSTATUS (uint8)(8U)

/**
 * @brief  API service ID for CDD_Dio_Abort function
 */
#define Dio_SID_ABORT (uint8)(9U)

/**
 * @brief  API service ID for CDD_Dio_DeInit function
 */
#define Dio_SID_DEINIT (uint8)(10U)

/**
 * @brief  API service ID for Dio_GetVersionInfo function
 */
#define Dio_SID_GET_VERSION_INFO (uint8)(1U)


#endif

/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                      EXTERN
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL CONSTANTS
 **********************************************************************************************************************/
#if (STD_OFF == Dio_PRECOMPILE_SUPPORT)
    #define START_CONFIG_DATA_UNSPECIFIED
    #include "MemMap.h"
        CDD_Dio_CONFIG_EXT
    #define STOP_CONFIG_DATA_UNSPECIFIED
    #include "MemMap.h"
#endif
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
 *                  Service ID:        0x00
 *                  SRS ID:            SWS_Dio_HuLa_XXXXX
 *                  Design ID:         CDD_Dio_Init_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            CDD_Dio_ConfigType *  
 *  @param[in]      ConfigPtr         Pointer to configuration structure.
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
void CDD_Dio_Init
(
    CDD_Dio_ConfigType * ConfigPtr
);

/**
 *  @brief          This function sets config Dio.
 *
 *  @details
 *                  Service ID:        0x02
 *                  SRS ID:            SWS_Mcl_HuLa_XXXXX
 *                  Design ID:         CDD_Dio_SetConfig_Activity
 *                  Sync/Async:        Asynchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dio_ConfigSetNumberType
 *  @param[in]      para_ConfigNumber_u32            Config setting ID from config structure to be set.
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
void CDD_Dio_SetConfig
(
    Dio_ConfigSetNumberType para_ConfigNumber_u32
);

/**
 *  @brief          This function to Async Send.
 *
 *  @details
 *                  Service ID:        0x03
 *                  SRS ID:            SWS_Mcl_HuLa_XXXXX
 *                  Design ID:         CDD_Dio_AsyncSend_Activity
 *                  Sync/Async:        Asynchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dio_ConfigSetNumberType
 *  @param[in]      para_ConfigNumber_u32            Config setting ID from config structure to be set.
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
Std_ReturnType CDD_Dio_AsyncSend
(
    Dio_ConfigSetNumberType para_ConfigNumber_u32,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);

/**
 *  @brief          This function to Async Receive.
 *
 *  @details
 *                  Service ID:        0x04
 *                  SRS ID:            SWS_Mcl_HuLa_XXXXX
 *                  Design ID:         CDD_Dio_AsyncReceive_Activity
 *                  Sync/Async:        Asynchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dio_ConfigSetNumberType
 *  @param[in]      para_ConfigNumber_u32            Config setting ID from config structure to be set.
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
Std_ReturnType CDD_Dio_AsyncReceive
(
    Dio_ConfigSetNumberType para_ConfigNumber_u32,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);


/**
 *  @brief          This function to sync Send.
 *
 *  @details
 *                  Service ID:        0x05
 *                  SRS ID:            SWS_Mcl_HuLa_XXXXX
 *                  Design ID:         CDD_Dio_SyncSend_Activity
 *                  Sync/Async:        Asynchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dio_ConfigSetNumberType
 *  @param[in]      para_ConfigNumber_u32            Config setting ID from config structure to be set.
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
Std_ReturnType CDD_Dio_SyncSend
(
    Dio_ConfigSetNumberType para_ConfigNumber_u32,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);


/**
 *  @brief          This function to Sync Receive.
 *
 *  @details
 *                  Service ID:        0x06
 *                  SRS ID:            SWS_Mcl_HuLa_XXXXX
 *                  Design ID:         CDD_Dio_SyncReceive_Activity
 *                  Sync/Async:        Asynchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dio_ConfigSetNumberType
 *  @param[in]      para_ConfigNumber_u32            Config setting ID from config structure to be set.
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
Std_ReturnType CDD_Dio_SyncReceive
(
    Dio_ConfigSetNumberType para_ConfigNumber_u32,
    uint8* para_Buffer_ptr,
    uint32 para_BufferSize_u32
);

/**
 *  @brief          This function to Change Baudrate.
 *
 *  @details
 *                  Service ID:        0x07
 *                  SRS ID:            SWS_Mcl_HuLa_XXXXX
 *                  Design ID:         CDD_Dio_ChangeBaudrate_Activity
 *                  Sync/Async:        Asynchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dio_ConfigSetNumberType
 *  @param[in]      para_ConfigNumber_u32            Config setting ID from config structure to be set.
 *  @arg            Dio_BaudrateType
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
Std_ReturnType CDD_Dio_ChangeBaudrate
(
    Dio_ConfigSetNumberType para_ConfigNumber_u32,
    Dio_BaudrateType para_Baudrate_e
);


/**
 *  @brief          This function to get error code status.
 *
 *  @details
 *                  Service ID:        0x08
 *                  SRS ID:            SWS_Mcl_HuLa_XXXXX
 *                  Design ID:         Dio_GetErrorStatus_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            None
 *  @param[in]      None
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
Dio_ErrorCodeType Dio_GetErrorStatus(void);


/**
 *  @brief          This function to Abort.
 *
 *  @details
 *                  Service ID:        0x09
 *                  SRS ID:            SWS_Mcl_HuLa_XXXXX
 *                  Design ID:         CDD_Dio_Abort_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dio_ConfigSetNumberType
 *  @param[in]      para_ConfigNumber_u32            Config setting ID from config structure to be set.
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
Std_ReturnType CDD_Dio_Abort
(
    Dio_ConfigSetNumberType para_ConfigNumber_u32
);

/**
 *  @brief          This function to Deinit.
 *
 *  @details
 *                  Service ID:        0x0A
 *                  SRS ID:            SWS_Mcl_HuLa_XXXXX
 *                  Design ID:         CDD_Dio_DeInit_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dio_ConfigSetNumberType
 *  @param[in]      para_ConfigNumber_u32            Config setting ID from config structure to be set.
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
Std_ReturnType CDD_Dio_DeInit
(
    Dio_ConfigSetNumberType para_ConfigNumber_u32
);

#if (Dio_GETVERSION_INFO_API == STD_ON)
/**
 *  @brief          This function get version info.
 *
 *  @details
 *                  Service ID:        0x01
 *                  SRS ID:            SWS_Dio__HuLa_XXXXX
 *                  Design ID:         CDD_Dio_GetVersionInfo_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            Versioninfo *
 *  @param[in]      versioninfo        Pointer to where to store the version information of this module.
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
void CDD_Dio_GetVersionInfo
(
    Std_VersionInfoType * versioninfo
);
#endif /* (Dio_GETVERSION_INFO_API == STD_ON) */


#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* Dio_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
