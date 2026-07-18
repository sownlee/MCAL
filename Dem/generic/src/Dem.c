/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dem.c
 *
 * Description: Implementation of Dem High Level layer
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
#include "Dem.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define Dem_VENDOR_ID_C                     15
#define Dem_AR_RELEASE_MAJOR_VERSION_C      4
#define Dem_AR_RELEASE_MINOR_VERSION_C      4
#define Dem_AR_RELEASE_REVISION_VERSION_C   0
#define Dem_SW_MAJOR_VERSION_C              1
#define Dem_SW_MINOR_VERSION_C              0
#define Dem_SW_PATCH_VERSION_C              0
/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

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
Dem_ConfigType Dem_g_ErrBuffer[DEM_MAX_BUFFER];
#define STOP_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "MemMap.h"

#define START_VAR_CLEARED_32
#include "MemMap.h"
uint32 Dem_g_BufferIndex_u32 = 0;
#define STOP_VAR_CLEARED_32
#include "MemMap.h"

#define START_VAR_CLEARED_8_NO_CACHEABLE
#include "MemMap.h"
/* DEM byte array storing reported extended data */
uint8 Dem_au8ExtendedData[DEM_MAX_EXTENDED_DATA_LENGTH_U8]; 
#define STOP_VAR_CLEARED_8_NO_CACHEABLE
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
 *  @brief          Dem SetEventStatus
 *
 *  @details        Called by SW-Cs or BSW modules to report monitor status information to the Dem. BSW modules calling Dem_SetEventStatus can safely ignore the return value.
 *                  Service ID:        0x04
 *                  SRS ID:            SWS_Dem_00183
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dem_EventIdType    
 *  @param[in]      EventId            Identification of an event by assigned EventId.
 *  @arg            Dem_EventStatusType
 *  @param[in]      EventStatus        Monitor test result
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK               Set of event status was successful             
 *  @retval         E_NOT_OK           Event status setting or processing failed or could not be accepted.            
 *
 *  @note           None
 *
 **/
Std_ReturnType Dem_SetEventStatus( Dem_EventIdType EventId, Dem_EventStatusType EventStatus )
{
  Dem_ConfigType *DemBuffer = &Dem_g_ErrBuffer[Dem_g_BufferIndex_u32 % DEM_MAX_BUFFER];
  DemBuffer->Dem_EventId = EventId;
  DemBuffer->Dem_EventStatus = EventStatus;
  Dem_g_BufferIndex_u32++;

  return E_OK;
}

/**
 *  @brief          This function shall be used to report the Event Status from a monitoring function as soon as a new test result is available.
 *
 *  @details        This function has to be used if pre-extended data shall be logged at the time the event has been reported as "Failed".
 *                  In case the EvTestResult is "Passed" the parameters pPreExtData and PreExtDataSize will be ignored.
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Dem_EventIdType    
 *  @param[in]      Dem_EventIdRaw      Identification of the event 
 *  @arg            Dem_EventStatusType
 *  @param[in]      Dem_EventStatusRaw  DEM_EVENT_STATUS_PASSED or DEM_EVENT_STATUS_FAILED 
 *  @arg            const uint8 * const
 *  @param[in]      Dem_pui8_PreExtData Pointer to pre-extended data 
 *  @arg            uint8
 *  @param[in]      Dem_PreExtDataSize  Size of pre-extended data 
 *
 *  @return         Std_ReturnType     
 *  @retval         E_OK                Operation was successful     
 *  @retval         E_NOT_OK            Operation failed 
 *
 *  @note           NON-AUTOSAR DEM function
 *
 **/
Std_ReturnType Dem_ReportErrorStatusPreExtData(Dem_EventIdType Dem_EventIdRaw,Dem_EventStatusType Dem_EventStatusRaw,const uint8 * const Dem_pui8_PreExtData,uint8 Dem_PreExtDataSize)
{
    uint8 u8Counter;
    Std_ReturnType retVal = (Std_ReturnType)E_OK;

    Dem_ConfigType *DemBuffer = &Dem_g_ErrBuffer[Dem_g_BufferIndex_u32 % DEM_MAX_BUFFER];
    DemBuffer->Dem_EventId = Dem_EventIdRaw;
    DemBuffer->Dem_EventStatus = Dem_EventStatusRaw;
    Dem_g_BufferIndex_u32++;

    /* Store extended data only if Dem_EventStatus is set to DEM_EVENT_STATUS_FAILED */
    if ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED == Dem_EventStatusRaw)
    {
        if (Dem_PreExtDataSize <= DEM_MAX_EXTENDED_DATA_LENGTH_U8)
        {
            for(u8Counter=0; u8Counter<Dem_PreExtDataSize; u8Counter++)
            {
                Dem_au8ExtendedData[u8Counter] = Dem_pui8_PreExtData[u8Counter];
            }
        }
        else
        {
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    return retVal;
}

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/