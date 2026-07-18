/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dem.h
 *
 * Description: Implementation of DEM High Level layer
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

#ifndef DEM_H
#define DEM_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES AND 
 **********************************************************************************************************************/
#include "Std_Types.h"
#include "Dem_IntErrId.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define DEM_VENDOR_ID                    15
#define DEM_MODULE_ID                    54
#define DEM_AR_RELEASE_MAJOR_VERSION     4
#define DEM_AR_RELEASE_MINOR_VERSION     4
#define DEM_AR_RELEASE_REVISION_VERSION  0
#define DEM_SW_MAJOR_VERSION             1
#define DEM_SW_MINOR_VERSION             0
#define DEM_SW_PATCH_VERSION             0
/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/
#ifndef DISABLE_CHECK_VERSION_AUTOSAR_EXTERNALMODULE
    /* Check AutoSar Version Numbers of DEM and StandardTypes.h */
    #if ((DEM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || (DEM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of DEM and StandardTypes.h are different"
    #endif
#endif
/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/
#define DEM_MAX_BUFFER                      (uint8)(100U)

/* Max length value of extended data kept by Dem when Dem_ReportErrorStatusPreExtData() API is called */
#define DEM_MAX_EXTENDED_DATA_LENGTH_U8     (uint8)(100U)

#define DEM_EVENT_STATUS_PASSED             (Dem_EventStatusType)0x00
#define DEM_EVENT_STATUS_FAILED             (Dem_EventStatusType)0x01
#define DEM_EVENT_STATUS_PREPASSED          (Dem_EventStatusType)0x02
#define DEM_EVENT_STATUS_PREFAILED          (Dem_EventStatusType)0x03

/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

typedef uint8 Dem_EventStatusType;
typedef uint16 Dem_EventIdType;

/**
 * @brief   strucure used to configure filters and store log data, using 0xff for a filter item means don't care
 * 
 * @details SRS ID: 
 *          Design ID: 
 */
typedef struct Dem_ConfigType_t
{
  Dem_EventIdType Dem_EventId;
  Dem_EventStatusType Dem_EventStatus;
  Dem_EventIdType Dem_EventIdRaw;
}Dem_ConfigType;
/***********************************************************************************************************************
 *                                                      EXTERN
 **********************************************************************************************************************/
#define START_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "MemMap.h"
extern Dem_ConfigType Dem_g_ErrBuffer[DEM_MAX_BUFFER];
#define STOP_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "MemMap.h"


#define START_VAR_CLEARED_32_NO_CACHEABLE
#include "MemMap.h"
extern uint32 Dem_g_BufferIndex_u32;
#define STOP_VAR_CLEARED_32_NO_CACHEABLE
#include "MemMap.h"


#define START_VAR_CLEARED_8_NO_CACHEABLE
#include "MemMap.h"
/* DEM byte array storing reported extended data */
extern uint8 Dem_au8ExtendedData[DEM_MAX_EXTENDED_DATA_LENGTH_U8]; 
#define STOP_VAR_CLEARED_8_NO_CACHEABLE
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
extern Std_ReturnType Dem_SetEventStatus( Dem_EventIdType EventId, Dem_EventStatusType EventStatus );
extern Std_ReturnType Dem_ReportErrorStatusPreExtData(Dem_EventIdType Dem_EventIdRaw,Dem_EventStatusType Dem_EventStatusRaw,const uint8 * const Dem_pui8_PreExtData,uint8 Dem_PreExtDataSize);
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

#endif /* DEM_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
