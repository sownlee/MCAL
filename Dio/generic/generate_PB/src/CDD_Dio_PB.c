[!CODE!][!//
[!AUTOSPACING!]
/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: CDD_Dio_PB.c
 *
 * Description: Implementation of CDD_Dio_PB High Level layer
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

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES
 **********************************************************************************************************************/

#include "CDD_Dio.h"

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
[!VAR "DioEcucPartitionRefCount" = "num:i(count(as:modconf('Dio')[1]/DioGeneral/DioEcucPartitionRef/*))"!]
[!IF "$DioEcucPartitionRefCount != 0 "!]
    [!VAR "DioEcucPartitionRefNum" = "1"!]
    [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
        [!VAR "maxPartition" = "0"!]
        [!LOOP "./DioGeneral/DioEcucPartitionRef/*"!]
            [!VAR "DioCrtLinkPart" = "node:value(.)"!]
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                [!IF "$DioCrtLinkPart = node:value(./OsAppEcucPartitionRef)"!]
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
    [!VAR "DioEcucPartitionRefNum" = "1"!]
[!ENDIF!]
[!ENDNOCODE!]


[!CODE!]
/**
 *   @brief  Array contain information of multi-core feature.
 */
[!ENDCODE!]
static const uint8 s_c_CoreList_a[Dio_MAX_PARTITIONS] =
{
[!VAR "NumofDioEcucPartitionRef"="num:i(count(as:modconf('Dio')[1]/DioGeneral/DioEcucPartitionRef/*))"!]
[!FOR "index" = "0" TO "num:i($maxPartition)"!]
    [!VAR "CoreListReturn"="0"!]
    [!LOOP "./DioGeneral/DioEcucPartitionRef/*"!]
        [!VAR "DioCrtLinkPart" = "node:value(.)"!]
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
            [!IF "$DioCrtLinkPart = node:value(./OsAppEcucPartitionRef)"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                [!IF "$index = node:value(./EcucCoreId)"!]
                    [!VAR "CoreListReturn"="1"!]
                [!ENDIF!]
                [!ENDSELECT!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]
    [!IF "$NumofDioEcucPartitionRef = 0"!]
        [!VAR "CoreListReturn"="0"!]
        [!CODE!][!WS "4"!][!"num:i($CoreListReturn)"!][!ENDCODE!]
    [!ELSEIF "$NumofDioEcucPartitionRef != 0"!]
        [!CODE!][!WS "4"!][!"num:i($CoreListReturn)"!][!IF "$index < num:i($maxPartition)"!],[!ENDIF!][!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]
[!CR!]
};



/**
 *   @brief  Data structure containing the initialization data for the Dio Driver.
 */
CDD_Dio_ConfigType CDD_Dio_g_c_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_st=
{
    /* Pointer to the Ipc pointer configuration */
    &Dio_Ipc_g_c_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_st,[!CR!]
    /* Core index */
    s_c_CoreList_a[!CR!]
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

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
[!ENDCODE!][!//
