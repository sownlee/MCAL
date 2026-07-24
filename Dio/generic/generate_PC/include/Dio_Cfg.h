[!CODE!][!//
[!AUTOSPACING!]
/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Cfg.h
 *
 * Description: Implementation of Dio_Cfg High Level layer
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

#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "Dio_Types.h"

/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/**
 * @brief   Definition of software version number about Dio config at High layer.
 */
#define DIO_VENDOR_ID_CFG_H                   15
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG_H    4
#define DIO_AR_RELEASE_MINOR_VERSION_CFG_H    4
#define DIO_AR_RELEASE_REVISION_VERSION_CFG_H 0
#define DIO_SW_MAJOR_VERSION_CFG_H            1
#define DIO_SW_MINOR_VERSION_CFG_H            0
#define DIO_SW_PATCH_VERSION_CFG_H            0

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/
 /**
 * @brief  Definition for Dio configure at HLD layer.
 */
#define DIO_CONFIG_PC \
                    extern const Dio_ConfigType Dio_g_c_Config;

[!SELECT "DioConfig"!][!//
[!INDENT "0"!][!//
[!VAR "ChannelGroupNumber" = "count(DioPort/*/DioChannelGroup/*)"!][!//
[!IF "$ChannelGroupNumber != 0"!][!//
/**
 * @brief  Dio driver Channel Groups configuration switch.
 */
#define DIO_CHANNEL_GROUPS_AVAILABLE
[!ENDIF!][!//
[!ENDINDENT!][!//
[!ENDSELECT!][!//

/**
 * @brief   Enable or Disable Development Error Detection.
 */
#define DIO_DEV_ERROR_DETECT    [!IF "DioGeneral/DioDevErrorDetect"!][!WS "8"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]


/**
 * @brief  Enable or disable Dio_GetVersionInfo API function.
 */
#define DIO_VERSION_INFO_API    [!IF "DioGeneral/DioVersionInfoApi"!][!WS "8"!]STD_ON[!ELSE!][!WS "4"!]STD_OFF[!ENDIF!]


/**
 * @brief  Enable or disable Dio_FlipChannel API function.
 */
#define DIO_FLIP_CHANNEL_API    [!IF "DioGeneral/DioFlipChannelApi"!][!WS "8"!]STD_ON[!ELSE!][!WS "4"!]STD_OFF[!ENDIF!]


/**
 * @brief  Enable or disable DioMaskedWritePort API function.
 */
#define DIO_MASKEDWRITEPORT_API [!IF "DioGeneral/DioMaskedWritePortApi"!][!WS "8"!]STD_ON[!ELSE!][!WS "4"!]STD_OFF[!ENDIF!]


/**
 * @brief  Enable or disable Dio_ReadZeroForUndefinedPortPins API function.
 */
#define DIO_READZERO_UNDEFINEDPORTS [!IF "DioGeneral/DioReadZeroForUndefinedPortPins"!][!WS "8"!]STD_ON[!ELSE!][!WS "4"!]STD_OFF[!ENDIF!]


/**
 * @brief  Enable/Disable multicore function from the driver
 */
#define DIO_MULTICORE_ENABLED          [!IF "DioGeneral/DioMulticoreSupport"!][!WS "8"!]STD_ON[!ELSE!][!WS "4"!]STD_OFF[!ENDIF!]


/**
 * @brief   Enable or Disable Port driver Pre-Compile configuration.
 */
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' and variant:size()<=1"!][!//
#define DIO_PRECOMPILE_SUPPORT     (STD_ON)
[!ELSE!][!//
#define DIO_PRECOMPILE_SUPPORT     (STD_OFF)
[!ENDIF!][!//


/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

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

#endif /* DIO_CFG_H */

/*--------------------------------------------------- End Of File -----------------------------------------------------*/
[!ENDCODE!][!//