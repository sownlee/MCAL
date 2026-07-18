#ifndef LIN_GENERAL_TYPES_H
#define LIN_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

#include "PlatformTypes.h"

/**
* @brief          Checksum models for the LIN Frame.
* @details        This type is used to specify the Checksum model to be
*                 used for the LIN Frame.
* @implements     Lin_FrameCsModelType_enumeration
*/
typedef enum
{
LIN_ENHANCED_CS,    /* Enhanced checksum model.*/
LIN_CLASSIC_CS      /* Classic checksum model.*/
} Lin_FrameCsModelType;

/**
* @brief          Frame response types.
* @details        This type is used to specify whether the frame
*                 processor is required to transmit the response
*                 part of the LIN frame.
* @implements     Lin_FrameResponseType_enumeration
*/

typedef enum
{
  LIN_FRAMERESPONSE_TX = 0,     /* Response is generated from this (master) node.*/
  LIN_FRAMERESPONSE_RX,         /* Response is generated from a remote slave node.*/
  LIN_FRAMERESPONSE_IGNORE      /* Response is generated from one slave to another slave.*/
                                /* For the master the response will be anonymous, it does not have to receive the response.*/
} Lin_FrameResponseType;

/**
* @brief          LIN Frame and Channel states operation.
* @details        LIN operation states for a LIN channel or frame, as returned
*                 by the API service Lin_GetStatus().
*                 part of the LIN frame.
* @implements     Lin_StatusType_enumeration
*/
typedef enum
{
  LIN_NOT_OK = 0,     /* Development or production error
                                  occurred.*/
  LIN_TX_OK,          /* Successful transmission.*/
  LIN_TX_BUSY,        /* Ongoing transmission (Header or
                                  Response).*/
  LIN_TX_HEADER_ERROR,/* Erroneous header transmission such
                                  as:
                                    - Mismatch between sent and read
                                      back data
                                    - Identifier parity error
                                    - Physical bus error.*/
  LIN_TX_ERROR,       /* Erroneous transmission such as:
                                    - Mismatch between sent and read
                                      back data
                                    - Physical bus error.*/
  LIN_RX_OK,          /* Reception of correct response.*/
  LIN_RX_BUSY,        /* Ongoing reception:
                                  at least one response byte has
                                  been received, but the checksum
                                  byte has not been received.*/
  LIN_RX_ERROR,       /* Erroneous reception such as:
                                    - Framing error
                                    - Overrun error
                                    - Checksum error
                                    - Short response.*/
  LIN_RX_NO_RESPONSE, /* No response byte has been received
                                  so far.*/
                      /* This is a mess !!
                                  Frame status is mixed with channel
                                  status but i kept it here only
                                  because of LIN168.*/
  LIN_OPERATIONAL,    /* Normal operation;
                                    - The related LIN channel is ready
                                      to transmit next header
                                    - No data from previous frame
                                      available (e.g. after
                                      initialization).*/
  LIN_CH_SLEEP        /* Sleep mode operation;
                                    - In this mode wake-up detection
                                      from slave nodes is enabled.*/
} Lin_StatusType;


/**
* @brief          LIN Slave error type.
* @details        This type represents the slave error types that are detected during header reception
*                 and response transmission / reception
* @implements     Lin_SlaveErrorType_enum
*/

typedef enum
{
    LIN_ERR_HEADER = 0, /* Error in header */

    LIN_ERR_RESP_STOPBIT, /* Framing error in response */

    LIN_ERR_RESP_CHKSUM, /* Checksum error */

    LIN_ERR_RESP_DATABIT, /* Monitoring error of transmitted data bit in response */

    LIN_ERR_NO_RESP, /* No response */

    LIN_ERR_INC_RESP /* Incomplete response */

} Lin_SlaveErrorType;
/* *****************************************************************************
*                                STRUCTURES AND OTHER TYPEDEFS
 ******************************************************************************/
/**
* @brief          Data length of a LIN Frame.
* @details        This type is used to specify the number of SDU
*                 data bytes to copy.
* @implements     Lin_FrameDlType_typedef
*/
typedef uint8 Lin_FrameDlType;

/**
* @brief          The LIN identifier (0..0x3F) with its parity bits.
* @details        Represents all valid protected Identifier used by
*                 Lin_SendFrame().
* @implements     Lin_FramePidType_typedef
*/
typedef uint8 Lin_FramePidType;

/**
* @brief          The LIN identifier (0..0x3F) with its parity bits.
* @details        This Type is used to provide PID, checksum model,
*                 data length and SDU pointer from the LIN Interface
*                 to the LIN driver.
* @implements     Lin_PduType_struct
*/
typedef struct
{
  Lin_FramePidType      Pid;     /* LIN frame identifier.*/
  Lin_FrameCsModelType  Cs;      /* Checksum model type.*/
  Lin_FrameResponseType Drc;     /* Response type.*/
  Lin_FrameDlType       Dl;      /* Data length.*/
  uint8*                SduPtr;  /* Pointer to Sdu.*/
} Lin_PduType;

/******************************************************************************
 *  CONSTANTS
 *****************************************************************************/

/******************************************************************************
 *  GLOBAL VARIABLES
 *****************************************************************************/

/******************************************************************************
 *  GLOBAL FUNCTION
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* COMSTACK_CFG_H */

