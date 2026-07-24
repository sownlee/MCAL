/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Gpio_Ip_Types.h
 *
 * Description: Implementation of Dio_Gpio_Ip_Types IP Level layer
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

#ifndef DIO_GPIO_IP_TYPES_H
#define DIO_GPIO_IP_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Dio_Gpio_Ip_Devassert.h"

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


/**
 * @brief  Type of a DIO channel representation.
 */
typedef uint16 Dio_Gpio_Ip_ChannelType_u16;

/**
 * @brief  Type of a DIO channel levels representation.
 */
typedef uint8 Dio_Gpio_Ip_LevelType_u8;

/**
 * @brief  Type of a DIO port representation.
 */
typedef uint8 Dio_Gpio_Ip_PortType_u8;

/**
 * @brief   Type of a DIO port levels representation.
 */
typedef uint16 Dio_Gpio_Ip_PortLevelType_u16;

/**
 * @brief   Type for the definition of a channel group, which consists of several adjoining channels within a port
 * @details SRS ID:    SWS_Dio_HuLa_XXXXX
 *          Design ID: Dio_Gpio_Ip_ChannelGroupType_Class     
 */
typedef struct 
{
    Dio_Gpio_Ip_PortType_u8            Dio_Gpio_Ip_port;         /* This is the port address offset on which the channel group works. */
    uint8                              Dio_Gpio_Ip_offset_u8;    /* This is the position of the channel group on the port counted from the LSB */
    Dio_Gpio_Ip_PortLevelType_u16      Dio_Gpio_Ip_mask;         /* This is the mask which defines the positions of the channel group */
} Dio_Gpio_Ip_ChannelGroupType;

/**
 * @brief   Type of the external data structure containing the initialization data for this module.
 * @details SRS ID:    SWS_Dio_HuLa_XXXXX
 *          Design ID: Dio_Gpio_Ip_ConfigType_Class
 */
typedef struct
{
    uint8 NumChannelGroups_u8;                                                  /* Number of channel groups in configuration */
    const Dio_Gpio_Ip_ChannelGroupType *Dio_Gpio_Ip_c_ChannelGroupList_ptr;     /* Pointer to list of channel groups in configuration */
    const uint32 *Dio_Gpio_Ip_c_ChannelToPartitionMap_u32_ptr;                  /* Pointer to channel to partition mapping */
    const uint32 *Dio_Gpio_Ip_c_PortToPartitionMap_u32_ptr;                     /* Pointer to port to partition mapping */
} Dio_Gpio_Ip_ConfigType;


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

#endif /* DIO_GPIO_IP_TYPES_H */

/*--------------------------------------------------- EOF -----------------------------------------------------*/