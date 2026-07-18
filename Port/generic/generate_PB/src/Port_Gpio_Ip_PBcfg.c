[!CODE!][!//
[!AUTOSPACING!][!//
/***********************************************************************************************************************
 * Project Name: Classic_Autosar_02
 * 
 * File Name: Port_Gpio_Ip_PBcfg.h
 *
 * Description: Implementation of Port_Gpio_Ip_PBcfg High Level layer
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
#include "Port_Gpio_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h"
#include "Port_Gpio_Ip.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/

[!SELECT "PortConfigSet/PortContainer"!][!//
/**
 *   @brief  Number of pin configured.
 */
#define PORT_GPIO_IP_NUM_OF_CONFIG_PIN    ([!"num:i(count(*/PortPin/*))"!]U)
[!ENDSELECT!][!// 
    
[!SELECT "PortConfigSet"!][!//
/**
 *   @brief  Number of unused pin configured.
 */
#define PORT_GPIO_IP_NUM_OF_UNUSED_PIN    ([!"num:i(count(./UnUsedPortPin/*))"!]U)
[!ENDSELECT!][!//

/***********************************************************************************************************************
 *                                                      EXTERN
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL CONSTANTS
 **********************************************************************************************************************/



[!/* Get Pin */!][!//
[!MACRO "PinIndex"!][!//
[!NOCODE!][!//
    [!IF "contains(./PortPinName,'_00')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_00')"!][!//
    [!ELSEIF "contains(./PortPinName,'_01')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_01')"!][!//
    [!ELSEIF "contains(./PortPinName,'_02')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_02')"!][!//
    [!ELSEIF "contains(./PortPinName,'_03')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_03')"!][!//
    [!ELSEIF "contains(./PortPinName,'_04')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_04')"!][!//
    [!ELSEIF "contains(./PortPinName,'_05')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_05')"!][!//
    [!ELSEIF "contains(./PortPinName,'_06')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_06')"!][!//
    [!ELSEIF "contains(./PortPinName,'_07')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_07')"!][!//
    [!ELSEIF "contains(./PortPinName,'_08')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_08')"!][!//
    [!ELSEIF "contains(./PortPinName,'_09')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_09')"!][!//
    [!ELSEIF "contains(./PortPinName,'_10')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_10')"!][!//
    [!ELSEIF "contains(./PortPinName,'_11')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_11')"!][!//
    [!ELSEIF "contains(./PortPinName,'_12')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_12')"!][!//
    [!ELSEIF "contains(./PortPinName,'_13')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_13')"!][!//
    [!ELSEIF "contains(./PortPinName,'_14')"!][!//
        [!VAR "PinName"= "string('PORT_PIN_14')"!][!//
    [!ELSE!][!//
        [!VAR "PinName"= "string('PORT_PIN_15')"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$PinName"!][!//
[!ENDMACRO!][!//

[!/* Get PortIndex */!][!//
[!MACRO "PortIndex"!][!//
[!NOCODE!][!//
    [!IF "contains(./PortPinName,'PA')"!][!//
        [!VAR "PortName"= "string('PORT_GROUP_A')"!][!//
    [!ELSEIF "contains(./PortPinName,'PB')"!][!//
        [!VAR "PortName"= "string('PORT_GROUP_B')"!][!//
    [!ELSEIF "contains(./PortPinName,'PC')"!][!//
        [!VAR "PortName"= "string('PORT_GROUP_C')"!][!//
    [!ELSEIF "contains(./PortPinName,'PD')"!][!//
        [!VAR "PortName"= "string('PORT_GROUP_D')"!][!//
    [!ELSEIF "contains(./PortPinName,'PE')"!][!//
        [!VAR "PortName"= "string('PORT_GROUP_E')"!][!//
    [!ELSEIF "contains(./PortPinName,'PF')"!][!//
        [!VAR "PortName"= "string('PORT_GROUP_F')"!][!//
    [!ELSEIF "contains(./PortPinName,'PG')"!][!//
        [!VAR "PortName"= "string('PORT_GROUP_G')"!][!//
    [!ELSEIF "contains(./PortPinName,'PH')"!][!//
        [!VAR "PortName"= "string('PORT_GROUP_H')"!][!//
    [!ELSE!][!//
        [!VAR "PortName"= "string('PORT_GROUP_I')"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$PortName"!][!//
[!ENDMACRO!][!//

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


[!NOCODE!]
    [!FOR "PartitionIdx" = "1" TO "$PortEcucPartitionRefNum"!]
    [!VAR "CounterNumber" = "1"!]
    [!SELECT "PortConfigSet"!][!//
        [!VAR "NameofConfigSet" = "as:name(.)"!][!//
        [!LOOP "PortContainer/*"!][!//
            [!VAR "NameofContainer" = "node:name(.)"!][!//
        [!ENDLOOP!][!//
    [!ENDSELECT!][!//
        [!SELECT "PortConfigSet/PortContainer"!]
        [!VAR "NumPinInPartition"  = "0"!]
        [!IF "$PortEcucPartitionRefCount != 0 or ($PortEcucPartitionRefCount = 0)"!]
            [!VAR "NumPinInPartition" = "num:i(count(*/PortPin/*))"!]
        [!ENDIF!]
        [!VAR "Idxxx" = "1"!]
            [!IF "num:i($NumPinInPartition)!=0 or num:i($NumPinInPartition)=0"!]
            [!CODE!]
/**
 *   @brief  List array contain information of All mode for each pin.
 */
            [!ENDCODE!]
                [!LOOP "*/PortPin/*"!]
                        [!CODE!][!IF "PortPinName = 'PA_00'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM2_CH1_ETR,PORT_GPIO_IP_IN_MODE_TIM5_CH1,PORT_GPIO_IP_IN_MODE_TIM8_ETR,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART2_CTS,PORT_GPIO_IP_OUT_MODE_UART4_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_ETH_MII_CRS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_01'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM2_CH2,PORT_GPIO_IP_IN_MODE_TIM5_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART2_RTS,PORT_GPIO_IP_IN_MODE_UART4_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_ETH_MII_RX_CLK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_02'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM2_CH3,PORT_GPIO_IP_IN_MODE_TIM5_CH3,PORT_GPIO_IP_IN_MODE_TIM9_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART2_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_ETH_MDIO,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_03'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM2_CH4,PORT_GPIO_IP_IN_MODE_TIM5_CH4,PORT_GPIO_IP_IN_MODE_TIM9_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART2_RX,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION, PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D0,PORT_GPIO_IP_IN_MODE_ETH_MII_COL,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_04'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI1_NSS,PORT_GPIO_IP_IN_MODE_SPI3_NSS,PORT_GPIO_IP_IN_MODE_USART2_CK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_SOF,PORT_GPIO_IP_IN_MODE_DCMI_HSYNC,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_05'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM2_CH1_ETR,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_CH1N,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI1_SCK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_SOF,PORT_GPIO_IP_IN_MODE_DCMI_HSYNC,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_06'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_BKIN,PORT_GPIO_IP_IN_MODE_TIM3_CH1,PORT_GPIO_IP_IN_MODE_TIM8_BKIN,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI1_MISO,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM13_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_07'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH1N,PORT_GPIO_IP_IN_MODE_TIM3_CH2,PORT_GPIO_IP_IN_MODE_TIM8_CH1N,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_SPI1_MOSI,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM14_CH1,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_ETH_MII_RX_DV,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_08'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_IN_MODE_MCO1,PORT_GPIO_IP_IN_MODE_TIM1_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_I2C3_SCL,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART1_CK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_FS_SOF,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_09'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C3_SMBA,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART1_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D0,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_10'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART1_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_FS_ID,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_11'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART1_CTS,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_CAN1_RX,PORT_GPIO_IP_IN_MODE_OTG_FS_DM,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_12'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_ETR,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART1_RTS,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_CAN1_TX,PORT_GPIO_IP_IN_MODE_OTG_FS_DP,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_13'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_IN_MODE_JTMS_SWDIO,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_14'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_IN_MODE_JTCK_SWCLK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PA_15'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_IN_MODE_JTDI,PORT_GPIO_IP_IN_MODE_TIM2_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI1_NSS,PORT_GPIO_IP_IN_MODE_SPI3_NSS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                
                                [!ELSEIF "PortPinName = 'PB_00'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH2N,PORT_GPIO_IP_IN_MODE_TIM3_CH3,PORT_GPIO_IP_IN_MODE_TIM8_CH2N,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D1,PORT_GPIO_IP_IN_MODE_ETH_MII_RXD2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_01'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH3N,PORT_GPIO_IP_IN_MODE_TIM3_CH4,PORT_GPIO_IP_IN_MODE_TIM8_CH3N,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D2,PORT_GPIO_IP_IN_MODE_ETH_MII_RXD3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_02'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_03'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_IN_MODE_JTDO,PORT_GPIO_IP_IN_MODE_TIM2_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI1_SCK,PORT_GPIO_IP_IN_MODE_SPI3_SCK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_04'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_IN_MODE_NJTRST,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM3_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI1_MISO,PORT_GPIO_IP_IN_MODE_SPI3_MISO,PORT_GPIO_IP_IN_MODE_I2S3ext_SD,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_05'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM3_CH2,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_I2C1_SMBA,PORT_GPIO_IP_OUT_MODE_SPI1_MOSI,PORT_GPIO_IP_OUT_MODE_SPI3_MOSI,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_CAN2_RX,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D7,PORT_GPIO_IP_OUT_MODE_ETH_PPS_OUT,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D10,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_06'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM4_CH1,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C1_SCL,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART1_TX,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_CAN2_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D5,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_07'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM4_CH2,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C1_SDA,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART1_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_NL,PORT_GPIO_IP_IN_MODE_DCMI_VSYNC,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_08'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM4_CH3,PORT_GPIO_IP_IN_MODE_TIM10_CH1,PORT_GPIO_IP_IN_MODE_I2C1_SCL,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_CAN1_RX,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_ETH_MII_TXD3,PORT_GPIO_IP_IN_MODE_SDIO_D4,PORT_GPIO_IP_IN_MODE_DCMI_D6,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_09'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM4_CH4,PORT_GPIO_IP_IN_MODE_TIM11_CH1,PORT_GPIO_IP_IN_MODE_I2C1_SDA,PORT_GPIO_IP_OUT_MODE_SPI2_NS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_CAN1_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SDIO_D5,PORT_GPIO_IP_IN_MODE_DCMI_D7,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_10'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM2_CH3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C2_SCL,PORT_GPIO_IP_OUT_MODE_SPI2_SCK,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART3_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D3,PORT_GPIO_IP_IN_MODE_ETH_MII_RX_ER,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_11'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM2_CH4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C2_SDA,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART3_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D4,PORT_GPIO_IP_OUT_MODE_ETH_MII_TX_EN,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_12'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_BKIN,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C2_SMBA,PORT_GPIO_IP_OUT_MODE_SPI2_NSS,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART3_CK,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_CAN2_RX,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D5,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD0,PORT_GPIO_IP_IN_MODE_OTG_HS_ID,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_13'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH1N,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_SPI2_SCK,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART3_CTS,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_CAN2_TX,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D6,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_14'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH1N,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI2_MISO,PORT_GPIO_IP_IN_MODE_I2S2ext_SD,PORT_GPIO_IP_OUT_MODE_USART3_RTS,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM12_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_DM,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PB_15'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH3N,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_CH3N,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_SPI2_MOSI,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM12_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_DP,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                            
                                [!ELSEIF "PortPinName = 'PC_00'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_STP,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_01'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_ETH_MDC,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_02'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI2_MISO,PORT_GPIO_IP_IN_MODE_I2S2ext_SD,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_DIR,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_03'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_SPI2_MOSI,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_NXT,PORT_GPIO_IP_OUT_MODE_ETH_MII_TX_CLK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_04'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_ETH_MII_RXD0,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_05'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_ETH_MII_RXD1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_06'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM3_CH1,PORT_GPIO_IP_IN_MODE_TIM8_CH1,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_I2S2_MCK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART6_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SDIO_D6,PORT_GPIO_IP_IN_MODE_DCMI_D0,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_07'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM3_CH2,PORT_GPIO_IP_IN_MODE_TIM8_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_I2S3_MCK,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART6_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SDIO_D7,PORT_GPIO_IP_IN_MODE_DCMI_D1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_08'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM3_CH3,PORT_GPIO_IP_IN_MODE_TIM8_CH3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_I2S3_MCK,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART6_CK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SDIO_D0,PORT_GPIO_IP_IN_MODE_DCMI_D2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_09'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_OUT_MODE_MCO2,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM3_CH4,PORT_GPIO_IP_IN_MODE_TIM8_CH4,PORT_GPIO_IP_IN_MODE_I2C3_SDA,PORT_GPIO_IP_IN_MODE_I2S_CKIN,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SDIO_D1,PORT_GPIO_IP_IN_MODE_DCMI_D3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_10'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI3_SCK,PORT_GPIO_IP_OUT_MODE_USART3_TX,PORT_GPIO_IP_OUT_MODE_UART4_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SDIO_D2,PORT_GPIO_IP_IN_MODE_DCMI_D8,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_11'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2S3ext_SD,PORT_GPIO_IP_IN_MODE_SPI3_MISO,PORT_GPIO_IP_IN_MODE_USART3_RX,PORT_GPIO_IP_IN_MODE_UART4_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SDIO_D3,PORT_GPIO_IP_IN_MODE_DCMI_D4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_12'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_SPI3_MOSI,PORT_GPIO_IP_IN_MODE_USART3_CK,PORT_GPIO_IP_OUT_MODE_UART5_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_SDIO_CK,PORT_GPIO_IP_IN_MODE_DCMI_D9,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_13'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_14'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PC_15'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                              
                                [!ELSEIF "PortPinName = 'PD_00'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_CAN1_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_D2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_01'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_CAN1_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_D3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_02'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM3_ETR,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_UART5_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SDIO_CMD,PORT_GPIO_IP_IN_MODE_DCMI_D11,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_03'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART2_CTS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_CLK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_04'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART2_RTS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NOE,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_05'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART2_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NWE,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_06'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART2_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_NWAIT,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_07'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART2_CK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NE1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_08'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART3_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_D13,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_09'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART3_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_D14,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_10'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART3_CK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_D15,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_11'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART3_CTS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A16,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_12'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM4_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART3_RTS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A17,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_13'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM4_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A18,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_14'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM4_CH3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_D0,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PD_15'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM4_CH4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_D1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                               
                                [!ELSEIF "PortPinName = 'PE_00'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM4_ETR,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NBL0,PORT_GPIO_IP_IN_MODE_DCMI_D2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_01'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NBL1,PORT_GPIO_IP_IN_MODE_DCMI_D3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_02'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_OUT_MODE_TRACECLK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD3,PORT_GPIO_IP_OUT_MODE_FSMC_A23,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_03'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_OUT_MODE_TRACED0,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A19,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_04'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_OUT_MODE_TRACED1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A20,PORT_GPIO_IP_IN_MODE_DCMI_D4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_05'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_OUT_MODE_TRACED2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM9_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A21,PORT_GPIO_IP_IN_MODE_DCMI_D6,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_06'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={PORT_GPIO_IP_OUT_MODE_TRACED3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM9_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A22,PORT_GPIO_IP_IN_MODE_DCMI_D7,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_07'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_ETR,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A22,PORT_GPIO_IP_IN_MODE_FSMC_D4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_08'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH1N,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A22,PORT_GPIO_IP_IN_MODE_FSMC_D5,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_09'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A22,PORT_GPIO_IP_IN_MODE_FSMC_D6,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_10'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH2N,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A22,PORT_GPIO_IP_IN_MODE_FSMC_D7,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_11'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A22,PORT_GPIO_IP_IN_MODE_FSMC_D8,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_12'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH3N,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A22,PORT_GPIO_IP_IN_MODE_FSMC_D9,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_13'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A22,PORT_GPIO_IP_IN_MODE_FSMC_D10,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_14'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_CH4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A22,PORT_GPIO_IP_IN_MODE_FSMC_D11,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PE_15'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM1_BKIN,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A22,PORT_GPIO_IP_IN_MODE_FSMC_D12,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                            
                                [!ELSEIF "PortPinName = 'PF_00'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C2_SDA,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A0,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_01'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C2_SCL,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_02'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C2_SMBA,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_03'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_04'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_05'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A5,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_06'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM10_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NIORD,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_07'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM11_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NREG,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_08'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM13_CH1,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NIOWR,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_09'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM14_CH1,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_CD,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_10'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_INTR,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_11'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D12,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_12'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A6,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_13'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A7,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_14'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A8,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PF_15'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A9,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//

                                [!ELSEIF "PortPinName = 'PG_00'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A10,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_01'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A11,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_02'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A12,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_03'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A13,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_04'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A14,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_05'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_A15,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_06'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_INT2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_07'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART6_CK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_FSMC_INT3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_08'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART6_RTS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, PORT_GPIO_IP_OUT_MODE_ETH_PPS_OUT,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_09'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_USART6_RX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NE2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_10'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NCE4_1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_11'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, PORT_GPIO_IP_OUT_MODE_ETH_MII_TX_EN,PORT_GPIO_IP_OUT_MODE_FSMC_NCE4_2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_12'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART6_RTS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_FSMC_NE4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_13'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_UART6_CTS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD0,PORT_GPIO_IP_OUT_MODE_FSMC_A24,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_14'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART6_TX,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD1,PORT_GPIO_IP_OUT_MODE_FSMC_A25,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PG_15'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_USART6_CTS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D13,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//

                                [!ELSEIF "PortPinName = 'PH_00'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_01'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_02'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, PORT_GPIO_IP_IN_MODE_ETH_MII_CRS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_03'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, PORT_GPIO_IP_IN_MODE_ETH_MII_COL,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_04'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C2_SCL,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_NXT, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_05'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C2_SDA,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_06'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C2_SMBA,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM12_CH1,NULL_ALT_FUNCTION, PORT_GPIO_IP_IN_MODE_ETH_MII_RXD2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_07'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_I2C3_SCL,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, PORT_GPIO_IP_IN_MODE_ETH_MII_RXD3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_08'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C3_SDA,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_HSYNC,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_09'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_I2C3_SMBA,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM12_CH2,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D0,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_10'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM5_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_11'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM5_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_12'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM5_CH3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_13'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_CH1N,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_CAN1_TX,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_14'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_CH2N,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PH_15'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_CH3N,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D11,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//

                                [!ELSEIF "PortPinName = 'PI_00'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM5_CH4,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_SPI2_NSS,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D13,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_01'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI2_SCK,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D8,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_02'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_CH4,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_SPI2_MISO,PORT_GPIO_IP_IN_MODE_I2S2ext_SD,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D9,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_03'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_ETR,NULL_ALT_FUNCTION,PORT_GPIO_IP_OUT_MODE_SPI2_MOSI,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D10,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_04'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_BKIN,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D5,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_05'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_CH1,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_VSYNC,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_06'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_CH2,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D6,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_07'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_TIM8_CH3,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_DCMI_D7,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_08'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_09'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_CAN1_RX,NULL_ALT_FUNCTION, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_10'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION, PORT_GPIO_IP_IN_MODE_ETH_MII_RX_ER,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//
                                [!ELSEIF "PortPinName = 'PI_11'"!]static const uint32 s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][16] ={NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_DIR, NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION,NULL_ALT_FUNCTION}[!//

                                [!ENDIF!][!ENDCODE!][!//
                                [!CODE!];[!ENDCODE!]
                [!IF "$Idxxx!=num:i($NumPinInPartition)"!]
                [!ENDIF!]
                [!CODE!][!CR!][!ENDCODE!]
                [!VAR "Idxxx" = "$Idxxx + 1"!]
                [!ENDLOOP!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDFOR!]
[!ENDNOCODE!]


[!CODE!]
/**
 *   @brief  Data structure containing the initialization data for Pin list information of the Port driver.
 */
[!ENDCODE!]
[!NOCODE!]
    [!FOR "PartitionIdx" = "1" TO "$PortEcucPartitionRefNum"!]
    [!VAR "CounterNumber" = "1"!]
    [!SELECT "PortConfigSet"!][!//
        [!VAR "NameofConfigSet" = "as:name(.)"!][!//
        [!LOOP "PortContainer/*"!][!//
            [!VAR "NameofContainer" = "node:name(.)"!][!//
        [!ENDLOOP!][!//
    [!ENDSELECT!][!//
        [!SELECT "PortConfigSet/PortContainer"!]
        [!VAR "NumPinInPartition"  = "0"!]
        [!IF "$PortEcucPartitionRefCount != 0 or ($PortEcucPartitionRefCount = 0)"!]
            [!VAR "NumPinInPartition" = "num:i(count(*/PortPin/*))"!]
        [!ENDIF!]

        [!VAR "Idxxx" = "1"!][!VAR "Idx" = "1"!]
            [!IF "num:i($NumPinInPartition)!=0 or num:i($NumPinInPartition)=0"!]
                [!CODE!]static const Port_Gpio_Ip_PinInfoType s_c_AllMode_PinListInfo[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_GPIO_IP_NUM_OF_CONFIG_PIN]=[!CR!]{[!CR!][!ENDCODE!]
                [!LOOP "*/PortPin/*"!]
                    [!CODE!][!WS "4"!][!IF "PortPinName = 'PA_00'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_01'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_02'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_03'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_04'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_05'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_06'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_07'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_08'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_09'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_10'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_11'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_12'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_13'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_14'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_15'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_00'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_01'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_02'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_03'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_04'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_05'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_06'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_07'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_08'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_09'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_10'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_11'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_12'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_13'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_14'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_15'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PC_00'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_01'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_02'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_03'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_04'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_05'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_06'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_07'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_08'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_09'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_10'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_11'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_12'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_13'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_14'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_15'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PD_00'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_01'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_02'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_03'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_04'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_05'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_06'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_07'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_08'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_09'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_10'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_11'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_12'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_13'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_14'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_15'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PE_00'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_01'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_02'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_03'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_04'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_05'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_06'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_07'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_08'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_09'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_10'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_11'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_12'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_13'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_14'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_15'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PF_00'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_01'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_02'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_03'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_04'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_05'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_06'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_07'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_08'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_09'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_10'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_11'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_12'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_13'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_14'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_15'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PG_00'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_01'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_02'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_03'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_04'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_05'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_06'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_07'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_08'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_09'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_10'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_11'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_12'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_13'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_14'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_15'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PH_00'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_01'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_02'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_03'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_04'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_05'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_06'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_07'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_08'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_09'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_10'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_11'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_12'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_13'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_14'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_15'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PI_00'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_01'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_02'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_03'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_04'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_05'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_06'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_07'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_08'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_09'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_10'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_11'"!]{16, s_c_AllMode_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ENDIF!][!ENDCODE!][!//
                    }[!//
                    [!IF "$Idx!=num:i($NumPinInPartition)"!]
                        [!CODE!],[!ENDCODE!]
                    [!ENDIF!]
                    [!CODE!][!CR!][!ENDCODE!]
                    [!VAR "Idx" = "$Idx + 1"!]
                [!ENDLOOP!]
                [!CODE!]};[!CR!][!CR!][!ENDCODE!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDFOR!]
[!ENDNOCODE!]


[!NOCODE!]
    [!FOR "PartitionIdx" = "1" TO "$PortEcucPartitionRefNum"!]
    [!VAR "CounterNumber" = "1"!]
    [!SELECT "PortConfigSet"!][!//
        [!VAR "NameofConfigSet" = "as:name(.)"!][!//
        [!LOOP "PortContainer/*"!][!//
            [!VAR "NameofContainer" = "node:name(.)"!][!//
        [!ENDLOOP!][!//
    [!ENDSELECT!][!//
        [!SELECT "PortConfigSet/PortContainer"!]
        [!VAR "NumPinInPartition"  = "0"!]
        [!IF "$PortEcucPartitionRefCount != 0 or ($PortEcucPartitionRefCount = 0)"!]
            [!VAR "NumPinInPartition" = "num:i(count(*/PortPin/*))"!]
        [!ENDIF!]
        [!VAR "Idxxx" = "1"!]
            [!IF "num:i($NumPinInPartition)!=0 or num:i($NumPinInPartition)=0"!]
            [!CODE!]
/**
 *   @brief  List array contain information of output mode for each pin.
 */
            [!ENDCODE!]
                [!LOOP "*/PortPin/*"!]
                        [!CODE!][!IF "PortPinName = 'PA_00'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART2_CTS,PORT_GPIO_IP_OUT_MODE_UART4_TX}[!//
                                [!ELSEIF "PortPinName = 'PA_01'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PA_02'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART2_TX}[!//
                                [!ELSEIF "PortPinName = 'PA_03'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PA_04'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PA_05'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PA_06'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PA_07'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_SPI1_MOSI}[!//
                                [!ELSEIF "PortPinName = 'PA_08'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PA_09'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART1_TX}[!//
                                [!ELSEIF "PortPinName = 'PA_10'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PA_11'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PA_12'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_CAN1_TX}[!//
                                [!ELSEIF "PortPinName = 'PA_13'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PA_14'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PA_15'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                
                                [!ELSEIF "PortPinName = 'PB_00'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PB_01'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PB_02'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PB_03'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PB_04'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PB_05'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][6] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_I2C1_SMBA,PORT_GPIO_IP_OUT_MODE_SPI1_MOSI,PORT_GPIO_IP_OUT_MODE_SPI3_MOSI,PORT_GPIO_IP_OUT_MODE_I2S3_SD,PORT_GPIO_IP_OUT_MODE_ETH_PPS_OUT}[!//
                                [!ELSEIF "PortPinName = 'PB_06'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART1_TX,PORT_GPIO_IP_OUT_MODE_CAN2_TX}[!//
                                [!ELSEIF "PortPinName = 'PB_07'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PB_08'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PB_09'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][4] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_SPI2_NS,PORT_GPIO_IP_OUT_MODE_I2S2_WS,PORT_GPIO_IP_OUT_MODE_CAN1_TX}[!//
                                [!ELSEIF "PortPinName = 'PB_10'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART3_TX}[!//
                                [!ELSEIF "PortPinName = 'PB_11'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_ETH_MII_TX_EN,PORT_GPIO_IP_OUT_MODE_ETH_RMII_TX_EN}[!//
                                [!ELSEIF "PortPinName = 'PB_12'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][5] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_SPI2_NSS,PORT_GPIO_IP_OUT_MODE_I2S2_WS,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD0,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD0}[!//
                                [!ELSEIF "PortPinName = 'PB_13'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][6] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_SPI2_SCK,PORT_GPIO_IP_OUT_MODE_I2S2_CK,PORT_GPIO_IP_OUT_MODE_CAN2_TX,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD1,PORT_GPIO_IP_OUT_MODE_ETH_RMII_TXD1}[!//
                                [!ELSEIF "PortPinName = 'PB_14'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART3_RTS}[!//
                                [!ELSEIF "PortPinName = 'PB_15'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_SPI2_MOSI,PORT_GPIO_IP_OUT_MODE_I2S2_SD}[!//
                           
                                [!ELSEIF "PortPinName = 'PC_00'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PC_01'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PC_02'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD2}[!//
                                [!ELSEIF "PortPinName = 'PC_03'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][4] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_SPI2_MOSI,PORT_GPIO_IP_OUT_MODE_I2S2_SD,PORT_GPIO_IP_OUT_MODE_ETH_MII_TX_CLK}[!//
                                [!ELSEIF "PortPinName = 'PC_04'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PC_05'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PC_06'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_I2S2_MCK,PORT_GPIO_IP_OUT_MODE_USART6_TX}[!//
                                [!ELSEIF "PortPinName = 'PC_07'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_I2S3_MCK}[!//
                                [!ELSEIF "PortPinName = 'PC_08'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART6_CK}[!//
                                [!ELSEIF "PortPinName = 'PC_09'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_MCO2}[!//
                                [!ELSEIF "PortPinName = 'PC_10'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PC_11'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_CAN1_TX}[!//
                                [!ELSEIF "PortPinName = 'PC_12'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][5] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_SPI3_SCK,PORT_GPIO_IP_OUT_MODE_I2S3_CK,PORT_GPIO_IP_OUT_MODE_USART3_TX,PORT_GPIO_IP_OUT_MODE_UART4_TX}[!//
                                [!ELSEIF "PortPinName = 'PC_13'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PC_14'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PC_15'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                              
                                [!ELSEIF "PortPinName = 'PD_00'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PD_01'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_CAN1_TX}[!//
                                [!ELSEIF "PortPinName = 'PD_02'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PD_03'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_CLK}[!//
                                [!ELSEIF "PortPinName = 'PD_04'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART2_RTS,PORT_GPIO_IP_OUT_MODE_FSMC_NOE}[!//
                                [!ELSEIF "PortPinName = 'PD_05'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART2_TX,PORT_GPIO_IP_OUT_MODE_FSMC_NWE}[!//
                                [!ELSEIF "PortPinName = 'PD_06'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PD_07'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][4] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART2_CK,PORT_GPIO_IP_OUT_MODE_FSMC_NE1,PORT_GPIO_IP_OUT_MODE_FSMC_NCE2}[!//
                                [!ELSEIF "PortPinName = 'PD_08'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART3_TX}[!//
                                [!ELSEIF "PortPinName = 'PD_09'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PD_10'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART3_CK}[!//
                                [!ELSEIF "PortPinName = 'PD_11'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A16}[!//
                                [!ELSEIF "PortPinName = 'PD_12'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART3_RTS,PORT_GPIO_IP_OUT_MODE_FSMC_A17}[!//
                                [!ELSEIF "PortPinName = 'PD_13'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A18}[!//
                                [!ELSEIF "PortPinName = 'PD_14'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PD_15'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                               
                                [!ELSEIF "PortPinName = 'PE_00'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_NBL0}[!//
                                [!ELSEIF "PortPinName = 'PE_01'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_NBL1}[!//
                                [!ELSEIF "PortPinName = 'PE_02'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][4] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_TRACECLK,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD3,PORT_GPIO_IP_OUT_MODE_FSMC_A23}[!//
                                [!ELSEIF "PortPinName = 'PE_03'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_TRACED0,PORT_GPIO_IP_OUT_MODE_FSMC_A19}[!//
                                [!ELSEIF "PortPinName = 'PE_04'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_TRACED1,PORT_GPIO_IP_OUT_MODE_FSMC_A20}[!//
                                [!ELSEIF "PortPinName = 'PE_05'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_TRACED2,PORT_GPIO_IP_OUT_MODE_FSMC_A21}[!//
                                [!ELSEIF "PortPinName = 'PE_06'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_TRACED3,PORT_GPIO_IP_OUT_MODE_FSMC_A22}[!//
                                [!ELSEIF "PortPinName = 'PE_07'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PE_08'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PE_09'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PE_10'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PE_11'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PE_12'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PE_13'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PE_14'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PE_15'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                            
                                [!ELSEIF "PortPinName = 'PF_00'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A0}[!//
                                [!ELSEIF "PortPinName = 'PF_01'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_I2C2_SCL,PORT_GPIO_IP_OUT_MODE_FSMC_A1}[!//
                                [!ELSEIF "PortPinName = 'PF_02'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A2}[!//
                                [!ELSEIF "PortPinName = 'PF_03'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A3}[!//
                                [!ELSEIF "PortPinName = 'PF_04'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A4}[!//
                                [!ELSEIF "PortPinName = 'PF_05'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A5}[!//
                                [!ELSEIF "PortPinName = 'PF_06'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_NIORD}[!//
                                [!ELSEIF "PortPinName = 'PF_07'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_NREG}[!//
                                [!ELSEIF "PortPinName = 'PF_08'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_NIOWR}[!//
                                [!ELSEIF "PortPinName = 'PF_09'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_CD}[!//
                                [!ELSEIF "PortPinName = 'PF_10'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PF_11'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PF_12'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A6}[!//
                                [!ELSEIF "PortPinName = 'PF_13'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A7}[!//
                                [!ELSEIF "PortPinName = 'PF_14'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A8}[!//
                                [!ELSEIF "PortPinName = 'PF_15'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A9}[!//

                                [!ELSEIF "PortPinName = 'PG_00'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A10}[!//
                                [!ELSEIF "PortPinName = 'PG_01'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A11}[!//
                                [!ELSEIF "PortPinName = 'PG_02'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A12}[!//
                                [!ELSEIF "PortPinName = 'PG_03'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A13}[!//
                                [!ELSEIF "PortPinName = 'PG_04'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A14}[!//
                                [!ELSEIF "PortPinName = 'PG_05'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_A15}[!//
                                [!ELSEIF "PortPinName = 'PG_06'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART6_CK}[!//
                                [!ELSEIF "PortPinName = 'PG_07'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART6_RTS,PORT_GPIO_IP_OUT_MODE_ETH_PPS_OUT}[!//
                                [!ELSEIF "PortPinName = 'PG_08'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_NE2,PORT_GPIO_IP_OUT_MODE_FSMC_NCE3}[!//
                                [!ELSEIF "PortPinName = 'PG_09'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_NE2,PORT_GPIO_IP_OUT_MODE_FSMC_NCE3}[!//
                                [!ELSEIF "PortPinName = 'PG_10'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_FSMC_NCE4_1,PORT_GPIO_IP_OUT_MODE_FSMC_NE3}[!//
                                [!ELSEIF "PortPinName = 'PG_11'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][4] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_ETH_MII_TX_EN,PORT_GPIO_IP_OUT_MODE_ETH_RMII_TX_EN,PORT_GPIO_IP_OUT_MODE_FSMC_NCE4_2}[!//
                                [!ELSEIF "PortPinName = 'PG_12'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART6_RTS,PORT_GPIO_IP_OUT_MODE_FSMC_NE4}[!//
                                [!ELSEIF "PortPinName = 'PG_13'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][4] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD0,PORT_GPIO_IP_OUT_MODE_ETH_RMII_TXD0,PORT_GPIO_IP_OUT_MODE_FSMC_A24}[!//
                                [!ELSEIF "PortPinName = 'PG_14'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][5] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_USART6_TX,PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD1,PORT_GPIO_IP_OUT_MODE_ETH_RMII_TXD1,PORT_GPIO_IP_OUT_MODE_FSMC_A25}[!//
                                [!ELSEIF "PortPinName = 'PG_15'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//

                                [!ELSEIF "PortPinName = 'PH_00'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_01'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_02'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_03'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_04'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_I2C2_SCL}[!//
                                [!ELSEIF "PortPinName = 'PH_05'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_06'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_07'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_I2C3_SCL}[!//
                                [!ELSEIF "PortPinName = 'PH_08'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_09'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_10'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][2] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_CAN1_TX}[!//
                                [!ELSEIF "PortPinName = 'PH_11'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_12'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_13'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_14'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PH_15'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//

                                [!ELSEIF "PortPinName = 'PI_00'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PI_01'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][3] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_SPI2_SCK,PORT_GPIO_IP_OUT_MODE_I2S2_CK}[!//
                                [!ELSEIF "PortPinName = 'PI_02'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PI_03'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][4] ={PORT_GPIO_IP_OUT_MODE_GPO,PORT_GPIO_IP_OUT_MODE_SPI2_MOSI,PORT_GPIO_IP_OUT_MODE_I2S2_SD,PORT_GPIO_IP_OUT_MODE_DCMI_D10}[!//
                                [!ELSEIF "PortPinName = 'PI_04'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PI_05'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PI_06'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PI_07'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PI_08'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PI_09'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PI_10'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//
                                [!ELSEIF "PortPinName = 'PI_11'"!]static const uint32 s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] ={PORT_GPIO_IP_OUT_MODE_GPO}[!//

                                [!ENDIF!][!ENDCODE!][!//
                                [!CODE!];[!ENDCODE!]
                [!IF "$Idxxx!=num:i($NumPinInPartition)"!]
                [!ENDIF!]
                [!CODE!][!CR!][!ENDCODE!]
                [!VAR "Idxxx" = "$Idxxx + 1"!]
                [!ENDLOOP!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDFOR!]
[!ENDNOCODE!]



[!CODE!]
/**
 *   @brief  Data structure containing the initialization data for Pin list information of the Port driver.
 */
[!ENDCODE!]
[!NOCODE!]
    [!FOR "PartitionIdx" = "1" TO "$PortEcucPartitionRefNum"!]
    [!VAR "CounterNumber" = "1"!]
    [!SELECT "PortConfigSet"!][!//
        [!VAR "NameofConfigSet" = "as:name(.)"!][!//
        [!LOOP "PortContainer/*"!][!//
            [!VAR "NameofContainer" = "node:name(.)"!][!//
        [!ENDLOOP!][!//
    [!ENDSELECT!][!//
        [!SELECT "PortConfigSet/PortContainer"!]
        [!VAR "NumPinInPartition"  = "0"!]
        [!IF "$PortEcucPartitionRefCount != 0 or ($PortEcucPartitionRefCount = 0)"!]
            [!VAR "NumPinInPartition" = "num:i(count(*/PortPin/*))"!]
        [!ENDIF!]

        [!VAR "Idxxx" = "1"!][!VAR "Idx" = "1"!]
            [!IF "num:i($NumPinInPartition)!=0 or num:i($NumPinInPartition)=0"!]
                [!CODE!]static const Port_Gpio_Ip_PinInfoType s_c_PinListInfo[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_GPIO_IP_NUM_OF_CONFIG_PIN]=[!CR!]{[!CR!][!ENDCODE!]
                [!LOOP "*/PortPin/*"!]
                    [!CODE!][!WS "4"!][!IF "PortPinName = 'PA_00'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_01'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_02'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_03'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_04'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_05'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_06'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_07'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_08'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_09'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_10'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_11'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_12'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_13'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_14'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PA_15'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_00'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_01'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_02'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_03'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_04'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_05'"!]{6, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_06'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_07'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_08'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_09'"!]{4, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_10'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_11'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_12'"!]{5, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_13'"!]{6, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_14'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PB_15'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PC_00'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_01'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_02'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_03'"!]{4, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_04'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_05'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_06'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_07'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_08'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_09'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_10'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_11'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_12'"!]{5, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_13'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_14'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PC_15'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PD_00'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_01'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_02'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_03'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_04'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_05'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_06'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_07'"!]{4, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_08'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_09'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_10'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_11'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_12'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_13'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_14'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PD_15'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PE_00'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_01'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_02'"!]{4, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_03'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_04'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_05'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_06'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_07'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_08'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_09'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_10'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_11'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_12'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_13'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_14'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PE_15'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PF_00'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_01'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_02'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_03'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_04'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_05'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_06'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_07'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_08'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_09'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_10'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_11'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_12'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_13'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_14'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PF_15'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PG_00'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_01'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_02'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_03'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_04'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_05'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_06'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_07'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_08'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_09'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_10'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_11'"!]{4, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_12'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_13'"!]{4, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_14'"!]{5, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PG_15'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PH_00'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_01'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_02'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_03'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_04'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_05'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_06'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_07'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_08'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_09'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_10'"!]{2, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_11'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_12'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_13'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_14'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PH_15'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ELSEIF "PortPinName = 'PI_00'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_01'"!]{3, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_02'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_03'"!]{4, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_04'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_05'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_06'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_07'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_08'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_09'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_10'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//
                                      [!ELSEIF "PortPinName = 'PI_11'"!]{1, s_c_Pin_[!"PortPinName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]}[!//

                                      [!ENDIF!][!ENDCODE!][!//
                    }[!//
                    [!IF "$Idx!=num:i($NumPinInPartition)"!]
                        [!CODE!],[!ENDCODE!]
                    [!ENDIF!]
                    [!CODE!][!CR!][!ENDCODE!]
                    [!VAR "Idx" = "$Idx + 1"!]
                [!ENDLOOP!]
                [!CODE!]};[!CR!][!CR!][!ENDCODE!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDFOR!]
[!ENDNOCODE!]



[!NOCODE!]
    [!FOR "PartitionIdx" = "1" TO "$PortEcucPartitionRefNum"!]
        [!VAR "CounterNumber" = "1"!]
        [!SELECT "PortConfigSet"!][!//
            [!VAR "NameofConfigSet" = "as:name(.)"!][!//
            [!LOOP "PortContainer/*"!][!//
                [!VAR "NameofContainer" = "node:name(.)"!][!//
            [!ENDLOOP!][!//
        [!ENDSELECT!][!//
        [!SELECT "PortConfigSet/PortContainer"!]
            [!VAR "NumPinInPartition"  = "0"!]
                [!IF "$PortEcucPartitionRefCount != 0 or ($PortEcucPartitionRefCount = 0)"!]
                    [!VAR "NumPinInPartition" = "num:i(count(*/PortPin/*))"!]
                [!ENDIF!]
            [!VAR "Idxxx" = "1"!]
            [!IF "num:i($NumPinInPartition)!=0 or num:i($NumPinInPartition)=0"!]
                [!LOOP "*/PortPin/*"!]
                    [!CODE!]


[!CODE!]
/**
 *   @brief  Data structure containing the initialization data for pin setting of PinId[[!"num:i($Idxxx)"!]] of the Port driver.
 */
[!ENDCODE!]

                    [!CODE!]static const Port_Gpio_Ip_PinSettingType s_c_PinSetting[!"num:i($Idxxx)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = [!CR!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "4"!]/* [!"node:name(.)"!] */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/* PORT_PinOutEn, PORT Pin Input Enable Selection */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!].OutEn_u32 = PORT_GPIO_IP_[!IF "PortPinDirection = 'PORT_PIN_IN'"!]PIN_OUT_OFF[!ELSE!]PIN_OUT_ON[!ENDIF!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/* PORT_PinInEn, PORT Pin Input Enable Selection */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!].InEn_u32 = PORT_GPIO_IP_[!IF "PortPinDirection = 'PORT_PIN_OUT'"!]PIN_IN_OFF[!ELSE!]PIN_IN_ON[!ENDIF!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/* PORT_PinOutData, PORT Pin Output Data Selection */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!].OutData_u32 = PORT_GPIO_IP_[!"PortPinLevelValue"!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/* PORT_PinOutType, PORT Pin Output Type Selection */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!].OpenDrain_u32 = PORT_GPIO_IP_[!"PortPinOutputType"!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/* Pull-up enable/disable */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!].PullType_u32 = PORT_GPIO_IP_[!"text:replaceAll(PortPinPullType,'/','_')"!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/* Output state latch enable */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!].OutLatchEn_u32 = PORT_GPIO_IP_[!IF "PortPinOutputLatch"!]PIN_LATCH_ON[!ELSE!]PIN_LATCH_OFF[!ENDIF!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/* PORT_PinMode, PORT Pin Mode Selection */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!].PinAttr_u32 = PORT_GPIO_IP_PIN_ATTR_[!"PortPinType"!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/* Port pin mode from mode list */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!].OutFuncSel_u32 = PORT_GPIO_IP_OUT_MODE_[!IF "PortPinMode = 'GPIO'"!]GPO[!//
                                                            [!ELSEIF "PortPinDirection = 'PORT_PIN_OUT'"!][!"text:replaceAll(PortPinMode,'/','_')"!][!//
                                                            [!ELSEIF "PortPinDirection = 'PORT_PIN_INOUT'"!][!"text:replaceAll(PortPinMode,'/','_')"!][!ELSE!]GPO[!ENDIF!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/* Pin input function setting */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!].InFuncSel_u32 = PORT_GPIO_IP_IN_MODE_[!IF "PortPinMode = 'GPIO'"!]GPI[!//
                                                            [!ELSEIF "PortPinDirection = 'PORT_PIN_IN'"!][!"text:replaceAll(PortPinMode,'/','_')"!][!//
                                                            [!ELSEIF "PortPinDirection = 'PORT_PIN_INOUT'"!][!"text:replaceAll(PortPinMode,'/','_')"!]
                                                            [!ELSE!]GPI[!//
                                                            [!ENDIF!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/* Choose mode Speed */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!].PortPinSpeed_u32 = PORT_GPIO_IP_[!"PortPinSpeed"!][!CR!][!ENDCODE!]
                    [!CODE!]};[!CR!][!CR!][!ENDCODE!]

/**
 *   @brief  Data structure containing the initialization data for Pin information of PinId[[!"num:i($Idxxx)"!]] of the Port driver.
 */
[!ENDCODE!]
[!CODE!]static const Port_Gpio_Ip_PortPinType s_c_PortPin[!"num:i($Idxxx)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = [!CR!]{[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]/* [!"node:name(.)"!] */[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!]/* Pin Index */[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!].Pin_u16 = (uint16)[!CALL "PinIndex"!],[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!]/* Port Index */[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!].Port_u8 = (uint8)[!CALL "PortIndex"!],[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!]/* PortPin Index */[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!].PortPinIndex_u8 = (uint8)PORT_GPIO_IP_[!"PortPinName"!],[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!]/* Pin Id of the GPIO pin */[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!].GpioNumber_u8 = (uint8)[!"PortPinId"!]U,[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!]/* Debug mode select */[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!].DebugPort_u8 = (uint8)PORT_GPIO_IP_[!IF "PortDebugPin"!]STATUS_ENABLE[!ELSE!]STATUS_DISABLE[!ENDIF!],[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!]/* The initial direction of the pin */[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!].Direction_u8 = (uint8)PORT_GPIO_IP_[!IF "PortPinDirection = 'PORT_PIN_IN'"!]PIN_IN[!//
                                    [!ELSEIF "PortPinDirection = 'PORT_PIN_OUT'"!]PIN_OUT[!//
                                    [!ELSE!]PIN_INOUT[!ENDIF!],[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!]/* PortPin Mode Changeable */[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!].ExternalInterrupt_u8 = (uint8)PORT_GPIO_IP_[!"InterruptExternal"!],[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!]/* PortPin Mode Changeable */[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!].ModeChangeable_bool = (boolean)[!IF "PortPinModeChangeable"!]TRUE[!ELSE!]FALSE[!ENDIF!],[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!]/* PortPin Direction Changeable */[!CR!][!ENDCODE!]
    [!CODE!][!WS "8"!].DirectionChangeable_bool = (boolean)[!IF "PortPinDirectionChangeable"!]TRUE[!ELSE!]FALSE[!ENDIF!][!CR!][!ENDCODE!]
[!CODE!]};[!CR!][!CR!][!ENDCODE!]
[!VAR "Idxxx" = "$Idxxx + 1"!]



                [!ENDLOOP!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDFOR!]           
[!ENDNOCODE!]


[!/* Get UnUsedPinIndex */!][!//
[!MACRO "UnUsedPinIndex"!][!//
[!NOCODE!][!//
    [!IF "contains(./UnUsedPortPinName,'_00')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_00')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_01')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_01')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_02')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_02')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_03')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_03')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_04')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_04')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_05')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_05')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_06')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_06')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_07')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_07')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_08')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_08')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_09')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_09')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_10')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_10')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_11')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_11')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_12')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_12')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_13')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_13')"!][!//
    [!ELSEIF "contains(./UnUsedPortPinName,'_14')"!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_14')"!][!//
    [!ELSE!][!//
        [!VAR "UnUsedPinName"= "string('PORT_PIN_15')"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$UnUsedPinName"!][!//
[!ENDMACRO!][!//

[!/* Get UnUsedPortIndex */!][!//
[!MACRO "UnUsedPortIndex"!][!//
[!NOCODE!][!//
    [!IF "contains(./UnUsedPortIndex,'PA')"!][!//
        [!VAR "UnUsedPortName"= "string('PORT_GROUP_A')"!][!//
    [!ELSEIF "contains(./UnUsedPortIndex,'PB')"!][!//
        [!VAR "UnUsedPortName"= "string('PORT_GROUP_B')"!][!//
    [!ELSEIF "contains(./UnUsedPortIndex,'PC')"!][!//
        [!VAR "UnUsedPortName"= "string('PORT_GROUP_C')"!][!//
    [!ELSEIF "contains(./UnUsedPortIndex,'PD')"!][!//
        [!VAR "UnUsedPortName"= "string('PORT_GROUP_D')"!][!//
    [!ELSEIF "contains(./UnUsedPortIndex,'PE')"!][!//
        [!VAR "UnUsedPortName"= "string('PORT_GROUP_E')"!][!//
    [!ELSEIF "contains(./UnUsedPortIndex,'PF')"!][!//
        [!VAR "UnUsedPortName"= "string('PORT_GROUP_F')"!][!//
    [!ELSEIF "contains(./UnUsedPortIndex,'PG')"!][!//
        [!VAR "UnUsedPortName"= "string('PORT_GROUP_G')"!][!//
    [!ELSEIF "contains(./UnUsedPortIndex,'PH')"!][!//
        [!VAR "UnUsedPortName"= "string('PORT_GROUP_H')"!][!//
    [!ELSE!][!//
        [!VAR "UnUsedPortName"= "string('PORT_GROUP_I')"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$UnUsedPortName"!][!//
[!ENDMACRO!][!//

[!NOCODE!][!//
    [!CODE!][!//
/**
 *   @brief  Data structure containing the initialization data for not used Pin of the Port driver.
 */
    [!ENDCODE!][!//
    [!CODE!]#if (0UL != PORT_GPIO_IP_NUM_OF_UNUSED_PIN)[!CR!][!ENDCODE!][!//
        [!SELECT "PortConfigSet"!][!//
            [!VAR "count"= "1"!][!//
            [!VAR "Maxcount"= "num:i(count(./UnUsedPortPin/*))"!][!//
            [!CODE!]static const Port_Gpio_Ip_UnusedPinConfigType s_c_NotUsedPortPin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_GPIO_IP_NUM_OF_UNUSED_PIN] = [!CR!]{[!CR!][!ENDCODE!]
            [!NOCODE!]
                [!LOOP "./UnUsedPortPin/*"!][!//
                    [!IF "$Maxcount>=$count"!][!//
                        [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                            [!CODE!][!WS "8"!].Pin_u16 = (uint16)[!CALL "UnUsedPinIndex"!],[!CR!][!ENDCODE!]
                            [!CODE!][!WS "8"!].Port_u8 = (uint8)[!CALL "UnUsedPortIndex"!][!CR!][!ENDCODE!]
                        [!CODE!][!WS "4"!]}[!ENDCODE!]
                    [!ENDIF!][!//
                    [!IF "$Maxcount > $count"!]
                        [!CODE!],[!ENDCODE!]
                    [!ENDIF!]
                    [!CODE!][!CR!][!ENDCODE!]
                    [!VAR "count"= "$count+1"!][!//
                [!ENDLOOP!][!//
                [!CODE!]};[!CR!][!ENDCODE!][!//
            [!ENDNOCODE!][!//
        [!ENDSELECT!][!//  
    [!CODE!]#endif[!CR!][!ENDCODE!][!// /* (0UL != PORT_GPIO_IP_NUM_OF_UNUSED_PIN[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!])
[!ENDNOCODE!][!//


[!CODE!]
/**
 *   @brief  Data structure containing the initialization data for Pin configuration of the Port driver.
 */
[!ENDCODE!]
[!NOCODE!]
    [!FOR "PartitionIdx" = "1" TO "$PortEcucPartitionRefNum"!]
        [!VAR "CounterNumber" = "1"!]
        [!SELECT "PortConfigSet"!][!//
            [!VAR "NameofConfigSet" = "as:name(.)"!][!//
            [!LOOP "PortContainer/*"!][!//
                [!VAR "NameofContainer" = "node:name(.)"!][!//
            [!ENDLOOP!][!//
        [!ENDSELECT!][!//
        [!SELECT "PortConfigSet/PortContainer"!]
            [!VAR "NumPinInPartition"  = "0"!]
            [!IF "$PortEcucPartitionRefCount != 0 or ($PortEcucPartitionRefCount = 0)"!]
                [!VAR "NumPinInPartition" = "num:i(count(*/PortPin/*))"!]
            [!ENDIF!]
            [!VAR "Idxxx" = "1"!]
            [!IF "num:i($NumPinInPartition)!=0 or num:i($NumPinInPartition)=0"!]
                [!CODE!]static const Port_Gpio_Ip_PinConfigType s_c_PinConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_GPIO_IP_NUM_OF_CONFIG_PIN] = [!CR!]{[!CR!][!ENDCODE!]
                [!LOOP "*/PortPin/*"!]
                    [!IF "(($PortEcucPartitionRefCount != 0) or ($PortEcucPartitionRefCount = 0))"!]
                    [!CODE!][!WS "4"!]/* Pointer to the list of Pins configured [!"PortPinId"!]*/[!CR!][!ENDCODE!]
                    [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]s_c_AllMode_PinListInfo[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]s_c_PinListInfo[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]&s_c_PinSetting[!"num:i($Idxxx)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!CR!][!ENDCODE!]
                    [!CODE!][!WS "8"!]&s_c_PortPin[!"num:i($Idxxx)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!][!ENDCODE!]
                    [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!]
                    [!ENDIF!]
                    [!IF "$Idxxx!=num:i($NumPinInPartition)"!]
                        [!CODE!][!WS "4"!],[!ENDCODE!]
                    [!ENDIF!]
                    [!CODE!][!CR!][!ENDCODE!]
                    [!VAR "Idxxx" = "$Idxxx + 1"!]
                [!ENDLOOP!]
                [!CODE!]};[!CR!][!CR!][!ENDCODE!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDFOR!]
[!ENDNOCODE!]

    
[!CODE!]
/**
 *   @brief  Data structure containing the initialization data for all configuration of the Port Driver.
 */
[!ENDCODE!]
[!CODE!]const Port_Gpio_Ip_ConfigType Port_Gpio_Ip_g_c_ConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = [!CR!]{[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]Port_Gpio_Ip_g_InMode,[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]/* Pointer to the list of Port configured pins */[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]s_c_PinConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]#if (0UL != PORT_GPIO_IP_NUM_OF_UNUSED_PIN)[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]/* Pointer to the list of Port Filter */[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]s_c_NotUsedPortPin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]#else[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]NULL_PTR,[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]#endif[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]/* The number of Notused pins. */[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]PORT_GPIO_IP_NUM_OF_UNUSED_PIN,[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]/* The number of configured pins. */[!CR!][!ENDCODE!]
    [!CODE!][!WS "4"!]PORT_GPIO_IP_NUM_OF_CONFIG_PIN,[!CR!][!ENDCODE!]
    [!CODE!]};[!CR!]
[!ENDCODE!]

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
