[!CODE!][!//
[!AUTOSPACING!]
/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: CDD_Dio_Cfg.h
 *
 * Description: Implementation of CDD_Dio_Cfg High Level layer
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

#ifndef CDD_Dio_CFG_H
#define CDD_Dio_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "as:modconf('EcuC')[1]/EcucPostBuildVariants/EcucPostBuildVariantRef/*"!][!//
#include "CDD_Dio_[!"substring-after(substring-after(substring-after(node:value(.),'/'),'/'),'/')"!]_PB.h"
    [!ENDLOOP!][!//
[!ELSE!]
#include "CDD_Dio_PB.h"
[!ENDIF!]
#include "CDD_Dio_Types.h"

/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/**
 * @brief   Definition of software version number about Mcl config at High layer.
 */
#define CDD_Dio_CFG_SW_MAJOR_VERSION        1U
#define CDD_Dio_CFG_SW_MINOR_VERSION        0U
#define CDD_Dio_CFG_SW_PATCH_VERSION        0U

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/

/**
 * @brief   Definition of CDD Mcl external configure at High layer.
 */
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild' or (variant:size()>1))"!][!//
#define CDD_Dio_CONFIG_EXT \
    [!IF "var:defined('postBuildVariant')"!][!//
        [!LOOP "variant:all()"!][!//
                CDD_Dio_CONFIG_[!"."!]_PB \
        [!ENDLOOP!][!//
    [!ELSE!][!//
                CDD_Dio_CONFIG_PB
    [!ENDIF!]
[!ENDIF!]


/**
* @brief    Ip Instance ID of the Dio driver.
*/
#define Dio_INSTANCE          ((uint8)0x00)


/**
 * @brief   Enable or Disable Development Error Detection.
 */
#define Dio_DEV_ERROR_DETECT           [!IF "DioGeneral/DioDevErrorDetect"!][!WS "8"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief   Enable or Disable Dio driver Pre-Compile configuration.
 */
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' and variant:size()<=1"!][!//
#define Dio_PRECOMPILE_SUPPORT     (STD_ON)
[!ELSE!][!//
#define Dio_PRECOMPILE_SUPPORT     (STD_OFF)
[!ENDIF!][!//

[!NOCODE!]
    [!VAR "DioEcucPartitionRefCount" = "num:i(count(as:modconf('Dio')[1]/DioGeneral/DioEcucPartitionRef/*))"!]
    [!IF "$DioEcucPartitionRefCount != 0 "!]
        [!VAR "DioEcucPartitionRefNum" = "$DioEcucPartitionRefCount"!]
        [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
            [!VAR "maxPartition" = "0"!]
            [!LOOP "./DioGeneral/DioEcucPartitionRef/*"!]
                [!VAR "DioCrtPart" = "node:value(.)"!]
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                    [!IF "$DioCrtPart = node:value(./OsAppEcucPartitionRef)"!]
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
 * @brief    Number of configured partitions
 */
#define Dio_MAX_PARTITIONS                    [!WS "4"!]([!"num:i($maxPartition + 1)"!]U)


/**
 * @brief    Enable or disable multi-core features.
 */
#define Dio_MULTICORE_SUPPORT                 [!IF "DioGeneral/DioMulticoreSupport"!][!WS "4"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief    Enable or disable user mode features.
 */
#define Dio_USERMODE_SUPPORT                 [!IF "DioGeneral/DioEnableUserModeSupport"!][!WS "4"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


[!IF "node:value(DioGeneral/DioErrorIsrNotificationEnable) = 'true'"!]
/**
 *@brief    The callout configured by the user for Dio notifications.
 */
#define Dio_ERROR_ISR_NOTIFICATION(para_ErrorCode_u8)   [!WS "4"!]([!"normalize-space(DioGeneral/DioErrorNotification)"!](para_ErrorCode_u8))
[!ENDIF!]


/**
 *@brief    Maximum number of Dio configurations.
 */
[!NOCODE!]
[!VAR "MaxNumberClockDioCFG" = "0"!]
    [!VAR "MaxNumberClockDioCFG" = "num:i(count(DioConfigSet/DioConfig/*))"!]
[!ENDNOCODE!]
#define Dio_MAX_CONFIGSET   [!WS "4"!]((uint32)[!"num:i($MaxNumberClockDioCFG)"!]U)


/**
 *@brief    Pre-processor switch to enable/disable the API Dio_VersionInfoApi.
 */
#define Dio_GETVERSION_INFO_API           [!WS "4"!][!IF "DioGeneral/DioVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
 *@brief    Pre-processor switch to enable/disable DioEnableInterrupt.
 */
#define Dio_ENABLE_INTERRUPT           [!WS "4"!][!IF "DioGeneral/DioEnableInterrupt = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
 *@brief    Pre-processor switch to enable/disable DioDmaEnable.
 */
#define Dio_ENABLE_DMA           [!WS "4"!][!IF "DioGeneral/DioDmaEnable = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]



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

#endif /* CDD_Dio_CFG_H */

/*--------------------------------------------------- End Of File -----------------------------------------------------*/
[!ENDCODE!][!//