[!CODE!][!//
[!AUTOSPACING!]
/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Ip_PB.c
 *
 * Description: Implementation of Dio_Ip_PB IP Level layer
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

#include "Dio_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PB.h"
#include "Dio_Ip.h"

/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

#define Dio_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_VENDOR_ID_C                         15U
#define Dio_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_AR_RELEASE_MAJOR_VERSION_C          4U
#define Dio_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_AR_RELEASE_MINOR_VERSION_C          4U
#define Dio_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_AR_RELEASE_REVISION_VERSION_C       0U


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
[!NOCODE!]

/*************** Get_Each_Config ******************/
[!MACRO "Get_Each_Config","TheEnd"!][!//
[!NOCODE!][!//
    [!CODE!][!WS "8"!]{[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!]/* DioController_e */[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!][!"node:value(DioController)"!],  [!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!]/* DioTransferMethod_e */[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!][!"node:value(DioTransferMethod)"!],  [!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!]/* DioDirection_e */[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!][!"node:value(DioDirection)"!],  [!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!]/* DioBaudrate_e */[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!][!"node:value(DioBaudrate)"!],  [!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!]/* DioParityControl_e */[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!][!"node:value(DioParityControl)"!],  [!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!]/* DioWordLength_e */[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!][!"node:value(DioWordLength)"!],  [!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!]/* DioNumberOfStopBits_e */[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!][!"node:value(DioNumberOfStopBits)"!],  [!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!]/* DioHWFlowControl_e */[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!][!"node:value(DioHWFlowControl)"!],  [!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!]/* DioOverSampling_e */[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!][!"node:value(DioOverSampling)"!],  [!ENDCODE!][!CR!]

            [!SELECT "node:ref(DioClockRef)"!][!//
                [!VAR "ClockFrequencyFromMcu" = "McuClockReferencePointFrequency"!]
            [!ENDSELECT!][!//

            [!CODE!][!WS "12"!]/* ClockFrequencyFromMcu_u32 */[!ENDCODE!][!CR!]
            [!CODE!][!WS "12"!][!"num:i($ClockFrequencyFromMcu)"!]U,  [!ENDCODE!][!CR!]

            [!CODE!][!WS "12"!]/* DmaConfigNumberTx_u32 */[!ENDCODE!][!CR!]
            [!IF "(node:exists(DioDmaTxConfigRef))"!][!//
            [!SELECT "node:ref(DioDmaTxConfigRef)"!][!//
            [!CODE!][!WS "12"!][!"MclDmaConfigId"!]U,  [!ENDCODE!][!CR!]
            [!ENDSELECT!][!//
            [!ELSE!][!//
                [!CODE!][!WS "12"!]255,[!ENDCODE!][!CR!]
            [!ENDIF!][!//  

            [!CODE!][!WS "12"!]/* DmaConfigNumberRx_u32 */[!ENDCODE!][!CR!]
            [!IF "(node:exists(DioDmaRxConfigRef))"!][!//
            [!SELECT "node:ref(DioDmaRxConfigRef)"!][!//
            [!CODE!][!WS "12"!][!"MclDmaConfigId"!]U,  [!ENDCODE!][!CR!]
            [!ENDSELECT!][!//
            [!ELSE!][!//
                [!CODE!][!WS "12"!]255,[!ENDCODE!][!CR!]
            [!ENDIF!][!//  
           
    [!CODE!][!WS "8"!]}[!ENDCODE!][!IF "$TheEnd = 1"!][!CODE!],[!ENDCODE!][!ENDIF!][!CR!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Dio_Ip_ArrayConfigSet","Type"!][!//
[!NOCODE!]
[!CODE!]
/* User Configuration structure for Dio config */
const Dio_Ip_EachConfigType Dio_Ip_EachConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_a[[!"num:i(count(DioConfigSet/DioConfig/*))"!]U] = 
[!ENDCODE!]
[!CODE!]{[!ENDCODE!][!CR!]
[!LOOP "node:order(DioConfigSet/DioConfig/*,'node:value(./DioConfigId)')"!][!//
[!CODE!][!WS "4"!]{[!ENDCODE!][!CR!]
            [!CODE!][!WS "8"!][!"num:i(node:value(./DioConfigId))"!]U, /* DioConfigId_u32 */[!ENDCODE!][!CR!]
            [!CALL "Get_Each_Config", "TheEnd"="0"!]
[!CODE!][!WS "4"!]},[!ENDCODE!][!CR!] 
[!ENDLOOP!][!// "DioConfigSet/DioConfig/*"
[!CODE!]};[!ENDCODE!][!CR!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!ENDNOCODE!]

#define START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

[!CALL "Dio_Ip_ArrayConfigSet", "Type" = "'PB'"!]

[!INCLUDE "Dio_Ip_GenConfigAndClock.m"!]
[!CALL "Dio_GenAllConfig", "Type" = "'PB'"!]

#define STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

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
