/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Can_GeneralTypes.h
 *
 * Description: Implementation of Can_GeneralTypes IP Level layer
 *              
 * AutoSAR Version:         4.4.0
 *
 * Compiler: GCC IAR
 *
 * Revision:
 *              Version         Date                Change History
 *              1.0.0          07/04/2024           Initial version
 *
 **********************************************************************************************************************/

#ifndef CAN_GENERAL_TYPES_H
#define CAN_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES AND 
 **********************************************************************************************************************/
#include "PlatformTypes.h"
#include "ComStack_Cfg.h"

/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/
#define CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION      4
#define CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION      4
#define CAN_GENERALTYPES_AR_RELEASE_REVISION_VERSION   0
#define CAN_GENERALTYPES_SW_MAJOR_VERSION              1
#define CAN_GENERALTYPES_SW_MINOR_VERSION              0
#define CAN_GENERALTYPES_SW_PATCH_VERSION              0
/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/
#define CAN_BUSY                                (0x02)
/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

/* States that are used by the several ControllerMode functions. */
typedef enum 
{
   CAN_CS_UNINIT = 0x00,    /* CAN controller state UNINIT */
   CAN_CS_STARTED,          /* CAN controller state STARTED */
   CAN_CS_STOPPED,          /* CAN controller state STOPPE */
   CAN_CS_SLEEP             /* CAN controller state SLEEP */
} Can_ControllerStateType;

/* Error states of a CAN controller */
typedef enum 
{
   CAN_ERRORSTATE_ACTIVE = 0x00,    /* The CAN controller takes fully part in communication. */
   CAN_ERRORSTATE_PASSIVE,          /* The CAN controller takes part in communication, but does not send active error frames */
   CAN_ERRORSTATE_BUSOFF            /* The CAN controller does not take part in communication */
} Can_ErrorStateType;

/**
    CAN Transceiver modes.
    Operating modes of the CAN Transceiver Driver.
*/
typedef enum
{
    CANTRCV_TRCVMODE_NORMAL = 0U, /* Transceiver mode NORMAL */
    CANTRCV_TRCVMODE_STANDBY,     /* Transceiver mode STANDBY */
    CANTRCV_TRCVMODE_SLEEP        /* Transceiver mode SLEEP */
} CanTrcv_TrcvModeType;

/**        
    This type shall be used to control the CAN transceiver concerning wake up events and wake up notifications.     
    According to [SWS_CanTrcv_00164] it should be present in Can_GeneralTypes.h
*/
typedef enum
{
	CANTRCV_WUMODE_ENABLE = 0x00,   /* The notification for wakeup events is enabled on the addressed transceiver. */
	CANTRCV_WUMODE_DISABLE = 0x01,  /* The notification for wakeup events is disabled on the addressed transceiver. */
	CANTRCV_WUMODE_CLEAR = 0x02	 	/* A stored wakeup event is cleared on the addressed transceiver. */
} CanTrcv_TrcvWakeupModeType;

/*        
    This type denotes the wake up reason detected by the CAN transceiver in detail.
    According to [SWS_CanTrcv_00165] it should be present in Can_GeneralTypes.h
*/
typedef enum
{
	CANTRCV_WU_ERROR	 		= 0, /* Due to an error wake up reason was not detected. This value may only be reported when error was reported to DEM before. */
	CANTRCV_WU_NOT_SUPPORTED 	= 1, /* The transceiver does not support any information for the wake up reason.  */
	CANTRCV_WU_BY_BUS			= 2, /* The transceiver has detected, that the network has caused the wake up of the ECU. */
	CANTRCV_WU_INTERNALLY		= 3, /* The transceiver has detected, that the network has woken up by the ECU via a request to NORMAL mode. */
	CANTRCV_WU_RESET			= 4, /* The transceiver has detected, that the "wake up" is due to an ECU reset. */
	CANTRCV_WU_POWER_ON			= 5, /* The transceiver has detected, that the "wake up" is due to an ECU reset after power on. */
	CANTRCV_WU_BY_PIN			= 6, /* The transceiver has detected a wake-up event at one of the transceiver's pins (not at the CAN bus). */
	CANTRCV_WU_BY_SYSERR		= 7  /* The transceiver has detected, that the wake up of the ECU was caused by a HW related device failure. */
} CanTrcv_TrcvWakeupReasonType;

/* Represents the hardware object handles of a CAN hardware unit.
   For CAN hardware units with more than 255 HW objects use extended range. 
   Used by "Can_Write" function.
*/
typedef uint8 Can_HwHandleType;

/* Represents the Identifier of an L-PDU. The two most significant bits specify the frame type:
00 CAN message with Standard CAN ID
01 CAN FD frame with Standard CAN ID
10 CAN message with Extended CAN ID
11 CAN FD frame with Extended CAN ID
*/
typedef uint32 Can_IdType;

/* This type defines a data structure which clearly provides an Hardware Object
    Handle including its corresponding CAN Controller and therefore CanDrv as well as the specific CanId. 
*/
typedef struct 
{
  Can_IdType CanId;      /* Standard/Extended CAN ID of CAN LPDU */
  Can_HwHandleType hoh;  /* ID of the corresponding Hardware Object Range */
  uint8 ControllerId;    /* ControllerId provided by CanIf clearly identify the corresponding controlle */
} Can_HwType;

/* 
    This type unites PduId (swPduHandle), SduLength (length), SduData (sdu), and CanId (id) for any CAN L-SDU. 
    Type used to provide ID, DLC, SDU from CAN interface to CAN driver.
    HTH or HRH = ID+DLC+SDU.
*/
typedef struct {
  /* The L-PDU Handle = defined and placed inside the CanIf module layer.
    Each handle represents an L-PDU, which is a constant structure with information for Tx/Rx processing.
  */
  PduIdType swPduHandle;
  /* DLC = Data Length Code (part of L-PDU that describes the SDU length). */
  uint8 length;
  /* CAN L-PDU = Data Link Layer Protocol Data Unit. Consists of Identifier, DLC and Data(SDU)
    It is uint32 for CAN_EXTENDEDID=STD_ON, else is uint16.
  */
  Can_IdType id;
  /* CAN L-SDU = Link Layer Service Data Unit. Data that is transported inside the L-PDU. */
  uint8 *sdu;
} Can_PduType;

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

#ifdef __cplusplus
}
#endif

#endif /* CAN_GENERAL_TYPES_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
