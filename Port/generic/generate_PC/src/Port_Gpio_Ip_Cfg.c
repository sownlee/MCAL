[!CODE!][!//
[!AUTOSPACING!]
/***********************************************************************************************************************
 * Project Name: Classic_Autosar_02
 * 
 * File Name: Port_Gpio_Ip_Cfg.h
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

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES
 **********************************************************************************************************************/
#include "Port_Gpio_Ip_Cfg.h"
#include "Common.h"
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
 *   @brief  List Array contain information of all PinId on each input mode.
 */
[!ENDCODE!]

[!CODE!][!//
static uint32 s_InMode_TIM2_CH1_ETR[2] = {PORT_GPIO_IP_PA_00,PORT_GPIO_IP_PA_05};[!CR!][!//
static uint32 s_InMode_TIM5_CH1[2] = {PORT_GPIO_IP_PA_00,PORT_GPIO_IP_PH_10};[!CR!][!//
static uint32 s_InMode_TIM8_ETR[2] = {PORT_GPIO_IP_PA_00,PORT_GPIO_IP_PI_03};[!CR!][!//
static uint32 s_InMode_ETH_MII_CRS[2] = {PORT_GPIO_IP_PA_00,PORT_GPIO_IP_PH_02};[!CR!][!//
static uint32 s_InMode_TIM2_CH2[2] = {PORT_GPIO_IP_PA_01,PORT_GPIO_IP_PB_03};[!CR!][!//
static uint32 s_InMode_TIM5_CH2[2] = {PORT_GPIO_IP_PA_01,PORT_GPIO_IP_PH_12};[!CR!][!//
static uint32 s_InMode_USART2_RTS[2] = {PORT_GPIO_IP_PA_01,PORT_GPIO_IP_PD_04};[!CR!][!//
static uint32 s_InMode_UART4_RX[2] = {PORT_GPIO_IP_PA_01,PORT_GPIO_IP_PC_11};[!CR!][!//
static uint32 s_InMode_ETH_MII_RX_CLK[1] = {PORT_GPIO_IP_PA_01};[!CR!][!//
static uint32 s_InMode_ETH_RMII_REF_CLK[1] = {PORT_GPIO_IP_PA_01};[!CR!][!//
static uint32 s_InMode_TIM2_CH3[2] = {PORT_GPIO_IP_PA_02,PORT_GPIO_IP_PB_10};[!CR!][!//
static uint32 s_InMode_TIM5_CH3[2] = {PORT_GPIO_IP_PA_02,PORT_GPIO_IP_PH_12};[!CR!][!//
static uint32 s_InMode_TIM9_CH1[2] = {PORT_GPIO_IP_PA_02,PORT_GPIO_IP_PE_05};[!CR!][!//
static uint32 s_InMode_ETH_MDIO[1] = {PORT_GPIO_IP_PA_02};[!CR!][!//
static uint32 s_InMode_TIM2_CH4[2] = {PORT_GPIO_IP_PA_03,PORT_GPIO_IP_PB_11};[!CR!][!//
static uint32 s_InMode_TIM5_CH4[2] = {PORT_GPIO_IP_PA_03,PORT_GPIO_IP_PI_00};[!CR!][!//
static uint32 s_InMode_TIM9_CH2[2] = {PORT_GPIO_IP_PA_03,PORT_GPIO_IP_PE_06};[!CR!][!//
static uint32 s_InMode_USART2_RX[2] = {PORT_GPIO_IP_PA_03,PORT_GPIO_IP_PD_06};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_D0[1] = {PORT_GPIO_IP_PA_03};[!CR!][!//
static uint32 s_InMode_ETH_MII_COL[2] = {PORT_GPIO_IP_PA_03,PORT_GPIO_IP_PH_03};[!CR!][!//
static uint32 s_InMode_SPI1_NSS[2] = {PORT_GPIO_IP_PA_04,PORT_GPIO_IP_PA_15};[!CR!][!//
static uint32 s_InMode_SPI3_NSS[2] = {PORT_GPIO_IP_PA_04,PORT_GPIO_IP_PA_15};[!CR!][!//
static uint32 s_InMode_I2S3_WS[2] = {PORT_GPIO_IP_PA_04,PORT_GPIO_IP_PA_15};[!CR!][!//--->
static uint32 s_InMode_USART2_CK[2] = {PORT_GPIO_IP_PA_04,PORT_GPIO_IP_PD_07};[!CR!][!//
static uint32 s_InMode_OTG_HS_SOF[1] = {PORT_GPIO_IP_PA_04};[!CR!][!//
static uint32 s_InMode_DCMI_HSYNC[2] = {PORT_GPIO_IP_PA_04,PORT_GPIO_IP_PH_08};[!CR!][!//
static uint32 s_InMode_TIM8_BKIN[2] = {PORT_GPIO_IP_PA_06,PORT_GPIO_IP_PI_04};[!CR!][!//
static uint32 s_InMode_TIM8_CH1N[3] = {PORT_GPIO_IP_PA_05,PORT_GPIO_IP_PA_07,PORT_GPIO_IP_PH_13};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_CK[1] = {PORT_GPIO_IP_PA_05};[!CR!][!//
static uint32 s_InMode_TIM1_CH1N[2] = {PORT_GPIO_IP_PA_07,PORT_GPIO_IP_PE_08};[!CR!][!//
static uint32 s_InMode_TIM3_CH2[3] = {PORT_GPIO_IP_PA_07,PORT_GPIO_IP_PB_05,PORT_GPIO_IP_PC_07};[!CR!][!//
static uint32 s_InMode_DCMI_D13[2] = {PORT_GPIO_IP_PI_00,PORT_GPIO_IP_PF_15};[!CR!][!//
static uint32 s_InMode_TIM14_CH1[2] = {PORT_GPIO_IP_PA_07,PORT_GPIO_IP_PF_09};[!CR!][!//
static uint32 s_InMode_ETH_MII_RX_DV[1] = {PORT_GPIO_IP_PA_07,};[!CR!][!//
static uint32 s_InMode_ETH_RMII_CRS_DV[1] = {PORT_GPIO_IP_PA_07};[!CR!][!//
static uint32 s_InMode_MCO1[1] = {PORT_GPIO_IP_PA_01};[!CR!][!//
static uint32 s_InMode_TIM1_CH1[1] = {PORT_GPIO_IP_PA_08};[!CR!][!//
static uint32 s_InMode_USART1_CK[1] = {PORT_GPIO_IP_PA_08};[!CR!][!//
static uint32 s_InMode_OTG_FS_SOF[1] = {PORT_GPIO_IP_PA_08};[!CR!][!//
static uint32 s_InMode_TIM1_CH2[2] = {PORT_GPIO_IP_PA_09,PORT_GPIO_IP_PE_11};[!CR!][!//
static uint32 s_InMode_I2C3_SMBA[2] = {PORT_GPIO_IP_PA_09,PORT_GPIO_IP_PH_09};[!CR!][!//
static uint32 s_InMode_DCMI_D0[3] = {PORT_GPIO_IP_PA_09,PORT_GPIO_IP_PC_06,PORT_GPIO_IP_PH_09};[!CR!][!//
static uint32 s_InMode_TIM1_CH3[2] = {PORT_GPIO_IP_PA_10,PORT_GPIO_IP_PE_13};[!CR!][!//
static uint32 s_InMode_USART1_RX[2] = {PORT_GPIO_IP_PA_10,PORT_GPIO_IP_PB_07};[!CR!][!//
static uint32 s_InMode_OTG_FS_ID[1] = {PORT_GPIO_IP_PA_10};[!CR!][!//
static uint32 s_InMode_DCMI_D1[3] = {PORT_GPIO_IP_PA_10,PORT_GPIO_IP_PC_07,PORT_GPIO_IP_PH_10};[!CR!][!//
static uint32 s_InMode_TIM1_CH4[2] = {PORT_GPIO_IP_PA_11,PORT_GPIO_IP_PE_14};[!CR!][!//
static uint32 s_InMode_CAN1_RX[4] = {PORT_GPIO_IP_PA_11,PORT_GPIO_IP_PB_08,PORT_GPIO_IP_PD_00,PORT_GPIO_IP_PI_09};[!CR!][!//
static uint32 s_InMode_TIM1_ETR[2] = {PORT_GPIO_IP_PA_12,PORT_GPIO_IP_PE_07};[!CR!][!//
static uint32 s_InMode_USART1_RTS[1] = {PORT_GPIO_IP_PA_12};[!CR!][!//
static uint32 s_InMode_OTG_FS_DP[1] = {PORT_GPIO_IP_PA_12};[!CR!][!//
static uint32 s_InMode_JTMS_SWDIO[1] = {PORT_GPIO_IP_PA_13};[!CR!][!//
static uint32 s_InMode_JTCK_SWCLK[1] = {PORT_GPIO_IP_PA_14};[!CR!][!//
static uint32 s_InMode_JTDI[1] = {PORT_GPIO_IP_PA_15};[!CR!][!//
static uint32 s_InMode_TIM2_CH1[1] = {PORT_GPIO_IP_PA_15};[!CR!][!//
static uint32 s_InMode_TIM2_ETR[1] = {PORT_GPIO_IP_PA_15};[!CR!][!//
static uint32 s_InMode_FSMC_INT2[1] = {PORT_GPIO_IP_PF_06};[!CR!][!//
static uint32 s_InMode_FSMC_INT3[1] = {PORT_GPIO_IP_PF_07};[!CR!][!//
static uint32 s_InMode_UART6_CTS[1] = {PORT_GPIO_IP_PF_13};[!CR!][!//
static uint32 s_InMode_TIM1_CH2N[3] = {PORT_GPIO_IP_PB_00,PORT_GPIO_IP_PB_14,PORT_GPIO_IP_PE_10};[!CR!][!//
static uint32 s_InMode_DCMI_D12[1] = {PORT_GPIO_IP_PF_11};[!CR!][!//
static uint32 s_InMode_TIM3_CH3[2] = {PORT_GPIO_IP_PB_00,PORT_GPIO_IP_PC_08};[!CR!][!//
static uint32 s_InMode_TIM8_CH2N[3] = {PORT_GPIO_IP_PB_00,PORT_GPIO_IP_PB_14,PORT_GPIO_IP_PH_14};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_D1[1] = {PORT_GPIO_IP_PB_00};[!CR!][!//
static uint32 s_InMode_ETH_MII_RXD2[2] = {PORT_GPIO_IP_PB_00,PORT_GPIO_IP_PH_06};[!CR!][!//
static uint32 s_InMode_TIM1_CH3N[3] = {PORT_GPIO_IP_PB_01,PORT_GPIO_IP_PB_15,PORT_GPIO_IP_PE_12};[!CR!][!//
static uint32 s_InMode_TIM3_CH4[2] = {PORT_GPIO_IP_PB_01,PORT_GPIO_IP_PC_09};[!CR!][!//
static uint32 s_InMode_TIM8_CH3N[3] = {PORT_GPIO_IP_PB_01,PORT_GPIO_IP_PB_15,PORT_GPIO_IP_PH_15};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_D2[1] = {PORT_GPIO_IP_PB_01};[!CR!][!//
static uint32 s_InMode_ETH_MII_RXD3[2] = {PORT_GPIO_IP_PB_01,PORT_GPIO_IP_PH_07};[!CR!][!//
static uint32 s_InMode_JTDO[1] = {PORT_GPIO_IP_PB_03};[!CR!][!//
static uint32 s_InMode_TRACESWO[1] = {PORT_GPIO_IP_PB_03};[!CR!][!//
static uint32 s_InMode_FSMC_INTR[1] = {PORT_GPIO_IP_PF_10};[!CR!][!//
static uint32 s_InMode_SPI1_MISO[2] = {PORT_GPIO_IP_PB_04,PORT_GPIO_IP_PA_06};[!CR!][!//
static uint32 s_InMode_I2S3ext_SD[2] = {PORT_GPIO_IP_PB_04,PORT_GPIO_IP_PC_11};[!CR!][!//
static uint32 s_InMode_TIM13_CH1[2] = {PORT_GPIO_IP_PF_08,PORT_GPIO_IP_PA_06};[!CR!][!//
static uint32 s_InMode_CAN2_RX[2] = {PORT_GPIO_IP_PB_05,PORT_GPIO_IP_PB_12};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_D7[1] = {PORT_GPIO_IP_PB_05};[!CR!][!//
static uint32 s_InMode_DCMI_D10[2] = {PORT_GPIO_IP_PB_05,PORT_GPIO_IP_PI_03};[!CR!][!//
static uint32 s_InMode_TIM4_CH1[2] = {PORT_GPIO_IP_PB_06,PORT_GPIO_IP_PD_12};[!CR!][!//
static uint32 s_InMode_DCMI_D5[2] = {PORT_GPIO_IP_PB_06,PORT_GPIO_IP_PI_04};[!CR!][!//
static uint32 s_InMode_TIM4_CH2[2] = {PORT_GPIO_IP_PB_07,PORT_GPIO_IP_PD_13};[!CR!][!//
static uint32 s_InMode_TIM4_ETR[1] = {PORT_GPIO_IP_PE_00};[!CR!][!//
static uint32 s_InMode_FSMC_NL[1] = {PORT_GPIO_IP_PB_07};[!CR!][!//
static uint32 s_InMode_DCMI_VSYNC[2] = {PORT_GPIO_IP_PB_07,PORT_GPIO_IP_PI_05};[!CR!][!//
static uint32 s_InMode_TIM4_CH3[2] = {PORT_GPIO_IP_PB_08,PORT_GPIO_IP_PD_14};[!CR!][!//
static uint32 s_InMode_TIM10_CH1[2] = {PORT_GPIO_IP_PB_08,PORT_GPIO_IP_PF_06};[!CR!][!//
static uint32 s_InMode_FSMC_NWAIT[1] = {PORT_GPIO_IP_PD_06};[!CR!][!//
static uint32 s_InMode_ETH_MII_TXD3[2] = {PORT_GPIO_IP_PB_08,PORT_GPIO_IP_PE_02};[!CR!][!//
static uint32 s_InMode_SDIO_D4[1] = {PORT_GPIO_IP_PB_08};[!CR!][!//
static uint32 s_InMode_DCMI_D6[3] = {PORT_GPIO_IP_PB_08,PORT_GPIO_IP_PE_05,PORT_GPIO_IP_PI_06};[!CR!][!//
static uint32 s_InMode_TIM11_CH1[2] = {PORT_GPIO_IP_PB_09,PORT_GPIO_IP_PF_07};[!CR!][!//
static uint32 s_InMode_SDIO_D5[1] = {PORT_GPIO_IP_PB_09};[!CR!][!//
static uint32 s_InMode_DCMI_D7[3] = {PORT_GPIO_IP_PB_09,PORT_GPIO_IP_PE_06,PORT_GPIO_IP_PI_07};[!CR!][!//
static uint32 s_InMode_DCMI_D11[2] = {PORT_GPIO_IP_PD_02,PORT_GPIO_IP_PH_15};[!CR!][!//
static uint32 s_InMode_SPI2_SCK[3] = {PORT_GPIO_IP_PB_10,PORT_GPIO_IP_PB_13,PORT_GPIO_IP_PI_01};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_D3[1] = {PORT_GPIO_IP_PB_10};[!CR!][!//
static uint32 s_InMode_ETH_MII_RX_ER[2] = {PORT_GPIO_IP_PB_10,PORT_GPIO_IP_PI_10};[!CR!][!//
static uint32 s_InMode_UART5_RX[1] = {PORT_GPIO_IP_PD_02};[!CR!][!//
static uint32 s_InMode_USART3_RX[3] = {PORT_GPIO_IP_PB_11,PORT_GPIO_IP_PC_11,PORT_GPIO_IP_PD_09};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_D4[1] = {PORT_GPIO_IP_PA_01};[!CR!][!//
static uint32 s_InMode_TIM1_BKIN[1] = {PORT_GPIO_IP_PB_11};[!CR!][!//
static uint32 s_InMode_I2C2_SMBA[3] = {PORT_GPIO_IP_PB_12,PORT_GPIO_IP_PF_02,PORT_GPIO_IP_PH_06};[!CR!][!//
static uint32 s_InMode_TIM3_ETR[1] = {PORT_GPIO_IP_PD_02};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_D5[1] = {PORT_GPIO_IP_PB_12};[!CR!][!//
static uint32 s_InMode_OTG_HS_ID[1] = {PORT_GPIO_IP_PB_12};[!CR!][!//
static uint32 s_InMode_USART3_CTS[2] = {PORT_GPIO_IP_PB_13,PORT_GPIO_IP_PD_11};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_D6[1] = {PORT_GPIO_IP_PB_13};[!CR!][!//
static uint32 s_InMode_DCMI_D9[2] = {PORT_GPIO_IP_PC_12,PORT_GPIO_IP_PI_02};[!CR!][!//
static uint32 s_InMode_FSMC_D2[1] = {PORT_GPIO_IP_PD_00};[!CR!][!//
static uint32 s_InMode_SPI2_MISO[3] = {PORT_GPIO_IP_PB_14,PORT_GPIO_IP_PC_02,PORT_GPIO_IP_PI_02};[!CR!][!//
static uint32 s_InMode_I2S2ext_SD[3] = {PORT_GPIO_IP_PB_14,PORT_GPIO_IP_PC_02,PORT_GPIO_IP_PI_02};[!CR!][!//
static uint32 s_InMode_TIM12_CH1[2] = {PORT_GPIO_IP_PB_14,PORT_GPIO_IP_PH_06};[!CR!][!//
static uint32 s_InMode_OTG_HS_DM[1] = {PORT_GPIO_IP_PB_14};[!CR!][!//
static uint32 s_InMode_SPI3_MISO[1] = {PORT_GPIO_IP_PC_11};[!CR!][!//
static uint32 s_InMode_DCMI_D4[3] = {PORT_GPIO_IP_PC_11,PORT_GPIO_IP_PE_04,PORT_GPIO_IP_PH_14};[!CR!][!//
static uint32 s_InMode_TIM12_CH2[2] = {PORT_GPIO_IP_PB_15,PORT_GPIO_IP_PH_09};[!CR!][!//
static uint32 s_InMode_OTG_HS_DP[1] = {PORT_GPIO_IP_PB_15};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_STP[1] = {PORT_GPIO_IP_PC_00};[!CR!][!//
static uint32 s_InMode_ETH_MDC[1] = {PORT_GPIO_IP_PC_01};[!CR!][!//
static uint32 s_InMode_DCMI_D8[2] = {PORT_GPIO_IP_PC_10};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_DIR[2] = {PORT_GPIO_IP_PC_02,PORT_GPIO_IP_PI_11};[!CR!][!//
static uint32 s_InMode_OTG_HS_ULPI_NXT[2] = {PORT_GPIO_IP_PC_03,PORT_GPIO_IP_PH_04};[!CR!][!//
static uint32 s_InMode_ETH_MII_RXD0[1] = {PORT_GPIO_IP_PC_04};[!CR!][!//
static uint32 s_InMode_ETH_RMII_RXD0[1] = {PORT_GPIO_IP_PC_04};[!CR!][!//
static uint32 s_InMode_ETH_MII_RXD1[1] = {PORT_GPIO_IP_PC_05};[!CR!][!//
static uint32 s_InMode_ETH_RMII_RXD1[1] = {PORT_GPIO_IP_PC_05};[!CR!][!//
static uint32 s_InMode_I2S_CKIN[1] = {PORT_GPIO_IP_PC_09};[!CR!][!//
static uint32 s_InMode_TIM8_CH1[2] = {PORT_GPIO_IP_PC_06,PORT_GPIO_IP_PI_05};[!CR!][!//
static uint32 s_InMode_TIM8_CH4[2] = {PORT_GPIO_IP_PC_09,PORT_GPIO_IP_PI_02};[!CR!][!//
static uint32 s_InMode_TIM8_CH2[2] = {PORT_GPIO_IP_PC_07,PORT_GPIO_IP_PI_06};[!CR!][!//
static uint32 s_InMode_USART6_RX[2] = {PORT_GPIO_IP_PC_07,PORT_GPIO_IP_PF_09};[!CR!][!//
static uint32 s_InMode_TIM8_CH3[2] = {PORT_GPIO_IP_PC_08,PORT_GPIO_IP_PI_07};[!CR!][!//
static uint32 s_InMode_NJTRST[1] = {PORT_GPIO_IP_PB_04};[!CR!][!//
static uint32 s_InMode_I2C1_SCL[3] = {PORT_GPIO_IP_PB_06,PORT_GPIO_IP_PB_08,PORT_GPIO_IP_PB_06};[!CR!][!//
static uint32 s_InMode_I2C1_SDA[2] = {PORT_GPIO_IP_PB_07,PORT_GPIO_IP_PB_09};[!CR!][!//
static uint32 s_InMode_I2C2_SCL[3] = {PORT_GPIO_IP_PB_10,PORT_GPIO_IP_PF_01,PORT_GPIO_IP_PH_04};[!CR!][!//
static uint32 s_InMode_I2C2_SDA[3] = {PORT_GPIO_IP_PB_11,PORT_GPIO_IP_PF_00,PORT_GPIO_IP_PH_05};[!CR!][!//
static uint32 s_InMode_USART3_CK[3] = {PORT_GPIO_IP_PB_12,PORT_GPIO_IP_PC_12,PORT_GPIO_IP_PD_10};[!CR!][!//
static uint32 s_InMode_SPI1_SCK[2] = {PORT_GPIO_IP_PA_05,PORT_GPIO_IP_PB_03,};[!CR!][!//
static uint32 s_InMode_SPI3_SCK[2] = {PORT_GPIO_IP_PB_03,PORT_GPIO_IP_PC_10};[!CR!][!//
static uint32 s_InMode_I2S3_CK[2] = {PORT_GPIO_IP_PB_03,PORT_GPIO_IP_PC_10};[!CR!][!//
static uint32 s_InMode_SDIO_D6[1] = {PORT_GPIO_IP_PC_06};[!CR!][!//
static uint32 s_InMode_SDIO_D7[1] = {PORT_GPIO_IP_PC_07};[!CR!][!//
static uint32 s_InMode_SDIO_D0[1] = {PORT_GPIO_IP_PC_08};[!CR!][!//
static uint32 s_InMode_I2C3_SDA[2] = {PORT_GPIO_IP_PC_09,PORT_GPIO_IP_PH_08};[!CR!][!//
static uint32 s_InMode_SDIO_D1[1] = {PORT_GPIO_IP_PC_09};[!CR!][!//
static uint32 s_InMode_SDIO_D2[1] = {PORT_GPIO_IP_PC_10};[!CR!][!//
static uint32 s_InMode_SDIO_D3[1] = {PORT_GPIO_IP_PC_11};[!CR!][!//
static uint32 s_InMode_FSMC_D3[1] = {PORT_GPIO_IP_PD_01};[!CR!][!//
static uint32 s_InMode_SDIO_CMD[1] = {PORT_GPIO_IP_PD_02};[!CR!][!//
static uint32 s_InMode_FSMC_D13[1] = {PORT_GPIO_IP_PD_08};[!CR!][!//
static uint32 s_InMode_FSMC_D14[1] = {PORT_GPIO_IP_PD_09};[!CR!][!//
static uint32 s_InMode_FSMC_D15[2] = {PORT_GPIO_IP_PD_10};[!CR!][!//
static uint32 s_InMode_FSMC_D0[1] = {PORT_GPIO_IP_PD_14};[!CR!][!//
static uint32 s_InMode_FSMC_D1[1] = {PORT_GPIO_IP_PD_15};[!CR!][!//
static uint32 s_InMode_FSMC_D4[1] = {PORT_GPIO_IP_PE_07};[!CR!][!//
static uint32 s_InMode_FSMC_D5[1] = {PORT_GPIO_IP_PE_08};[!CR!][!//
static uint32 s_InMode_FSMC_D6[1] = {PORT_GPIO_IP_PE_09};[!CR!][!//
static uint32 s_InMode_FSMC_D7[1] = {PORT_GPIO_IP_PE_10};[!CR!][!//
static uint32 s_InMode_FSMC_D8[1] = {PORT_GPIO_IP_PE_11};[!CR!][!//
static uint32 s_InMode_FSMC_D9[1] = {PORT_GPIO_IP_PE_12};[!CR!][!//
static uint32 s_InMode_FSMC_D10[1] = {PORT_GPIO_IP_PE_13};[!CR!][!//
static uint32 s_InMode_FSMC_D11[1] = {PORT_GPIO_IP_PE_04};[!CR!][!//
static uint32 s_InMode_FSMC_D12[1] = {PORT_GPIO_IP_PE_15};[!CR!][!//
static uint32 s_InMode_I2S2_WS[2] = {PORT_GPIO_IP_PB_09,PORT_GPIO_IP_PB_12};[!CR!][!//
static uint32 s_InMode_USART1_CTS[1] = {PORT_GPIO_IP_PA_11};[!CR!][!//
static uint32 s_InMode_OTG_FS_DM[1] = {PORT_GPIO_IP_PA_11};[!CR!][!//
static uint32 s_InMode_TIM3_CH1[3] = {PORT_GPIO_IP_PA_06,PORT_GPIO_IP_PB_04,PORT_GPIO_IP_PC_06};[!CR!][!//
static uint32 s_InMode_TIM4_CH4[2] = {PORT_GPIO_IP_PB_09,PORT_GPIO_IP_PD_15};[!CR!][!//
static uint32 s_InMode_I2S2_CK[3] = {PORT_GPIO_IP_PB_10,PORT_GPIO_IP_PB_13,PORT_GPIO_IP_PI_01};[!CR!][!//
static uint32 s_InMode_DCMI_D3[3] = {PORT_GPIO_IP_PC_09,PORT_GPIO_IP_PE_01,PORT_GPIO_IP_PH_12};[!CR!][!//
static uint32 s_InMode_DCMI_D2[3] = {PORT_GPIO_IP_PC_08,PORT_GPIO_IP_PE_00,PORT_GPIO_IP_PH_11};[!CR!][!//
[!ENDCODE!][!//

[!CODE!]
/**
 *   @brief  Data struct containing information of input mode in Port driver.
 */
[!ENDCODE!]

[!CODE!]Port_Gpio_Ip_PinListType Port_Gpio_Ip_g_InMode[PORT_GPIO_IP_MAX_IN_MODE_VALUE] =[!CR!]{[!CR!][!ENDCODE!][!//
[!CODE!][!WS "4"!]{2, ALF_FUNCTION_1, s_InMode_TIM2_CH1_ETR},[!CR!][!//  
[!WS "4"!]{2, ALF_FUNCTION_2, s_InMode_TIM5_CH1},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_3, s_InMode_TIM8_ETR},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_11, s_InMode_ETH_MII_CRS},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_1, s_InMode_TIM2_CH2},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_2, s_InMode_TIM5_CH2},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_7, s_InMode_USART2_RTS},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_8, s_InMode_UART4_RX},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_8, s_InMode_ETH_MII_RX_CLK},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_11, s_InMode_ETH_RMII_REF_CLK},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_1, s_InMode_TIM2_CH3},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_2, s_InMode_TIM5_CH3},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_3, s_InMode_TIM9_CH1},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_11, s_InMode_ETH_MDIO},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_1, s_InMode_TIM2_CH4},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_2, s_InMode_TIM5_CH4},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_3, s_InMode_TIM9_CH2},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_7, s_InMode_USART2_RX},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_OTG_HS_ULPI_D0},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_11, s_InMode_ETH_MII_COL},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_5, s_InMode_SPI1_NSS},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_5, s_InMode_SPI3_NSS},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_6, s_InMode_I2S3_WS},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_7, s_InMode_USART2_CK},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_SOF},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_13, s_InMode_DCMI_HSYNC},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_3, s_InMode_TIM8_BKIN},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_3, s_InMode_TIM8_CH1N},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_CK},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_1, s_InMode_TIM1_CH1N},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_2, s_InMode_TIM3_CH2},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_11, s_InMode_DCMI_D13},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_13, s_InMode_TIM14_CH1},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_11, s_InMode_ETH_MII_RX_DV},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_11, s_InMode_ETH_RMII_CRS_DV},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_0, s_InMode_MCO1},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_1, s_InMode_TIM1_CH1},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_7, s_InMode_USART1_CK},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_FS_SOF},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_1, s_InMode_TIM1_CH2},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_4, s_InMode_I2C3_SMBA},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_13, s_InMode_DCMI_D0},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_1, s_InMode_TIM1_CH3},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_7, s_InMode_USART1_RX},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_FS_ID},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_13, s_InMode_DCMI_D1},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_1, s_InMode_TIM1_CH4},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_7, s_InMode_USART1_CTS},[!CR!][!//
[!WS "4"!]{4, ALF_FUNCTION_9, s_InMode_CAN1_RX},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_FS_DM},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_1, s_InMode_TIM1_ETR},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_7, s_InMode_USART1_RTS},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_FS_DP},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_0, s_InMode_JTMS_SWDIO},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_0, s_InMode_JTCK_SWCLK},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_0, s_InMode_JTDI},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_1, s_InMode_TIM2_CH1},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_1, s_InMode_TIM2_ETR},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_INT2},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_INT3},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_8, s_InMode_UART6_CTS},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_1, s_InMode_TIM1_CH2N},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_13, s_InMode_DCMI_D12},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_2, s_InMode_TIM3_CH3},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_3, s_InMode_TIM8_CH2N},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_D1},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_11, s_InMode_ETH_MII_RXD2},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_1, s_InMode_TIM1_CH3N},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_2, s_InMode_TIM3_CH4},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_3, s_InMode_TIM8_CH3N},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_D2},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_11, s_InMode_ETH_MII_RXD3},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_0, s_InMode_JTDO},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_0, s_InMode_TRACESWO},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_INTR},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_2, s_InMode_TIM3_CH1},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_5, s_InMode_SPI1_MISO},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_7, s_InMode_I2S3ext_SD},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_9, s_InMode_TIM13_CH1},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_9, s_InMode_CAN2_RX},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_D7},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_13, s_InMode_DCMI_D10},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_2, s_InMode_TIM4_CH1},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_13, s_InMode_DCMI_D5},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_2, s_InMode_TIM4_CH2},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_2, s_InMode_TIM4_ETR},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_11, s_InMode_FSMC_NL},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_11, s_InMode_DCMI_VSYNC},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_11, s_InMode_TIM4_CH3},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_3, s_InMode_TIM10_CH1},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_NWAIT},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_11, s_InMode_ETH_MII_TXD3},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_0, s_InMode_SDIO_D4},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_13, s_InMode_DCMI_D6},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_2, s_InMode_TIM4_CH4},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_3, s_InMode_TIM11_CH1},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_0, s_InMode_SDIO_D5},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_13, s_InMode_DCMI_D7},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_13, s_InMode_DCMI_D11},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_5, s_InMode_SPI2_SCK},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_5, s_InMode_I2S2_CK},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_D3},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_11, s_InMode_ETH_MII_RX_ER},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_8, s_InMode_UART5_RX},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_7, s_InMode_USART3_RX},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_D4},[!CR!]  [!//
[!WS "4"!]{1, ALF_FUNCTION_1, s_InMode_TIM1_BKIN},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_4, s_InMode_I2C2_SMBA},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_2, s_InMode_TIM3_ETR},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_D5},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_ID},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_7, s_InMode_USART3_CTS},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_D6},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_13, s_InMode_DCMI_D9},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D2},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_5, s_InMode_SPI2_MISO},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_5, s_InMode_I2S2ext_SD},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_9, s_InMode_TIM12_CH1},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_DM},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_6, s_InMode_SPI3_MISO},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_13, s_InMode_DCMI_D4},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_9, s_InMode_TIM12_CH2},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_DP},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_STP},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_11, s_InMode_ETH_MDC},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_13, s_InMode_DCMI_D3},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_13, s_InMode_DCMI_D8},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_DIR},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_10, s_InMode_OTG_HS_ULPI_NXT},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_11, s_InMode_ETH_MII_RXD0},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_11, s_InMode_ETH_RMII_RXD0},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_11, s_InMode_ETH_MII_RXD1},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_11, s_InMode_ETH_RMII_RXD1},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_5, s_InMode_I2S_CKIN},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_3, s_InMode_TIM8_CH1},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_13, s_InMode_DCMI_D2},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_3, s_InMode_TIM8_CH4},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_3, s_InMode_TIM8_CH2},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_8, s_InMode_USART6_RX},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_3, s_InMode_TIM8_CH3},[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_0, s_InMode_NJTRST},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_4, s_InMode_I2C1_SCL},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_4, s_InMode_I2C1_SDA},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_4, s_InMode_I2C2_SCL},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_4, s_InMode_I2C2_SDA},[!CR!][!//
[!WS "4"!]{3, ALF_FUNCTION_7, s_InMode_USART3_CK},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_5, s_InMode_SPI1_SCK},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_6, s_InMode_SPI3_SCK},[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_6, s_InMode_I2S3_CK },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_SDIO_D6 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_SDIO_D7 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_SDIO_D0 },[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_4, s_InMode_I2C3_SDA },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_SDIO_D1 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_SDIO_D2 },[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_5, s_InMode_I2S2_WS },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_SDIO_D3 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D3 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_SDIO_CMD },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D13 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D14 },[!CR!][!//
[!WS "4"!]{2, ALF_FUNCTION_12, s_InMode_FSMC_D15 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D0 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D1 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D4 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D5 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D6 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D7 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D8 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D9 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D10 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D11 },[!CR!][!//
[!WS "4"!]{1, ALF_FUNCTION_12, s_InMode_FSMC_D12 },[!CR!][!//
                    [!ENDCODE!][!//
                    [!CODE!][!CR!][!ENDCODE!]
                [!CODE!]};[!CR!][!ENDCODE!]

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
