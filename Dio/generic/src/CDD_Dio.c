/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: CDD_Dio.c
 *
 * Description: Implementation of CDD_Dio High Level layer
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

#include "CDD_Dio.h"
#if (Dio_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#include "CDD_Dio_VersionInfo.h"

/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
/* Common Published Information */
#define CDD_Dio_VENDOR_ID_C                      15U
#define CDD_Dio_MODULE_ID_C                      255U

/* AUTOSAR release version information */
#define CDD_Dio_AR_RELEASE_MAJOR_VERSION_C       4U
#define CDD_Dio_AR_RELEASE_MINOR_VERSION_C       4U 
#define CDD_Dio_AR_RELEASE_REVISION_VERSION_C    0U 

/* File version information */
#define CDD_Dio_SW_MAJOR_VERSION_C               1U 
#define CDD_Dio_SW_MINOR_VERSION_C               0U 
#define CDD_Dio_SW_PATCH_VERSION_C               0U 
/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/**
 * @brief Check if Dio.c and Dio_VersionInfo.h are of the same version
 */
#if ((CDD_Dio_SW_MAJOR_VERSION_C != CDD_Dio_SW_MAJOR_VERSION) || \
     (CDD_Dio_SW_MINOR_VERSION_C != CDD_Dio_SW_MINOR_VERSION) || \
     (CDD_Dio_SW_PATCH_VERSION_C != CDD_Dio_SW_PATCH_VERSION))
#error "Inconsistent Software Versions of Dio.c and Dio_VersionInfo.h"
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

#if (STD_ON == Dio_PRECOMPILE_SUPPORT)
#define START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/**
 * @brief  Extern variable to get data from generated config
 */
extern CDD_Dio_ConfigType CDD_Dio_g_c_Config_st;
#define STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#endif

/***********************************************************************************************************************
 *                                                  LOCAL VARIABLES
 **********************************************************************************************************************/

#define START_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/**
 * @brief  Static pointer to save config set of Dio driver when init.
 */
static CDD_Dio_ConfigType *CDD_Dio_s_c_ConfigPtr_ptr;

#define STOP_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/***********************************************************************************************************************
 *                                                 GLOBAL VARIABLES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                             LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define START_CODE
#include "MemMap.h"

static Std_ReturnType Dio_ValidateInitFunction
(
    uint8 para_CoreId_u8,
    CDD_Dio_ConfigType *para_c_Config_ptr
);

#define STOP_CODE
#include "MemMap.h"

/***********************************************************************************************************************
 *                                                  LOCAL FUNCTION
 **********************************************************************************************************************/


#define START_CODE
#include "MemMap.h"

