/***********************************************************************************************************************
 * Project Name: Classic_Autosar_02
 * 
 * File Name: Port_Gpio_Ip_Types.h
 *
 * Description: Implementation of Port_Gpio_Ip_Types IP Level layer
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

#ifndef PORT_GPIO_IP_TYPES_H
#define PORT_GPIO_IP_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Gpio_Ip_Devassert.h"

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
/**
 *  @brief   This type contain status value in Port driver.
 *  @details SRS ID:     PORT_GPIO_IP_00008
 *           Design ID:  Port_Gpio_Ip_StatusType_Enumeration
 */
typedef enum
{
    PORT_GPIO_IP_STATUS_DISABLE = 0U, /* Status is Disable */
    PORT_GPIO_IP_STATUS_ENABLE        /* Status is Enable  */
} Port_Gpio_Ip_StatusType;

/**
 *  @brief   This type contain information of all input mode in port driver.
 *  @details SRS ID:     PORT_GPIO_IP_XXXXX
 *           Design ID:  Port_Gpio_Ip_PinListType_Class
 */
typedef struct
{
    uint8 NumberOfPin_u8;          /* Number of pin for each mode */
    uint32 AltFunction_Number_u32; /* Number of Alt Function  */
    uint32 *PinList_ptr;           /* Point to pin list variable */
} Port_Gpio_Ip_PinListType;

/**
 *  @brief   This type contain information of all output mode in port driver.
 *  @details SRS ID:     PORT_GPIO_IP_XXXXX
 *           Design ID:  Port_Gpio_Ip_PinInfoType_Class
 */
typedef struct
{
    uint8 NumberOfMode_u8;     /* Number of output mode for each pin */
    const uint32 *PinMode_ptr; /* Point to pin mode variable */
} Port_Gpio_Ip_PinInfoType;

/**
 *  @brief   This type contain all setting for specific pin in Port driver.
 *  @details SRS ID:     PORT_GPIO_IP_XXXXX
 *           Design ID:  Port_Gpio_Ip_PinSettingType_Class
 */
typedef struct
{
    uint32 OutEn_u32;          /* Output buffer enable                          */
    uint32 InEn_u32;           /* Input buffer enable                           */
    uint32 OutData_u32;        /* Set pin data to high or low                   */
    uint32 OpenDrain_u32;      /* Pin output type setting                       */
    uint32 PullType_u32;       /* Internal pull-up/down resistor setting        */
    uint32 OutLatchEn_u32;     /* Pin output latch setting                      */
    uint32 PinAttr_u32;        /* Digital or analog attribute setting           */
    uint32 OutFuncSel_u32;     /* Alternative function Output setting           */
    uint32 InFuncSel_u32;      /* Alternative function Input setting            */
    uint32 PortPinSpeed_u32;   /* Pin setting mode Speed                        */
} Port_Gpio_Ip_PinSettingType;

/**
 *  @brief   This type contain information for pin port pin.
 *  @details SRS ID:     PORT_GPIO_IP_00002
 *           Design ID:  Port_Gpio_Ip_PortPinType_Class
 */
typedef struct
{
    uint16 Pin_u16;                   /* Pin number                        */
    uint8 Port_u8;                    /* Port number                       */
    uint8 PortPinIndex_u8;            /* Port Pin Index                    */
    uint8 GpioNumber_u8;              /* Order of Port Pin in config set   */
    uint8 DebugPort_u8;               /* Debug Port                        */
    uint8 Direction_u8;               /* Direction of Pin                  */
    uint8 ExternalInterrupt_u8;       /* ExternalInterrupt Falling/Rising  */
    boolean ModeChangeable_bool;      /* Mode changeable for Pin           */
    boolean DirectionChangeable_bool; /* Direction changeable for Pin      */
} Port_Gpio_Ip_PortPinType;

/**
 *  @brief   This type contain data of all pin config in Port driver.
 *  @details SRS ID:     PORT_GPIO_IP_00004
 *           Design ID:  Port_Gpio_Ip_PinConfigType_Class
 */
typedef struct
{
    const Port_Gpio_Ip_PinInfoType *AllModePinInfo_ptr;       /* Structure contain All mode information for pin */
    const Port_Gpio_Ip_PinInfoType *PinInfo_ptr;              /* Structure contain out mode information for pin */
    const Port_Gpio_Ip_PinSettingType *PinSetting_ptr;        /* Structure contain all setting for pin    */
    const Port_Gpio_Ip_PortPinType *PortPin_ptr;              /* Structure contain information for pin    */
} Port_Gpio_Ip_PinConfigType;

/**
 *  @brief   This type contain information of un-used pin in Port driver.
 *  @details SRS ID:     PORT_GPIO_IP_XXXXX
 *           Design ID:  Port_Gpio_Ip_UnusedPinConfigType_Class
 */
typedef struct
{
    uint16 Pin_u16; /* Pin number  */
    uint8 Port_u8;  /* Port number */
} Port_Gpio_Ip_UnusedPinConfigType;

/**
 *  @brief   Type of the external data structure containing the initialization data for Port module.
 *  @details SRS ID:     PORT_GPIO_IP_XXXXX
 *           Design ID:  Port_Gpio_Ip_ConfigType_Class
 */
 typedef struct
{
    Port_Gpio_Ip_PinListType *PinList_ptr;                       /* Structure contain input mode information for port driver    */
    const Port_Gpio_Ip_PinConfigType *PinConfig_ptr;             /* Structure contain Pin config of all port pin      */
    const Port_Gpio_Ip_UnusedPinConfigType *UnUsedPinConfig_ptr; /* Structure contain information of un-used Port Pin */
    uint8 NumUnusedPin_u8;                                       /* Number of un-used Pin in config set               */
    uint8 NumPins_u8;                                            /* Number of Pin in config set                       */
} Port_Gpio_Ip_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* PORT_GPIO_IP_TYPES_H */

/*--------------------------------------------------- End Of File -----------------------------------------------------*/
