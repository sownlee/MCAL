/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dem_Stub.c
 *
 * Description: Implementation of Dem_Stub File
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
#include "Dem_Stub.h"
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
 *  @brief          Tests if an expected event has been reported to DEM
 *
 *  @details        This function will search the buffer of events, from the last event logged to the first one (from the newest to the oldest event), for the event ID&Status passed as parameter.
 *                  This function will also delete the event found ( (NumberOfEvents--) && (all events will be shifted with one position in the buffer))
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            Dem_EventIdType
 *  @param[in]      EventId            ID of the event reported
 *  @arg            Dem_EventStatusType
 *  @param[in]      EventStatus        Event status
 * 
 *  @return         boolean     
 *  @retval         True               if the event is found (the first one found) with the requested status    
 *  @retval         False              if that event is not found in the entire buffer with the requested status
 *
 *  @note           None
 *
 **/
boolean Dem_TestLastReportErrorStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
	boolean Result = 0U;
	sint32 CounterDown;
	uint32 CounterUp;

    Dem_ConfigType *DemBuffer_ptr = Dem_g_ErrBuffer;

	/* Search all events, from the last event logged to the first one */
	for(CounterDown = (Dem_g_BufferIndex_u32 - 1); (sint32)0 <= CounterDown; CounterDown--)
	{
	  /* If the specific event is found */
	  if((EventId == DemBuffer_ptr[CounterDown % DEM_MAX_BUFFER].Dem_EventId) && (EventStatus == DemBuffer_ptr[CounterDown % DEM_MAX_BUFFER].Dem_EventStatus))
	  {
		  /* Mark the result as found */
		  Result = 1;
		  /* Shift all the newest events with one position(discard the one that it is found) */
		  for(CounterUp = (uint32)CounterDown; CounterUp < (Dem_g_BufferIndex_u32 - 1);CounterUp++)
		  {
            DemBuffer_ptr[CounterUp % DEM_MAX_BUFFER].Dem_EventId = DemBuffer_ptr[(CounterUp+1) % DEM_MAX_BUFFER].Dem_EventId;
            DemBuffer_ptr[CounterUp % DEM_MAX_BUFFER].Dem_EventStatus = DemBuffer_ptr[(CounterUp+1) % DEM_MAX_BUFFER].Dem_EventStatus;
		  }
		  /* Update the Dem_numEventErrors (the event found is discarded) */
		  Dem_g_BufferIndex_u32--;
		  /* Terminate the search */
		  break;
	  }
	}

	return Result;
}


/**
 *  @brief          Tests if a FAILED or PREFAILED event has been reported to DEM
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            Void
 *  @param[in]      None
 * 
 *  @return         boolean     
 *  @retval         True               In case of NO event has been reported
 *  @retval         False              
 *
 *  @note           None
 *
 **/
boolean Dem_TestNoError(void) 
{
    boolean Result = 1U;
    uint32 Counter;

	for(Counter = 0;Counter < Dem_g_BufferIndex_u32; Counter++)
	{
        Dem_ConfigType *DetBuffer_ptr = &Dem_g_ErrBuffer[Counter];
	    if((DEM_EVENT_STATUS_FAILED == DetBuffer_ptr->Dem_EventId) || (DEM_EVENT_STATUS_PREFAILED == DetBuffer_ptr->Dem_EventId))
	    {
	        Result = 0U;
          /* terminate the search */
          break;
	    }
	}
	Dem_g_BufferIndex_u32 = 0;

	return Result;
}


/**
 *  @brief          Tests if a DEM extended data has been reported to DEM
 *
 *  @details        
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
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
 *  @return         boolean     
 *  @retval         True               True in case of expected extended data was found   
 *  @retval         False              
 *
 *  @note           None
 *
 **/