/**
 *  @brief          The function will validate CDD_Dio_g_c_Config_st parameter.
 *
 *  @details        
 *                  Service ID:        None
 *                  SRS ID:            None
 *                  Design ID:         Dio_ValidateInitFunction_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            uint8   
 *  @param[in]      para_CoreId_u8     Core current
 *  @arg            CDD_Dio_ConfigType*   
 *  @param[in]      para_c_Config_ptr  Pointer to a CDD_Dio_ConfigType structure
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK               The function call is valid                               
 *  @retval         E_NOT_OK           The function call is invalid                             
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
static Std_ReturnType Dio_ValidateInitFunction
(
    uint8 para_CoreId_u8,
    CDD_Dio_ConfigType *para_c_Config_ptr
)
{
    Std_ReturnType l_ReturnValue_u8 = (Std_ReturnType)E_NOT_OK;
    CDD_Dio_ConfigType *l_Config_ptr = para_c_Config_ptr;

    #if (Dio_PRECOMPILE_SUPPORT == STD_OFF)
    if (NULL_PTR == l_Config_ptr)
    {
        l_ReturnValue_u8 = (Std_ReturnType)E_NOT_OK;
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_INIT, Dio_E_INIT_FAILED);
    }
    else
    {
        l_ReturnValue_u8 = (Std_ReturnType)E_OK;
    }
    #else /* Dio_PRECOMPILE_SUPPORT == STD_ON */
    
    if (NULL_PTR != l_Config_ptr)
    {
        l_ReturnValue_u8 = (Std_ReturnType)E_NOT_OK;
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_INIT, Dio_E_INIT_FAILED);
    }
    else
    {
        l_ReturnValue_u8 = (Std_ReturnType)E_OK;
    }
    #endif /* (Dio_PRECOMPILE_SUPPORT == STD_ON) */

    #if (STD_ON == Dio_PRECOMPILE_SUPPORT)
    /* Assign generated global variable in Pre-Compile to l_Config_ptr */
    l_Config_ptr = &CDD_Dio_g_c_Config_st;
    #endif

    if (E_OK == l_ReturnValue_u8)
    {
        /* Validate Core */
        #if (STD_ON == Dio_MULTICORE_SUPPORT)
            /* Check if exist core Id in core list */
            if ((uint8)1 != l_Config_ptr->CoreList_ptr[para_CoreId_u8])
            {
                l_ReturnValue_u8 = (Std_ReturnType)E_NOT_OK;
                /* Report Dio_E_WRONG_CORE error to DET */
                #if (STD_ON == Dio_DEV_ERROR_DETECT)
                    (void)Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_INIT, Dio_E_WRONG_CORE);
                #endif /* (STD_ON == Dio_DEV_ERROR_DETECT) */
            }
            else
            {
                l_ReturnValue_u8 = (Std_ReturnType)E_OK;
            }
        #else
            /* Check if don't exist core id in core list */
            if ((uint8)0 != l_Config_ptr->CoreList_ptr[para_CoreId_u8])
            {
                l_ReturnValue_u8 = (Std_ReturnType)E_NOT_OK;
                /* Report Dio_E_WRONG_CORE error to DET */
                #if (STD_ON == Dio_DEV_ERROR_DETECT)
                    (void)Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_INIT, Dio_E_WRONG_CORE);
                #endif /* (STD_ON == Dio_DEV_ERROR_DETECT) */
            }
            else
            {
                l_ReturnValue_u8 = (Std_ReturnType)E_OK;
            }
        #endif /*STD_ON == Dio_MULTICORE_SUPPORT*/
    }

    /* Avoid Misra violation */
    (void)para_CoreId_u8;
    (void)l_Config_ptr;

    return l_ReturnValue_u8;
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
)
{
    CDD_Dio_ConfigType *l_c_Config_ptr = NULL_PTR;
    uint8 l_CoreId_u8;
    Std_ReturnType l_ErrorStatus_u8;

    /* Get current core id */
    l_CoreId_u8 = Dio_GetCoreID();

    /* Validate ConfigPtr pointer parameter */
    l_ErrorStatus_u8 = Dio_ValidateInitFunction(l_CoreId_u8, ConfigPtr);

    if ((Std_ReturnType)E_OK == l_ErrorStatus_u8)
    {
        #if (STD_ON == Dio_PRECOMPILE_SUPPORT)
            /* Assign local pointer equal address of global generated pointer. */
            l_c_Config_ptr = &CDD_Dio_g_c_Config_st;
        #else
            /* Assign local pointer equal address of ConfigPtr parameter */
            l_c_Config_ptr = ConfigPtr;
        #endif /* (STD_ON == Dio_PRECOMPILE_SUPPORT) */

        /* Initialize Dio driver */
        (void)Dio_Ipc_Init(l_c_Config_ptr->CDDDioIpcConfig_ptr);
    }

    /* Save generated Dio config to global pointer contain information of Dio config set */
    CDD_Dio_s_c_ConfigPtr_ptr = l_c_Config_ptr;
}


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
)
{
    #if (Dio_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != CDD_Dio_s_c_ConfigPtr_ptr)
    {
        /* Check if para_ConfigNumber_u32 configuration is valid. */ 
        if (para_ConfigNumber_u32 < CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigNumber_u32)    
        {
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */
            SchM_Enter_Dio_Dio_EXCLUSIVE_AREA_00();
            Dio_Ipc_SetConfig(&(*CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigSet_ptr)[para_ConfigNumber_u32]);
            SchM_Exit_Dio_Dio_EXCLUSIVE_AREA_00();
    #if (Dio_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_SETCONFIG, Dio_E_PARAM_CONFIG_NUMBER);
        }
    }
    else
    {
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_SETCONFIG, Dio_E_UNINIT);
    }
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */
}


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
)
{
    Std_ReturnType l_ReturnValue_u8 = E_NOT_OK;

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != CDD_Dio_s_c_ConfigPtr_ptr)
    {
        /* Check if para_ConfigNumber_u32 configuration is valid. */ 
        if (para_ConfigNumber_u32 < CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigNumber_u32)    
        {
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

            if (NULL_PTR == para_Buffer_ptr)
            {
                #if (Dio_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ASYNCSEND, Dio_E_PARAM_POINTER);
                #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */
            }
            else if (0U == para_BufferSize_u32)
            {
                #if (Dio_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ASYNCSEND, Dio_E_INVALID_PARAMETER);
                #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                l_ReturnValue_u8 = Dio_Ipc_AsyncSend(&(*CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigSet_ptr)[para_ConfigNumber_u32], para_Buffer_ptr, para_BufferSize_u32);
            }

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ASYNCSEND, Dio_E_PARAM_CONFIG_NUMBER);
        }
    }
    else
    {
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ASYNCSEND, Dio_E_UNINIT);
    }
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

    return l_ReturnValue_u8;
}


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
)
{
    Std_ReturnType l_ReturnValue_u8 = E_NOT_OK;

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != CDD_Dio_s_c_ConfigPtr_ptr)
    {
        /* Check if para_ConfigNumber_u32 configuration is valid. */ 
        if (para_ConfigNumber_u32 < CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigNumber_u32)    
        {
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

            if (NULL_PTR == para_Buffer_ptr)
            {
                #if (Dio_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ASYNCRECEIVE, Dio_E_PARAM_POINTER);
                #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */
            }
            else if (0U == para_BufferSize_u32)
            {
                #if (Dio_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ASYNCRECEIVE, Dio_E_INVALID_PARAMETER);
                #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                l_ReturnValue_u8 = Dio_Ipc_AsyncReceive(&(*CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigSet_ptr)[para_ConfigNumber_u32], para_Buffer_ptr, para_BufferSize_u32);
            }

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ASYNCRECEIVE, Dio_E_PARAM_CONFIG_NUMBER);
        }
    }
    else
    {
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ASYNCRECEIVE, Dio_E_UNINIT);
    }
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

    return l_ReturnValue_u8;
}


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
)
{
    Std_ReturnType l_ReturnValue_u8 = E_NOT_OK;

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != CDD_Dio_s_c_ConfigPtr_ptr)
    {
        /* Check if para_ConfigNumber_u32 configuration is valid. */ 
        if (para_ConfigNumber_u32 < CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigNumber_u32)    
        {
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

            if (NULL_PTR == para_Buffer_ptr)
            {
                #if (Dio_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_SYNCSEND, Dio_E_PARAM_POINTER);
                #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */
            }
            else if (0U == para_BufferSize_u32)
            {
                #if (Dio_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_SYNCSEND, Dio_E_INVALID_PARAMETER);
                #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                l_ReturnValue_u8 = Dio_Ipc_SyncSend(&(*CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigSet_ptr)[para_ConfigNumber_u32], para_Buffer_ptr, para_BufferSize_u32);
            }

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_SYNCSEND, Dio_E_PARAM_CONFIG_NUMBER);
        }
    }
    else
    {
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_SYNCSEND, Dio_E_UNINIT);
    }
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

    return l_ReturnValue_u8;
}


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
)
{
    Std_ReturnType l_ReturnValue_u8 = E_NOT_OK;

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != CDD_Dio_s_c_ConfigPtr_ptr)
    {
        /* Check if para_ConfigNumber_u32 configuration is valid. */ 
        if (para_ConfigNumber_u32 < CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigNumber_u32)    
        {
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

            if (NULL_PTR == para_Buffer_ptr)
            {
                #if (Dio_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_SYNCRECEIVE, Dio_E_PARAM_POINTER);
                #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */
            }
            else if (0U == para_BufferSize_u32)
            {
                #if (Dio_DEV_ERROR_DETECT == STD_ON)
                (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_SYNCRECEIVE, Dio_E_INVALID_PARAMETER);
                #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                l_ReturnValue_u8 = Dio_Ipc_SyncReceive(&(*CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigSet_ptr)[para_ConfigNumber_u32], para_Buffer_ptr, para_BufferSize_u32);
            }

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_SYNCRECEIVE, Dio_E_PARAM_CONFIG_NUMBER);
        }
    }
    else
    {
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_SYNCRECEIVE, Dio_E_UNINIT);
    }
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

    return l_ReturnValue_u8;
}


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
)
{
    Std_ReturnType l_ReturnValue_u8 = E_NOT_OK;

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != CDD_Dio_s_c_ConfigPtr_ptr)
    {
        /* Check if para_ConfigNumber_u32 configuration is valid. */ 
        if (para_ConfigNumber_u32 < CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigNumber_u32)    
        {
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

        l_ReturnValue_u8 = Dio_Ipc_ChangeBaudrate(&(*CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigSet_ptr)[para_ConfigNumber_u32], para_Baudrate_e);

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_CHANGEBAUDRATE, Dio_E_PARAM_CONFIG_NUMBER);
        }
    }
    else
    {
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_CHANGEBAUDRATE, Dio_E_UNINIT);
    }
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

    return l_ReturnValue_u8;
}


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
Dio_ErrorCodeType Dio_GetErrorStatus(void)
{
    Dio_ErrorCodeType l_ErrorCode_e = Dio_ERRORCODE_NO_ERROR;

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != CDD_Dio_s_c_ConfigPtr_ptr)
    {
        l_ErrorCode_e = CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->DioState_st.ErrorCode_e;
    }
    else
    {
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_GETERRORSTATUS, Dio_E_UNINIT);
    }
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

    return l_ErrorCode_e;
}


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
)
{
    Std_ReturnType l_ReturnValue_u8 = E_NOT_OK;

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != CDD_Dio_s_c_ConfigPtr_ptr)
    {
        /* Check if para_ConfigNumber_u32 configuration is valid. */ 
        if (para_ConfigNumber_u32 < CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigNumber_u32)    
        {
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

        l_ReturnValue_u8 = Dio_Ipc_Abort(&(*CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigSet_ptr)[para_ConfigNumber_u32]);

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ABORT, Dio_E_PARAM_CONFIG_NUMBER);
        }
    }
    else
    {
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ABORT, Dio_E_UNINIT);
    }
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

    return l_ReturnValue_u8;
}


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
)
{
    Std_ReturnType l_ReturnValue_u8 = E_NOT_OK;

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != CDD_Dio_s_c_ConfigPtr_ptr)
    {
        /* Check if para_ConfigNumber_u32 configuration is valid. */ 
        if (para_ConfigNumber_u32 < CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigNumber_u32)    
        {
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

        l_ReturnValue_u8 = Dio_Ipc_DeInit(&(*CDD_Dio_s_c_ConfigPtr_ptr->CDDDioIpcConfig_ptr->DioIpConfig_ptr->c_ConfigSet_ptr)[para_ConfigNumber_u32]);

    #if (Dio_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ABORT, Dio_E_PARAM_CONFIG_NUMBER);
        }
    }
    else
    {
        (void) Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_ABORT, Dio_E_UNINIT);
    }
    #endif /* (Dio_DEV_ERROR_DETECT == STD_ON) */

    return l_ReturnValue_u8;
}

