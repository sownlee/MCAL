[!CODE!][!//
[!AUTOSPACING!][!//
/***********************************************************************************************************************
 * Project Name: Classic_Autosar_02
 * 
 * File Name: Port_Gpio_Ip_Cfg.h
 *
 * Description: Implementation of Port_Gpio_Ip_Cfg High Level layer
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

#ifndef PORT_IP_CFG_H
#define PORT_IP_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
#include "Port_Gpio_Ip_[!"."!]_PBcfg.h"
[!ENDLOOP!][!//
[!ELSE!][!//
#include "Port_Gpio_Ip_PBcfg.h"
[!ENDIF!][!//
#include "Port_Gpio_Ip_Types.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

 /**
 * @brief   Definition of software version number at IP layer.
 */
#define PORT_GPIO_IP_CFG_SW_MAJOR_VERSION        0U
#define PORT_GPIO_IP_CFG_SW_MINOR_VERSION        0U
#define PORT_GPIO_IP_CFG_SW_PATCH_VERSION        1U

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/
 /**
 * @brief   Definition of Port external configure at IP layer.
 */
#define PORT_IP_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
        PORT_IP_CONFIG_[!"."!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
        PORT_IP_CONFIG_PB
[!ENDIF!]

/**
 * @brief   Count the currently defined number of PortPin.
 *
 */
[!SELECT "PortConfigSet/PortContainer"!][!//
#define PORT_GPIO_IP_NUM_OF_PIN_CONFIG                        ([!"num:i(count(*/PortPin/*))"!]U)
[!ENDSELECT!][!//

/**
 * @brief   PortPin mode definition.
 *
 */
[!CODE!]
/* -----IN--------- */
#define PORT_GPIO_IP_IN_MODE_TIM2_CH1_ETR                          (0U)
#define PORT_GPIO_IP_IN_MODE_TIM5_CH1                              (1U)
#define PORT_GPIO_IP_IN_MODE_TIM8_ETR                              (2U)
#define PORT_GPIO_IP_IN_MODE_ETH_MII_CRS                           (3U)                       
#define PORT_GPIO_IP_IN_MODE_TIM2_CH2                              (4U)
#define PORT_GPIO_IP_IN_MODE_TIM5_CH2                              (5U)
#define PORT_GPIO_IP_IN_MODE_USART2_RTS                            (6U)
#define PORT_GPIO_IP_IN_MODE_UART4_RX                              (7U)
#define PORT_GPIO_IP_IN_MODE_ETH_MII_RX_CLK                        (8U)
#define PORT_GPIO_IP_IN_MODE_ETH_RMII_REF_CLK                      (9U)
#define PORT_GPIO_IP_IN_MODE_TIM2_CH3                              (10U)
#define PORT_GPIO_IP_IN_MODE_TIM5_CH3                              (11U)
#define PORT_GPIO_IP_IN_MODE_TIM9_CH1                              (12U)
#define PORT_GPIO_IP_IN_MODE_ETH_MDIO                              (13U)
#define PORT_GPIO_IP_IN_MODE_TIM2_CH4                              (14U)
#define PORT_GPIO_IP_IN_MODE_TIM5_CH4                              (15U)
#define PORT_GPIO_IP_IN_MODE_TIM9_CH2                              (16U)
#define PORT_GPIO_IP_IN_MODE_USART2_RX                             (17U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D0                        (18U)
#define PORT_GPIO_IP_IN_MODE_ETH_MII_COL                           (19U)
#define PORT_GPIO_IP_IN_MODE_SPI1_NSS                              (20U)
#define PORT_GPIO_IP_IN_MODE_SPI3_NSS                              (21U)
#define PORT_GPIO_IP_IN_MODE_I2S3_WS                               (22U)
#define PORT_GPIO_IP_IN_MODE_USART2_CK                             (23U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_SOF                            (24U)
#define PORT_GPIO_IP_IN_MODE_DCMI_HSYNC                            (25U)
#define PORT_GPIO_IP_IN_MODE_TIM8_BKIN                             (26U)
#define PORT_GPIO_IP_IN_MODE_TIM8_CH1N                             (27U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_CK                        (28U)
#define PORT_GPIO_IP_IN_MODE_TIM1_CH1N                             (29U)
#define PORT_GPIO_IP_IN_MODE_TIM3_CH2                              (30U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D13                              (31U)
#define PORT_GPIO_IP_IN_MODE_TIM14_CH1                             (32U)
#define PORT_GPIO_IP_IN_MODE_ETH_MII_RX_DV                         (33U)
#define PORT_GPIO_IP_IN_MODE_ETH_RMII_CRS_DV                       (34U)
#define PORT_GPIO_IP_IN_MODE_MCO1                                  (35U)
#define PORT_GPIO_IP_IN_MODE_TIM1_CH1                              (36U)
#define PORT_GPIO_IP_IN_MODE_USART1_CK                             (37U)
#define PORT_GPIO_IP_IN_MODE_OTG_FS_SOF                            (38U)
#define PORT_GPIO_IP_IN_MODE_TIM1_CH2                              (39U)
#define PORT_GPIO_IP_IN_MODE_I2C3_SMBA                             (40U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D0                               (41U)
#define PORT_GPIO_IP_IN_MODE_TIM1_CH3                              (42U)
#define PORT_GPIO_IP_IN_MODE_USART1_RX                             (43U)
#define PORT_GPIO_IP_IN_MODE_OTG_FS_ID                             (44U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D1                               (45U)
#define PORT_GPIO_IP_IN_MODE_TIM1_CH4                              (46U)
#define PORT_GPIO_IP_IN_MODE_USART1_CTS                            (47U)
#define PORT_GPIO_IP_IN_MODE_CAN1_RX                               (48U)
#define PORT_GPIO_IP_IN_MODE_OTG_FS_DM                             (49U)
#define PORT_GPIO_IP_IN_MODE_TIM1_ETR                              (50U)
#define PORT_GPIO_IP_IN_MODE_USART1_RTS                            (51U)
#define PORT_GPIO_IP_IN_MODE_OTG_FS_DP                             (52U)
#define PORT_GPIO_IP_IN_MODE_JTMS_SWDIO                            (53U)
#define PORT_GPIO_IP_IN_MODE_JTCK_SWCLK                            (54U)
#define PORT_GPIO_IP_IN_MODE_JTDI                                  (55U)
#define PORT_GPIO_IP_IN_MODE_TIM2_CH1                              (56U)
#define PORT_GPIO_IP_IN_MODE_TIM2_ETR                              (57U)
#define PORT_GPIO_IP_IN_MODE_FSMC_INT2                             (58U)
#define PORT_GPIO_IP_IN_MODE_FSMC_INT3                             (59U)
#define PORT_GPIO_IP_IN_MODE_UART6_CTS                             (60U)
#define PORT_GPIO_IP_IN_MODE_TIM1_CH2N                             (61U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D12                              (62U)
#define PORT_GPIO_IP_IN_MODE_TIM3_CH3                              (63U)
#define PORT_GPIO_IP_IN_MODE_TIM8_CH2N                             (64U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D1                        (65U)
#define PORT_GPIO_IP_IN_MODE_ETH_MII_RXD2                          (66U)
#define PORT_GPIO_IP_IN_MODE_TIM1_CH3N                             (67U)
#define PORT_GPIO_IP_IN_MODE_TIM3_CH4                              (68U)
#define PORT_GPIO_IP_IN_MODE_TIM8_CH3N                             (69U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D2                        (70U)
#define PORT_GPIO_IP_IN_MODE_ETH_MII_RXD3                          (71U)
#define PORT_GPIO_IP_IN_MODE_JTDO                                  (72U)
#define PORT_GPIO_IP_IN_MODE_TRACESWO                              (73U)
#define PORT_GPIO_IP_IN_MODE_FSMC_INTR                             (74U)
#define PORT_GPIO_IP_IN_MODE_TIM3_CH1                              (75U)
#define PORT_GPIO_IP_IN_MODE_SPI1_MISO                             (76U)
#define PORT_GPIO_IP_IN_MODE_I2S3ext_SD                            (77U)
#define PORT_GPIO_IP_IN_MODE_TIM13_CH1                             (78U)
#define PORT_GPIO_IP_IN_MODE_CAN2_RX                               (79U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D7                        (80U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D10                              (81U)
#define PORT_GPIO_IP_IN_MODE_TIM4_CH1                              (82U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D5                               (83U)
#define PORT_GPIO_IP_IN_MODE_TIM4_CH2                              (84U)
#define PORT_GPIO_IP_IN_MODE_TIM4_ETR                              (85U)
#define PORT_GPIO_IP_IN_MODE_FSMC_NL                               (86U)
#define PORT_GPIO_IP_IN_MODE_DCMI_VSYNC                            (87U)
#define PORT_GPIO_IP_IN_MODE_TIM4_CH3                              (88U)
#define PORT_GPIO_IP_IN_MODE_TIM10_CH1                             (89U)
#define PORT_GPIO_IP_IN_MODE_FSMC_NWAIT                            (90U)
#define PORT_GPIO_IP_IN_MODE_ETH_MII_TXD3                          (91U)
#define PORT_GPIO_IP_IN_MODE_SDIO_D4                               (92U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D6                               (93U)
#define PORT_GPIO_IP_IN_MODE_TIM4_CH4                              (94U)
#define PORT_GPIO_IP_IN_MODE_TIM11_CH1                             (95U)
#define PORT_GPIO_IP_IN_MODE_SDIO_D5                               (96U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D7                               (97U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D11                              (98U)
#define PORT_GPIO_IP_IN_MODE_SPI2_SCK                              (99U)
#define PORT_GPIO_IP_IN_MODE_I2S2_CK                               (100U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D3                        (101U)
#define PORT_GPIO_IP_IN_MODE_ETH_MII_RX_ER                         (102U)
#define PORT_GPIO_IP_IN_MODE_UART5_RX                              (103U)
#define PORT_GPIO_IP_IN_MODE_USART3_RX                             (104U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D4                        (105U)
#define PORT_GPIO_IP_IN_MODE_TIM1_BKIN                             (106U)
#define PORT_GPIO_IP_IN_MODE_I2C2_SMBA                             (107U)
#define PORT_GPIO_IP_IN_MODE_TIM3_ETR                              (124U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D5                        (109U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ID                             (110U)
#define PORT_GPIO_IP_IN_MODE_USART3_CTS                            (111U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_D6                        (112U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D9                               (113U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D2                               (114U)
#define PORT_GPIO_IP_IN_MODE_SPI2_MISO                             (115U)
#define PORT_GPIO_IP_IN_MODE_I2S2ext_SD                            (116U)
#define PORT_GPIO_IP_IN_MODE_TIM12_CH1                             (117U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_DM                             (118U)
#define PORT_GPIO_IP_IN_MODE_SPI3_MISO                             (119U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D4                               (120U)
#define PORT_GPIO_IP_IN_MODE_TIM12_CH2                             (121U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_DP                             (122U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_STP                       (123U)
#define PORT_GPIO_IP_IN_MODE_ETH_MDC                               (124U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D3                               (125U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D8                               (126U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_DIR                       (127U)
#define PORT_GPIO_IP_IN_MODE_OTG_HS_ULPI_NXT                       (128U)
#define PORT_GPIO_IP_IN_MODE_ETH_MII_RXD0                          (129U)
#define PORT_GPIO_IP_IN_MODE_ETH_RMII_RXD0                         (130U)
#define PORT_GPIO_IP_IN_MODE_ETH_MII_RXD1                          (131U)
#define PORT_GPIO_IP_IN_MODE_ETH_RMII_RXD1                         (132U)
#define PORT_GPIO_IP_IN_MODE_I2S_CKIN                              (133U)
#define PORT_GPIO_IP_IN_MODE_TIM8_CH1                              (134U)
#define PORT_GPIO_IP_IN_MODE_DCMI_D2                               (135U)
#define PORT_GPIO_IP_IN_MODE_TIM8_CH4                              (136U)
#define PORT_GPIO_IP_IN_MODE_TIM8_CH2                              (137U)
#define PORT_GPIO_IP_IN_MODE_USART6_RX                             (138U)
#define PORT_GPIO_IP_IN_MODE_TIM8_CH3                              (139U)
#define PORT_GPIO_IP_IN_MODE_NJTRST                                (140U)
#define PORT_GPIO_IP_IN_MODE_I2C1_SCL                              (141U)
#define PORT_GPIO_IP_IN_MODE_I2C1_SDA                              (142U)
#define PORT_GPIO_IP_IN_MODE_I2C2_SCL                              (143U)
#define PORT_GPIO_IP_IN_MODE_I2C2_SDA                              (144U)
#define PORT_GPIO_IP_IN_MODE_USART3_CK                             (145U)
#define PORT_GPIO_IP_IN_MODE_SPI1_SCK                              (146U)
#define PORT_GPIO_IP_IN_MODE_SPI3_SCK                              (147U)
#define PORT_GPIO_IP_IN_MODE_I2S3_CK                               (148U)
#define PORT_GPIO_IP_IN_MODE_SDIO_D6                               (149U)
#define PORT_GPIO_IP_IN_MODE_SDIO_D7                               (150U)
#define PORT_GPIO_IP_IN_MODE_SDIO_D0                               (151U)
#define PORT_GPIO_IP_IN_MODE_I2C3_SDA                              (152U)
#define PORT_GPIO_IP_IN_MODE_SDIO_D1                               (153U)
#define PORT_GPIO_IP_IN_MODE_SDIO_D2                               (154U)
#define PORT_GPIO_IP_IN_MODE_I2S2_WS                               (155U)
#define PORT_GPIO_IP_IN_MODE_SDIO_D3                               (156U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D3                               (157U)
#define PORT_GPIO_IP_IN_MODE_SDIO_CMD                              (158U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D13                              (159U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D14                              (160U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D15                              (161U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D0                               (162U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D1                               (163U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D4                               (164U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D5                               (165U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D6                               (166U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D7                               (167U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D8                               (168U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D9                               (169U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D10                              (170U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D11                              (171U)
#define PORT_GPIO_IP_IN_MODE_FSMC_D12                              (172U)

/* ----OUT---------- */
#define PORT_GPIO_IP_OUT_MODE_UART5_TX                             (179U)
#define PORT_GPIO_IP_OUT_MODE_USART3_CK                            (280U)
#define PORT_GPIO_IP_OUT_MODE_SDIO_CK                              (181U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_CLK                             (182U)
#define PORT_GPIO_IP_OUT_MODE_USART2_RTS                           (183U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NOE                             (184U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NWE                             (185U)
#define PORT_GPIO_IP_OUT_MODE_USART2_CK                            (186U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NE1                             (187U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NCE2                            (188U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A16                             (189U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A17                             (190U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A18                             (191U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NBL0                            (192U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NBL1                            (193U)
#define PORT_GPIO_IP_OUT_MODE_TRACECLK                             (194U)
#define PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD3                         (195U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A23                             (196U)
#define PORT_GPIO_IP_OUT_MODE_TRACED0                              (197U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A19                             (198U)
#define PORT_GPIO_IP_OUT_MODE_TRACED1                              (199U)
#define PORT_GPIO_IP_OUT_MODE_TRACED2                              (200U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A21                             (201U)
#define PORT_GPIO_IP_OUT_MODE_TRACED3                              (202U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A22                             (203U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A0                              (204U)
#define PORT_GPIO_IP_OUT_MODE_I2C2_SCL                             (205U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A1                              (206U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A2                              (207U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A3                              (208U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A4                              (209U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A5                              (210U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NIORD                           (211U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NREG                            (212U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NIOWR                           (213U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_CD                              (214U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A6                              (215U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A7                              (216U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A8                              (217U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A9                              (218U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A10                             (219U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A11                             (220U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A12                             (221U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A13                             (222U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A14                             (223U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A15                             (224U)
#define PORT_GPIO_IP_OUT_MODE_USART6_RTS                           (225U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NE2                             (226U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NCE3                            (227U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NCE4_1                          (228U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NE3                             (229U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NCE4_2                          (230U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_NE4                             (231U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A24                             (232U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A25                             (233U)
#define PORT_GPIO_IP_OUT_MODE_I2C3_SCL                             (235U)
#define PORT_GPIO_IP_OUT_MODE_DCMI_D10                             (236U)
#define PORT_GPIO_IP_OUT_MODE_USART2_CTS                           (237U)
#define PORT_GPIO_IP_OUT_MODE_UART4_TX                             (238U)
#define PORT_GPIO_IP_OUT_MODE_USART2_TX                            (239U)
#define PORT_GPIO_IP_OUT_MODE_SPI1_MOSI                            (240U)
#define PORT_GPIO_IP_OUT_MODE_USART1_TX                            (241U)
#define PORT_GPIO_IP_OUT_MODE_CAN1_TX                              (242U)
#define PORT_GPIO_IP_OUT_MODE_I2C1_SMBA                            (243U)
#define PORT_GPIO_IP_OUT_MODE_SPI3_MOSI                            (244U)
#define PORT_GPIO_IP_OUT_MODE_I2S3_SD                              (245U)
#define PORT_GPIO_IP_OUT_MODE_ETH_PPS_OUT                          (246U)
#define PORT_GPIO_IP_OUT_MODE_CAN2_TX                              (247U)
#define PORT_GPIO_IP_OUT_MODE_SPI2_NS                              (248U)
#define PORT_GPIO_IP_OUT_MODE_I2S2_WS                              (249U)
#define PORT_GPIO_IP_OUT_MODE_USART3_TX                            (250U)
#define PORT_GPIO_IP_OUT_MODE_ETH_MII_TX_EN                        (251U)
#define PORT_GPIO_IP_OUT_MODE_ETH_RMII_TX_EN                       (252U)
#define PORT_GPIO_IP_OUT_MODE_SPI2_NSS                             (253U)
#define PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD0                         (254U)
#define PORT_GPIO_IP_OUT_MODE_ETH_RMII_TXD0                        (255U)
#define PORT_GPIO_IP_OUT_MODE_SPI2_SCK                             (256U)
#define PORT_GPIO_IP_OUT_MODE_I2S2_CK                              (257U)
#define PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD1                         (258U)
#define PORT_GPIO_IP_OUT_MODE_ETH_RMII_TXD1                        (259U)
#define PORT_GPIO_IP_OUT_MODE_USART3_RTS                           (260U)
#define PORT_GPIO_IP_OUT_MODE_SPI2_MOSI                            (261U)
#define PORT_GPIO_IP_OUT_MODE_I2S2_SD                              (262U)
#define PORT_GPIO_IP_OUT_MODE_OTG_HS_ULPI_STP                      (263U)
#define PORT_GPIO_IP_OUT_MODE_ETH_MII_TXD2                         (264U)
#define PORT_GPIO_IP_OUT_MODE_ETH_I2S2_SD                          (265U)
#define PORT_GPIO_IP_OUT_MODE_ETH_MII_TX_CLK                       (266U)
#define PORT_GPIO_IP_OUT_MODE_I2S2_MCK                             (267U)
#define PORT_GPIO_IP_OUT_MODE_USART6_TX                            (268U)
#define PORT_GPIO_IP_OUT_MODE_I2S3_MCK                             (269U)
#define PORT_GPIO_IP_OUT_MODE_MCO2                                 (270U)
#define PORT_GPIO_IP_OUT_MODE_USART6_CK                            (271U)
#define PORT_GPIO_IP_OUT_MODE_SPI3_SCK                             (272U)
#define PORT_GPIO_IP_OUT_MODE_I2S3_CK                              (273U)
#define PORT_GPIO_IP_OUT_MODE_USART6_CTS                           (274U)
#define PORT_GPIO_IP_OUT_MODE_FSMC_A20                             (275U)

#define PORT_GPIO_IP_OUT_MODE_GPO                                  (276U)
#define PORT_GPIO_IP_IN_MODE_GPI                                   (277U)
#define PORT_GPIO_IP_IN_MODE_GPIO                                  (278U)

#define NULL_ALT_FUNCTION                                          (500U)

/**
 * @brief   PortPin index definition
 *
 */
#define PORT_GPIO_IP_PA_00                                 (0U)
#define PORT_GPIO_IP_PA_01                                 (1U)
#define PORT_GPIO_IP_PA_02                                 (2U)
#define PORT_GPIO_IP_PA_03                                 (3U)
#define PORT_GPIO_IP_PA_04                                 (4U)
#define PORT_GPIO_IP_PA_05                                 (5U)
#define PORT_GPIO_IP_PA_06                                 (6U)
#define PORT_GPIO_IP_PA_07                                 (7U)
#define PORT_GPIO_IP_PA_08                                 (8U)
#define PORT_GPIO_IP_PA_09                                 (9U)
#define PORT_GPIO_IP_PA_10                                 (10U)
#define PORT_GPIO_IP_PA_11                                 (11U)
#define PORT_GPIO_IP_PA_12                                 (12U)
#define PORT_GPIO_IP_PA_13                                 (13U)
#define PORT_GPIO_IP_PA_14                                 (14U)
#define PORT_GPIO_IP_PA_15                                 (15U)
#define PORT_GPIO_IP_PB_00                                 (16U)
#define PORT_GPIO_IP_PB_01                                 (17U)
#define PORT_GPIO_IP_PB_02                                 (18U)
#define PORT_GPIO_IP_PB_03                                 (19U)
#define PORT_GPIO_IP_PB_04                                 (20U)
#define PORT_GPIO_IP_PB_05                                 (21U)
#define PORT_GPIO_IP_PB_06                                 (22U)
#define PORT_GPIO_IP_PB_07                                 (23U)
#define PORT_GPIO_IP_PB_08                                 (24U)
#define PORT_GPIO_IP_PB_09                                 (25U)
#define PORT_GPIO_IP_PB_10                                 (26U)
#define PORT_GPIO_IP_PB_11                                 (27U)
#define PORT_GPIO_IP_PB_12                                 (28U)
#define PORT_GPIO_IP_PB_13                                 (29U)
#define PORT_GPIO_IP_PB_14                                 (30U)
#define PORT_GPIO_IP_PB_15                                 (31U)
#define PORT_GPIO_IP_PC_00                                 (32U)
#define PORT_GPIO_IP_PC_01                                 (33U)
#define PORT_GPIO_IP_PC_02                                 (34U)
#define PORT_GPIO_IP_PC_03                                 (35U)
#define PORT_GPIO_IP_PC_04                                 (36U)
#define PORT_GPIO_IP_PC_05                                 (37U)
#define PORT_GPIO_IP_PC_06                                 (38U)
#define PORT_GPIO_IP_PC_07                                 (39U)
#define PORT_GPIO_IP_PC_08                                 (40U)
#define PORT_GPIO_IP_PC_09                                 (41U)
#define PORT_GPIO_IP_PC_10                                 (42U)
#define PORT_GPIO_IP_PC_11                                 (43U)
#define PORT_GPIO_IP_PC_12                                 (44U)
#define PORT_GPIO_IP_PC_13                                 (45U)
#define PORT_GPIO_IP_PC_14                                 (46U)
#define PORT_GPIO_IP_PC_15                                 (47U)
#define PORT_GPIO_IP_PD_00                                 (48U)
#define PORT_GPIO_IP_PD_01                                 (49U)
#define PORT_GPIO_IP_PD_02                                 (50U)
#define PORT_GPIO_IP_PD_03                                 (51U)
#define PORT_GPIO_IP_PD_04                                 (52U)
#define PORT_GPIO_IP_PD_05                                 (53U)
#define PORT_GPIO_IP_PD_06                                 (54U)
#define PORT_GPIO_IP_PD_07                                 (55U)
#define PORT_GPIO_IP_PD_08                                 (56U)
#define PORT_GPIO_IP_PD_09                                 (57U)
#define PORT_GPIO_IP_PD_10                                 (58U)
#define PORT_GPIO_IP_PD_11                                 (59U)
#define PORT_GPIO_IP_PD_12                                 (61U)
#define PORT_GPIO_IP_PD_13                                 (62U)
#define PORT_GPIO_IP_PD_14                                 (63U)
#define PORT_GPIO_IP_PD_15                                 (64U)
#define PORT_GPIO_IP_PE_00                                 (65U)
#define PORT_GPIO_IP_PE_01                                 (66U)
#define PORT_GPIO_IP_PE_02                                 (67U)
#define PORT_GPIO_IP_PE_03                                 (68U)
#define PORT_GPIO_IP_PE_04                                 (69U)
#define PORT_GPIO_IP_PE_05                                 (70U)
#define PORT_GPIO_IP_PE_06                                 (71U)
#define PORT_GPIO_IP_PE_07                                 (72U)
#define PORT_GPIO_IP_PE_08                                 (73U)
#define PORT_GPIO_IP_PE_09                                 (74U)
#define PORT_GPIO_IP_PE_10                                 (75U)
#define PORT_GPIO_IP_PE_11                                 (76U)
#define PORT_GPIO_IP_PE_12                                 (77U)
#define PORT_GPIO_IP_PE_13                                 (78U)
#define PORT_GPIO_IP_PE_14                                 (79U)
#define PORT_GPIO_IP_PE_15                                 (80U)
#define PORT_GPIO_IP_PF_00                                 (81U)
#define PORT_GPIO_IP_PF_01                                 (82U)
#define PORT_GPIO_IP_PF_02                                 (83U)
#define PORT_GPIO_IP_PF_03                                 (84U)
#define PORT_GPIO_IP_PF_04                                 (85U)
#define PORT_GPIO_IP_PF_05                                 (86U)
#define PORT_GPIO_IP_PF_06                                 (87U)
#define PORT_GPIO_IP_PF_07                                 (88U)
#define PORT_GPIO_IP_PF_08                                 (89U)
#define PORT_GPIO_IP_PF_09                                 (90U)
#define PORT_GPIO_IP_PF_10                                 (91U)
#define PORT_GPIO_IP_PF_11                                 (92U)
#define PORT_GPIO_IP_PF_12                                 (93U)
#define PORT_GPIO_IP_PF_13                                 (94U)
#define PORT_GPIO_IP_PF_14                                 (95U)
#define PORT_GPIO_IP_PF_15                                 (96U)
#define PORT_GPIO_IP_PG_00                                 (97U)
#define PORT_GPIO_IP_PG_01                                 (98U)
#define PORT_GPIO_IP_PG_02                                 (99U)
#define PORT_GPIO_IP_PG_03                                 (100U)
#define PORT_GPIO_IP_PG_04                                 (101U)
#define PORT_GPIO_IP_PG_05                                 (102U)
#define PORT_GPIO_IP_PG_06                                 (103U)
#define PORT_GPIO_IP_PG_07                                 (104U)
#define PORT_GPIO_IP_PG_08                                 (105U)
#define PORT_GPIO_IP_PG_09                                 (106U)
#define PORT_GPIO_IP_PG_10                                 (107U)
#define PORT_GPIO_IP_PG_11                                 (124U)
#define PORT_GPIO_IP_PG_12                                 (109U)
#define PORT_GPIO_IP_PG_13                                 (110U)
#define PORT_GPIO_IP_PG_14                                 (111U)
#define PORT_GPIO_IP_PG_15                                 (112U)
#define PORT_GPIO_IP_PH_00                                 (113U)
#define PORT_GPIO_IP_PH_01                                 (114U)
#define PORT_GPIO_IP_PH_02                                 (115U)
#define PORT_GPIO_IP_PH_03                                 (116U)
#define PORT_GPIO_IP_PH_04                                 (117U)
#define PORT_GPIO_IP_PH_05                                 (118U)
#define PORT_GPIO_IP_PH_06                                 (119U)
#define PORT_GPIO_IP_PH_07                                 (120U)
#define PORT_GPIO_IP_PH_08                                 (121U)
#define PORT_GPIO_IP_PH_09                                 (122U)
#define PORT_GPIO_IP_PH_10                                 (123U)
#define PORT_GPIO_IP_PH_11                                 (124U)
#define PORT_GPIO_IP_PH_12                                 (125U)
#define PORT_GPIO_IP_PH_13                                 (126U)
#define PORT_GPIO_IP_PH_14                                 (127U)
#define PORT_GPIO_IP_PH_15                                 (128U)
#define PORT_GPIO_IP_PI_00                                 (129U)
#define PORT_GPIO_IP_PI_01                                 (130U)
#define PORT_GPIO_IP_PI_02                                 (131U)
#define PORT_GPIO_IP_PI_03                                 (132U)
#define PORT_GPIO_IP_PI_04                                 (133U)
#define PORT_GPIO_IP_PI_05                                 (134U)
#define PORT_GPIO_IP_PI_06                                 (135U)
#define PORT_GPIO_IP_PI_07                                 (136U)
#define PORT_GPIO_IP_PI_08                                 (137U)
#define PORT_GPIO_IP_PI_09                                 (138U)
#define PORT_GPIO_IP_PI_10                                 (139U)
#define PORT_GPIO_IP_PI_11                                 (140U)
#define PORT_GPIO_IP_PI_12                                 (141U)
#define PORT_GPIO_IP_PI_13                                 (142U)
#define PORT_GPIO_IP_PI_14                                 (143U)
#define PORT_GPIO_IP_PI_15                                 (144U)

[!ENDCODE!][!//

#define ALF_FUNCTION_0                                      (0U)
#define ALF_FUNCTION_1                                      (1U)
#define ALF_FUNCTION_2                                      (2U)
#define ALF_FUNCTION_3                                      (3U)
#define ALF_FUNCTION_4                                      (4U)
#define ALF_FUNCTION_5                                      (5U)
#define ALF_FUNCTION_6                                      (6U)
#define ALF_FUNCTION_7                                      (7U)
#define ALF_FUNCTION_8                                      (8U)
#define ALF_FUNCTION_9                                      (9U)
#define ALF_FUNCTION_10                                     (10U)
#define ALF_FUNCTION_11                                     (11U)
#define ALF_FUNCTION_12                                     (12U)
#define ALF_FUNCTION_13                                     (13U)
#define ALF_FUNCTION_14                                     (14U)
#define ALF_FUNCTION_15                                     (15U)

/**
 * @brief   Max value of Input mode.
 *
 */
#define PORT_GPIO_IP_MAX_IN_MODE_VALUE                      (173U)

/**
 * @brief   Enable or Disable Development Error Detection.
 */
#define PORT_GPIO_IP_DEV_ERROR_DETECT           [!IF "PortGeneral/PortDevErrorDetect"!][!WS "8"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief   Enable or disable Port_Gpio_Ip_SetPinDirection API function.
 */
#define PORT_GPIO_IP_SET_PIN_DIRECTION_API      [!IF "PortGeneral/PortSetPinDirectionApi"!][!WS "8"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief   Enable or disable Port_Gpio_Ip_SetPinMode API function.
 */
#define PORT_GPIO_IP_SET_PIN_MODE_API           [!IF "PortGeneral/PortSetPinModeApi"!][!WS "8"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


/**
 * @brief   Enable or disable Port_Gpio_Ip_ReSetPinMode API function.
 */
#define PORT_GPIO_IP_RESET_PIN_MODE_API           [!IF "PortGeneral/PortResetPinModeApi"!][!WS "8"!](STD_ON)[!ELSE!][!WS "4"!](STD_OFF)[!ENDIF!]


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

extern Port_Gpio_Ip_PinListType Port_Gpio_Ip_g_InMode[PORT_GPIO_IP_MAX_IN_MODE_VALUE];

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

#endif /* PORT_IP_CFG_H */

/*--------------------------------------------------- End Of File -----------------------------------------------------*/
[!ENDCODE!][!//
