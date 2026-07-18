#ifndef COMSTACK_CFG_H
#define COMSTACK_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


#include "Platform_Types.h"


/**
* @brief   This type serve as a unique identifier of a PDU within a software module.
*          Allowed ranges: uint8 .. uint16
* @implements PduIdType_type
*/
typedef uint16       PduIdType;

/**
* @brief   This type serve as length information of a PDU in bytes.
*          Allowed ranges: uint8 .. uint32
* @implements PduLengthType_Type
*/
typedef uint32       PduLengthType;

#ifdef __cplusplus
}
#endif


#endif /* COMSTACK_CFG_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