#if (Dio_GETVERSION_INFO_API == STD_ON)
/**
 *  @brief          This function to get version info.
 *
 *  @details
 *                  Service ID:        0x01
 *                  SRS ID:            SWS_Dio_HuLa_XXXXX
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
)
{
     uint8 l_InstanceId = 0x0U;

    /* Validate Versioninfo parameter */
    if (NULL_PTR != versioninfo)
    {
        /* Copy version information to output pointer */
        (versioninfo)->sw_major_version = (uint8)CDD_Dio_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)CDD_Dio_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)CDD_Dio_SW_PATCH_VERSION;
        (versioninfo)->vendorID         = (uint16)CDD_Dio_VENDOR_ID;
        (versioninfo)->moduleID         = (uint16)CDD_Dio_MODULE_ID;
    }
    else
    {
          #if (STD_ON == Dio_DEV_ERROR_DETECT)
               /* Report Dio_E_PARAM_POINTER error to DET */
               (void)Det_ReportError((uint16)CDD_Dio_MODULE_ID, Dio_INSTANCE, Dio_SID_GET_VERSION_INFO, Dio_E_PARAM_POINTER);
           #endif /* (STD_ON == Dio_DEV_ERROR_DETECT) */
    }
}
#endif /* (Dio_GETVERSION_INFO_API == STD_ON) */


#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/