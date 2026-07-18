/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Det.h
 *
 * Description: Implementation of DET High Level layer
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

#ifndef DET_H
#define DET_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES AND 
 **********************************************************************************************************************/
#include "Std_Types.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define DET_VENDOR_ID                    15
#define DET_MODULE_ID                    15
#define DET_AR_RELEASE_MAJOR_VERSION     4
#define DET_AR_RELEASE_MINOR_VERSION     4
#define DET_AR_RELEASE_REVISION_VERSION  0
#define DET_SW_MAJOR_VERSION             1
#define DET_SW_MINOR_VERSION             0
#define DET_SW_PATCH_VERSION             0
/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/
#ifndef DISABLE_CHECK_VERSION_AUTOSAR_EXTERNALMODULE
    /* Check AutoSar Version Numbers of Det and StandardTypes.h */
    #if ((DET_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || (DET_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Det and StandardTypes.h are different"
    #endif
#endif
/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/
#define DET_MAX_BUFFER                   (uint8)(100U)

/**
 * @brief   The DET shall notify the error DET_E_PARAM_POINTER to all functions configured in callouts in case a null pointer error occurs in Det_GetVersionInfo.
 * 
 * @details SRS ID: SWS_Det_00052
 *          Design ID: 
 */
#define DET_E_PARAM_POINTER              ((uint8)0x20)

/**
 * @brief   Instance ID of the DET driver.
 * 
 * @details SRS ID: 
 *          Design ID: 
 */
#define DET_INSTANCE_ID                  ((uint8)0x00)

/**
 * @brief   API service ID for DET @p Get_Version() Info function.
 * 
 * @details SRS ID: 
 *          Design ID: 
 */
#define DET_GETVERSIONINFO_ID                  ((uint8)0x03)

/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

/**
 * @brief   Configuration data structure of the Det module.
 * 
 * @details SRS ID: SWS_Det_00210,SRS_BSW_00414
 *          Design ID: 
 */
typedef struct Det_ConfigType_t { 
    VAR(uint16, DET_VAR) ModuleId;
    VAR(uint8, DET_VAR) InstanceId;
    VAR(uint8, DET_VAR) ApiId;
    VAR(uint8, DET_VAR) ErrorId;
    VAR(uint8, DET_VAR) FaultId;
    VAR(uint8, DET_VAR) RuntimeId;
} Det_ConfigType;
/***********************************************************************************************************************
 *                                                      EXTERN
 **********************************************************************************************************************/
#define START_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "MemMap.h"

extern VAR(Det_ConfigType, DET_VAR) Det_g_DetErrBuffer[DET_MAX_BUFFER];

#define STOP_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "MemMap.h"


#define START_VAR_CLEARED_32_NO_CACHEABLE
#include "MemMap.h"

extern VAR(uint32, DET_VAR)        Det_DetBuffIndex_u32;

#define STOP_VAR_CLEARED_32_NO_CACHEABLE
#include "MemMap.h"
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
#define START_CODE
#include "MemMap.h"

extern FUNC(void, DET_CODE) Det_Init(const Det_ConfigType* ConfigPtr);
extern FUNC(void, DET_CODE) Det_Start(void);
extern FUNC(Std_ReturnType, DET_CODE) Det_ReportError(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) ErrorId);
extern FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) RuntimeId);
extern FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) FaultId);

#define STOP_CODE
#include "MemMap.h"
/***********************************************************************************************************************
 *                                                  LOCAL FUNCTION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  GLOBAL FUNCTION
 **********************************************************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* DET_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
