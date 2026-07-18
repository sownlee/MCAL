[!CODE!][!//
[!AUTOSPACING!][!//
/***********************************************************************************************************************
 * Project Name: Classic_Autosar_02
 * 
 * File Name: Port_Cfg.h
 *
 * Description: Implementation of PORT_CFG High Level layer
 *              
 * AutoSAR Version:         4.4.0
 *
 * Compiler: GCC IAR GHS TASKING
 *
 * Revision:
 *              Version         Date                Change History
 *              0.0.1          07/05/2026           Initial version
 *
 **********************************************************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "as:modconf('EcuC')[1]/EcucPostBuildVariants/EcucPostBuildVariantRef/*"!][!//
#include "Port_[!"substring-after(substring-after(substring-after(node:value(.),'/'),'/'),'/')"!]_PBcfg.h"
    [!ENDLOOP!][!//
[!ELSE!]
#include "Port_PBcfg.h"
[!ENDIF!]
#include "Port_Types.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

 /**
 * @brief   Definition of software version number about Port config at High layer.
 */
#define PORT_CFG_SW_MAJOR_VERSION        0U
#define PORT_CFG_SW_MINOR_VERSION        0U
#define PORT_CFG_SW_PATCH_VERSION        1U

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                      EXTERN
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL CONSTANTS
 **********************************************************************************************************************/
 /**
 * @brief   Definition of Port external configure at High layer.
 */
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild' or (variant:size()>1))"!][!//
#define PORT_CONFIG_EXT \
    [!IF "var:defined('postBuildVariant')"!][!//
        [!LOOP "variant:all()"!][!//
                PORT_CONFIG_[!"."!]_PB \
        [!ENDLOOP!][!//
    [!ELSE!][!//
                PORT_CONFIG_PB
    [!ENDIF!]
[!ENDIF!]

/**
 * @brief   Enable or Disable Development Error Detection.
 */
#define PORT_DEV_ERROR_DETECT           [!IF "PortGeneral/PortDevErrorDetect"!][!WS "8"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief   Enable or disable Port_SetPinDirection API function.
 */
#define PORT_SET_PIN_DIRECTION_API      [!IF "PortGeneral/PortSetPinDirectionApi"!][!WS "8"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief   Enable or disable Port_SetPinMode API function.
 */
#define PORT_SET_PIN_MODE_API           [!IF "PortGeneral/PortSetPinModeApi"!][!WS "8"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief   Enable or disable Port_ReSetPinMode API function.
 */
#define PORT_RESET_PIN_MODE_API           [!IF "PortGeneral/PortResetPinModeApi"!][!WS "8"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief   Enable or disable Port_GetVersionInfo API function.
 */
#define PORT_VERSION_INFO_API           [!IF "PortGeneral/PortVersionInfoApi"!][!WS "8"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief   Count the currently defined number of PortPin.
 */
#define PORT_NUM_PINS           ([!"num:i(count(PortConfigSet/PortContainer/*/PortPin/*))"!]U)

/**
 * @brief   Enable or Disable Port driver Pre-Compile configuration.
 */
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' and variant:size()<=1"!][!//
#define PORT_PRECOMPILE_SUPPORT     (STD_ON)
[!ELSE!][!//
#define PORT_PRECOMPILE_SUPPORT     (STD_OFF)
[!ENDIF!][!//

[!NOCODE!]
    [!VAR "PortEcucPartitionRefCount" = "num:i(count(as:modconf('Port')[1]/PortGeneral/PortEcucPartitionRef/*))"!]
    [!IF "$PortEcucPartitionRefCount != 0 "!]
        [!VAR "PortEcucPartitionRefNum" = "$PortEcucPartitionRefCount"!]
        [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
            [!VAR "maxPartition" = "0"!]
            [!LOOP "./PortGeneral/PortEcucPartitionRef/*"!]
                [!VAR "PortCrtPart" = "node:value(.)"!]
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                    [!IF "$PortCrtPart = node:value(./OsAppEcucPartitionRef)"!]
                        [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                            [!IF "$maxPartition < node:value(./EcucCoreId)"!]
                                [!VAR "maxPartition" = "node:value(./EcucCoreId)"!]
                            [!ENDIF!]
                        [!ENDSELECT!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDLOOP!]
        [!ELSE!]
            [!VAR "maxPartition" = "0"!]
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                    [!IF "$maxPartition < node:value(./EcucCoreId)"!]
                        [!VAR "maxPartition" = "node:value(./EcucCoreId)"!]
                    [!ENDIF!]
                [!ENDSELECT!]
            [!ENDLOOP!]
        [!ENDIF!]
    [!ELSE!]
        [!VAR "maxPartition" = "0"!]
    [!ENDIF!]
[!ENDNOCODE!]

/**
 * @brief Number of configured partitions
 * @details SRS ID: SWS_Port_CONSTR_00233
 */
#define PORT_MAX_PARTITIONS                    [!WS "4"!]([!"num:i($maxPartition + 1)"!]U)

/**
 * @brief Enable or disable multi-core features.
 */
#define PORT_MULTICORE_SUPPORT                 [!IF "PortGeneral/PortMulticoreSupport"!][!WS "4"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief Port Pin symbol names
 * @details SRS ID: SWS_Port_00013, SWS_Port_00207, SWS_Port_00208
 */
[!NOCODE!]
    [!SELECT "PortConfigSet"!][!//
        [!VAR "NameOfConfigSet" = "as:name(.)"!][!//
        [!LOOP "PortContainer/*"!][!//
            [!VAR "NameOfContainer" = "node:name(.)"!][!//
            [!LOOP "PortPin/*"!][!//
[!CODE!][!//
#define [!"$NameOfConfigSet"!]_[!"$NameOfContainer"!]_[!"node:name(.)"!]  [!WS "4"!][!"PortPinId"!]
[!ENDCODE!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDSELECT!][!//
[!ENDNOCODE!]

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

#endif /* PORT_CFG_H */

/*--------------------------------------------------- End Of File -----------------------------------------------------*/
[!ENDCODE!][!//
