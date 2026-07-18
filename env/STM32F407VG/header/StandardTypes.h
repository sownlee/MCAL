#ifndef STANDARDTYPES_H
#define STANDARDTYPES_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Compiler.h"
#include "Platform_Types.h"

#define STD_VENDOR_ID                     15
#define STD_AR_RELEASE_MAJOR_VERSION      4
#define STD_AR_RELEASE_MINOR_VERSION      4
#define STD_AR_RELEASE_REVISION_VERSION   0
#define STD_SW_MAJOR_VERSION              1
#define STD_SW_MINOR_VERSION              0
#define STD_SW_PATCH_VERSION              0

/**
* @brief Physical state 5V or 3.3V
*/
#define STD_HIGH    0x01

/**
* @brief Physical state 0V.
*/
#define STD_LOW     0x00

/**
* @brief Logical state active.
*/
#define STD_ACTIVE  0x01

/**
* @brief Logical state idle.
*/
#define STD_IDLE    0x00

/**
* @brief ON State.
*/
#define STD_ON      0x01

/**
* @brief OFF state.
*/
#define STD_OFF     0x00

/**
* @brief Return code for failure/error.
*/
#define E_NOT_OK    0x01
#define E_OK        0x00

typedef uint8 StatusType;

/**
* @brief This type can be used as standard API return type which is shared between the RTE and the BSW modules.
*/
typedef uint8 Std_ReturnType;

/**
* @brief This type shall be used to request the version of a BSW module using the
*       "ModuleName"_GetVersionInfo() function.
*/
typedef struct
{
    uint16  vendorID;               /* @brief Vendor ID */
    uint16  moduleID;               /* @brief BSW module ID */
    uint8   sw_major_version;       /* @brief BSW module software major version */
    uint8   sw_minor_version;       /* @brief BSW module software minor version */
    uint8   sw_patch_version;       /* @brief BSW module software patch version */
} Std_VersionInfoType;

/**
* @brief Typedef for DEM error management implemented by MCAL drivers
*/
typedef struct
{
    uint32 state;   /* enabling/disabling the DEM error: Active=STD_ON/ Inactive=STD_OFF */
    uint32 id ;     /* ID of DEM error (0 if STD_OFF)*/
}Mcal_DemErrorType; 

#ifdef __cplusplus
}
#endif

#endif /* #ifndef STANDARDTYPES_H */