boolean Dem_TestLastReportErrorStatusPreExtData(Dem_EventIdType Dem_EventIdRaw,Dem_EventStatusType Dem_EventStatusRaw,uint8* Dem_pui8_PreExtData,uint8 Dem_PreExtDataSize )
{
	boolean RetValue = 1U;
	sint32 CounterDown;
	uint32 CounterUp;
	uint8  u8Counter;

    Dem_ConfigType *DemBuffer_ptr = Dem_g_ErrBuffer;

	/* Search all events, from the last event logged to the first one */
	for(CounterDown = (Dem_g_BufferIndex_u32 - 1); (sint32)0 <= CounterDown; CounterDown--)
	{
	  /* If the specific event is found */
	  if((Dem_EventIdRaw == DemBuffer_ptr[CounterDown % DEM_MAX_BUFFER].Dem_EventIdRaw) && (Dem_EventStatusRaw == DemBuffer_ptr[CounterDown % DEM_MAX_BUFFER].Dem_EventStatus))
	  {
		  /* If EventId and EventStatus match, check if data provided through pointer and length matches */
		for(u8Counter=0; u8Counter < Dem_PreExtDataSize; u8Counter++)
		{
			/* Skip over Dem extended data marked as not used */
			if (DEM_EXT_DATA_NOT_USED_U8 == Dem_pui8_PreExtData[u8Counter])
				continue;
			/* Check for match between expected and existing DEM extended data */
			if (Dem_pui8_PreExtData[u8Counter] != Dem_au8ExtendedData[u8Counter])
			{
				RetValue = (boolean)FALSE;
			}
		}
		  /* Shift all the newest events with one position(discard the one that it is found) */
		for(CounterUp = (uint32)CounterDown; CounterUp < (Dem_g_BufferIndex_u32 - 1);CounterUp++)
		{
            DemBuffer_ptr[CounterUp % DEM_MAX_BUFFER].Dem_EventId = DemBuffer_ptr[(CounterUp +1 ) % DEM_MAX_BUFFER].Dem_EventId ;
            DemBuffer_ptr[CounterUp % DEM_MAX_BUFFER].Dem_EventStatus = DemBuffer_ptr[(CounterUp +1 ) % DEM_MAX_BUFFER].Dem_EventStatus ;
		}
		/* update the Dem_numEventErrors (the event found is discarded) */
		Dem_g_BufferIndex_u32--;
	    /* Terminate the search */
		break;
	  }
	}

    /* Clear the stored information */
    for(u8Counter=0; u8Counter < DEM_MAX_EXTENDED_DATA_LENGTH_U8; u8Counter++)
    {
        Dem_au8ExtendedData[u8Counter] = 0x0U;
    }	

    return RetValue;
}

void Dem_ClearEvents(void)
{
    Dem_g_BufferIndex_u32 = 0U;
}

uint32 Dem_GetEventCount(void)
{
    return Dem_g_BufferIndex_u32;
}

/**
 *  @brief          It will return the event found on the index passed as parameter(IndexNumber)
 *
 *  @details        This function will return the event found on the index passed as parameter(IndexNumber)
 *                  This function will use the parameters 2 and 3(&EventId, &EventStatus) to return that entry.
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            N/A    
 *  @param[in]      None
 * 
 *  @return         boolean     
 *  @retval         True                True in case IndexNumber is OutOfRange
 *  @retval         False              
 *
 *  @note           None
 *
 **/
boolean Dem_GetEvent(uint32 IndexNumber, Dem_EventIdType* EventId, Dem_EventStatusType* EventStatus)
{
    boolean Result = 0;
    Dem_ConfigType *DetBuffer_ptr = Dem_g_ErrBuffer;

    if(IndexNumber < Dem_g_BufferIndex_u32)
    {
        *EventId = DetBuffer_ptr[IndexNumber].Dem_EventId;
        *EventStatus = DetBuffer_ptr[IndexNumber].Dem_EventStatus;
    }
    else
    {
        Result = 1;
    }
  return Result;
}

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/