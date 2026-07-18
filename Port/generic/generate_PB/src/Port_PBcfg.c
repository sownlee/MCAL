[!CODE!][!//
[!AUTOSPACING!]
/***********************************************************************************************************************
 * Project Name: Classic_Autosar_02
 * 
 * File Name: Port_PBcfg.h
 *
 * Description: Implementation of Port_PBcfg High Level layer
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

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES
 **********************************************************************************************************************/
#include "Port.h"
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
#define START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "PB_Variant" = "concat('PB_', $postBuildVariant)"!]
[!ELSE!]
    [!VAR "PB_Variant" = "'PB'"!]
[!ENDIF!]
[!VAR "PortEcucPartitionRefCount" = "num:i(count(as:modconf('Port')[1]/PortGeneral/PortEcucPartitionRef/*))"!]
[!IF "$PortEcucPartitionRefCount != 0 "!]
    [!VAR "PortEcucPartitionRefNum" = "1"!]
    [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
        [!VAR "maxPartition" = "0"!]
        [!LOOP "./PortGeneral/PortEcucPartitionRef/*"!]
            [!VAR "PortCrtLinkPart" = "node:value(.)"!]
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                [!IF "$PortCrtLinkPart = node:value(./OsAppEcucPartitionRef)"!]
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
    [!VAR "PortEcucPartitionRefNum" = "1"!]
[!ENDIF!]
[!ENDNOCODE!]


[!CODE!]
/**
 *   @brief  Array contain information of multi-core feature.
 */
[!ENDCODE!]
static const uint8 s_c_CoreList[PORT_MAX_PARTITIONS] =
{
[!VAR "NumofPortEcucPartitionRef"="num:i(count(as:modconf('Port')[1]/PortGeneral/PortEcucPartitionRef/*))"!]
[!FOR "index" = "0" TO "num:i($maxPartition)"!]
    [!VAR "CoreListReturn"="0"!]
    [!LOOP "./PortGeneral/PortEcucPartitionRef/*"!]
        [!VAR "PortCrtLinkPart" = "node:value(.)"!]
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
            [!IF "$PortCrtLinkPart = node:value(./OsAppEcucPartitionRef)"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                [!IF "$index = node:value(./EcucCoreId)"!]
                    [!VAR "CoreListReturn"="1"!]
                [!ENDIF!]
                [!ENDSELECT!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]
    [!IF "$NumofPortEcucPartitionRef = 0"!]
        [!VAR "CoreListReturn"="0"!]
        [!CODE!][!WS "4"!][!"num:i($CoreListReturn)"!][!ENDCODE!]
    [!ELSEIF "$NumofPortEcucPartitionRef != 0"!]
        [!CODE!][!WS "4"!][!"num:i($CoreListReturn)"!][!IF "$index < num:i($maxPartition)"!],[!ENDIF!][!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]
[!CR!]
};

/**
 *   @brief  Data structure containing the initialization data for the Port Driver.
 */
const Port_ConfigType Port_g_c_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Pointer to the Ipc pointer configuration */
    &Port_Ipc_g_c_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!CR!]
    /* Core index */
    s_c_CoreList[!CR!]
};

#define STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

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

/*--------------------------------------------------- End Of File -----------------------------------------------------*/
[!ENDCODE!][!//
