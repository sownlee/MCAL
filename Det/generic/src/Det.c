/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Det.c
 *
 * Description: Implementation of Det High Level layer
 *              
 * AutoSAR Version:         4.4.0
 *
 * Compiler: GCC IAR
 *
 * Revision:
 *              Version         Date                Change History
 *              0.9.3          23/02/2024           Initial version
 *
 **********************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES
 **********************************************************************************************************************/
#include "Std_Types.h"
#include "Compiler.h"
#include "Det.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define DET_VENDOR_ID_C                     15
#define DET_AR_RELEASE_MAJOR_VERSION_C      4
#define DET_AR_RELEASE_MINOR_VERSION_C      4
#define DET_AR_RELEASE_REVISION_VERSION_C   0
#define DET_SW_MAJOR_VERSION_C              1
#define DET_SW_MINOR_VERSION_C              0
#define DET_SW_PATCH_VERSION_C              0
/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/
#ifndef DISABLE_CHECK_VERSION_AUTOSAR_EXTERNALMODULE
    /* Check if source file and DET header file are of the same vendor */
    #if (DET_VENDOR_ID_C != DET_VENDOR_ID)
        #error "Det.c and Det.h have different vendor ids"
    #endif

    /* Check if source file and DET header file are of the same Autosar version */
    #if ((DET_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
        (DET_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) || \
        (DET_AR_RELEASE_REVISION_VERSION_C != DET_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Det.c and Det.h are different"
    #endif

    /* Check if source file and DET header file are of the same Software version */
    #if ((DET_SW_MAJOR_VERSION_C != DET_SW_MAJOR_VERSION) || \
        (DET_SW_MINOR_VERSION_C != DET_SW_MINOR_VERSION) || \
        (DET_SW_PATCH_VERSION_C != DET_SW_PATCH_VERSION))
        #error "Software Version Numbers of Det.c and Det.h are different"
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

/***********************************************************************************************************************
 *                                                 GLOBAL VARIABLES
 **********************************************************************************************************************/
#define START_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "MemMap.h"

Det_ConfigType Det_g_DetErrBuffer[DET_MAX_BUFFER];

#define STOP_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "MemMap.h"


#define START_VAR_CLEARED_32
#include "MemMap.h"

uint32 Det_DetBuffIndex_u32 = 0;

#define STOP_VAR_CLEARED_32
#include "MemMap.h"
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
 *  @brief          Det init
 *
 *  @details        Service to initialize the Default Error Tracer
 *                  Service ID:        0x00
 *                  SRS ID:            SWS_Det_00008,SRS_BSW_00310,SRS_BSW_00358,SRS_BSW_00414
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Det_ConfigType*
 *  @param[in]      ConfigPtr         
 *
 *  @return         Void     
 *  @retval         None             
 *
 *  @note           None
 *
 **/
void Det_Init(const Det_ConfigType* ConfigPtr)
{
    (void)ConfigPtr;
}

/**
 *  @brief          Det Start
 *
 *  @details        Service to start the Default Error Tracer
 *                  Service ID:        0x02
 *                  SRS ID:            SWS_Det_00010,SRS_BSW_00310
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            void
 *  @param[in]      None         
 *
 *  @return         Void     
 *  @retval         None             
 *
 *  @note           None
 *
 **/
void Det_Start(void)
{
    
}

/**
 *  @brief          Service to report development errors 
 *
 *  @details        This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
 *                  Service ID:        0x01
 *                  SRS ID:            SWS_Det_00009,SRS_BSW_00310,SRS_Diag_04086,SRS_Diag_04085
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint16
 *  @param[in]      ModuleId          Module ID of Calling Module
 *  @arg            uint8
 *  @param[in]      InstanceId        The identifier of the index based instance of a module, starting from 0, If the module is a single instance module it shall pass 0 as the InstanceId.
 *  @arg            uint8
 *  @param[in]      ApiId             ID of API service in which error is detected
 *  @arg            uint8
 *  @param[in]      ErrorId           ID of detected development error
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK              Never returns a value, but has a return type for compatibility with services and hooks
 *
 *  @note           None
 *
 **/

Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
  Det_ConfigType *DetBuffer_ptr = &Det_g_DetErrBuffer[Det_DetBuffIndex_u32 % DET_MAX_BUFFER];

  DetBuffer_ptr->ModuleId = ModuleId;
  DetBuffer_ptr->InstanceId = InstanceId;
  DetBuffer_ptr->ApiId = ApiId;
  DetBuffer_ptr->ErrorId = ErrorId;
  Det_DetBuffIndex_u32++;

  return E_OK;
}

/**
 *  @brief          Service to report runtime errors. If a callout has been configured then this callout shall be called.
 *
 *  @details        This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
 *                  Service ID:        0x04
 *                  SRS ID:            SWS_Det_01001,SRS_BSW_00310,SRS_Diag_04086,SRS_Diag_04143
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint16
 *  @param[in]      ModuleId          Module ID of Calling Module
 *  @arg            uint8
 *  @param[in]      InstanceId        The identifier of the index based instance of a module, starting from 0, If the module is a single instance module it shall pass 0 as the InstanceId.
 *  @arg            uint8
 *  @param[in]      ApiId             ID of API service in which error is detected (defined in SWS of calling module)
 *  @arg            uint8
 *  @param[in]      RuntimeId           ID of detected runtime error (defined in SWS of calling module)
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK              Returns always E_OK (is required for services)
 *
 *  @note           None
 *
 **/
Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 RuntimeId)
{
  Det_ConfigType *DetBuffer_ptr = &Det_g_DetErrBuffer[Det_DetBuffIndex_u32 % DET_MAX_BUFFER];

  DetBuffer_ptr->ModuleId = ModuleId;
  DetBuffer_ptr->InstanceId = InstanceId;
  DetBuffer_ptr->ApiId = ApiId;
  DetBuffer_ptr->RuntimeId = RuntimeId;
  Det_DetBuffIndex_u32++;

  return E_OK;
}

/**
 *  @brief          Service to report transient faults. If a callout has been configured than this callout shall be called and the returned value of the callout shall be returned. Otherwise it returns immediately with E_OK  
 *
 *  @details        This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
 *                  Service ID:        0x05
 *                  SRS ID:            SWS_Det_01003,SRS_BSW_00310,SRS_Diag_04086,SRS_Diag_04144
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint16
 *  @param[in]      ModuleId          Module ID of Calling Module
 *  @arg            uint8
 *  @param[in]      InstanceId        The identifier of the index based instance of a module, starting from 0, If the module is a single instance module it shall pass 0 as the InstanceId.
 *  @arg            uint8
 *  @param[in]      ApiId             ID of API service in which transient fault is detected (defined in SWS of calling module)
 *  @arg            uint8
 *  @param[in]      FaultId           ID of detected transient fault (defined in SWS of calling module).
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK              If no callout exists it shall return E_OK, otherwise it shall return the value of the configured callout. In case several callouts are configured the logical or (sum) of the callout return values shall be returned. Rationale: since E_OK=0, E_OK will be only returned if all are E_OK, and for multiple error codes there is a good chance to detect several of them.
 *
 *  @note           None
 *
 **/
Std_ReturnType Det_ReportTransientFault(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 FaultId)
{
  Det_ConfigType *DetBuffer_ptr = &Det_g_DetErrBuffer[Det_DetBuffIndex_u32 % DET_MAX_BUFFER];

  DetBuffer_ptr->ModuleId = ModuleId;
  DetBuffer_ptr->InstanceId = InstanceId;
  DetBuffer_ptr->ApiId = ApiId;
  DetBuffer_ptr->FaultId = FaultId;
  Det_DetBuffIndex_u32++;

  return E_OK;
}

/**
 *  @brief          Det GetVersionInfo
 *
 *  @details        Returns the version information of this module.
 *                  Service ID:        0x03
 *                  SRS ID:            SWS_Det_00011,SRS_BSW_00310,SRS_BSW_00318
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            Std_VersionInfoType
 *  @param[in]      versioninfo          Pointer to where to store the version information of this module.
 *
 *  @return         Void     
 *  @retval         None             
 *
 *  @note           None
 *
 **/
void Det_GetVersionInfo( Std_VersionInfoType* versioninfo)
{
    #define DET_DEV_ERROR_DETECT STD_ON
    #if (STD_ON == DET_DEV_ERROR_DETECT)
        if (NULL_PTR == versioninfo)
        {
            (void)Det_ReportError((uint16)DET_MODULE_ID, DET_INSTANCE_ID, DET_GETVERSIONINFO_ID, DET_E_PARAM_POINTER);
        }
        else
    #endif /* (STD_ON == DET_DEV_ERROR_DETECT) */
        {
            versioninfo->vendorID         = (uint16)DET_VENDOR_ID;
            versioninfo->moduleID         = (uint16)DET_MODULE_ID;
            versioninfo->sw_major_version = (uint8)DET_SW_MAJOR_VERSION;
            versioninfo->sw_minor_version = (uint8)DET_SW_MINOR_VERSION;
            versioninfo->sw_patch_version = (uint8)DET_SW_PATCH_VERSION;
        }
}

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/