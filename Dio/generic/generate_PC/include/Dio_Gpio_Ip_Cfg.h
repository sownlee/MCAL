[!CODE!][!//
[!AUTOSPACING!]
/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Gpio_Ip_Cfg.h
 *
 * Description: Implementation of Dio_Gpio_Ip_Cfg IP Level layer
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

#ifndef DIO_IP_CFG_H
#define DIO_IP_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "Dio_Gpio_Ip_Types.h"

/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/**
 * @brief   Definition of software version number at IP layer.
 */
#define DIO_GPIO_IP_CFG_SW_MAJOR_VERSION        1U
#define DIO_GPIO_IP_CFG_SW_MINOR_VERSION        0U
#define DIO_GPIO_IP_CFG_SW_PATCH_VERSION        0U

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/
 
 /**
 * @brief  Definition for Dio configure at IP layer.
 */
#define DIO_IP_CONFIG_PC \
                    extern const Dio_Gpio_Ip_ConfigType Dio_Gpio_Ip_g_c_Config;


[!SELECT "DioConfig"!][!//
[!INDENT "0"!][!//
[!VAR "ChannelGroupNumber" = "count(DioPort/*/DioChannelGroup/*)"!][!//
[!IF "$ChannelGroupNumber != 0"!][!//
/**
 * @brief  Dio Gpio Ip driver Channel Groups configuration switch.
 */
#define DIO_GPIO_IP_CHANNEL_GROUPS_AVAILABLE
[!ENDIF!][!//
[!ENDINDENT!][!//
[!ENDSELECT!][!//

[!NOCODE!][!//
[!VAR "NumPortsForWrite"="count(ecu:list('Dio.AvailablePortPinsForRead'))"!]
[!VAR "NumPortsForRead"="count(ecu:list('Dio.AvailablePortPinsForWrite'))"!]
[!IF "$NumPortsForWrite != $NumPortsForRead"!]
    [!ERROR!]The number ports in Dio.AvailablePortPinsForRead  and Dio.AvailablePortPinsForWrite were not same value in resource file[!ENDERROR!]
[!ENDIF!]
[!ENDNOCODE!][!//

[!NOCODE!][!//
/**
 * @brief   The number of partition on the platform. Used for channel, port and channel group validation.        
 */
[!VAR "maxPartition" = "num:i(0)"!][!//
[!IF "node:value(DioGeneral/DioMulticoreSupport)='true'"!]
    [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!][!//
        [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$maxPartition = 0"!][!//
    [!VAR "maxPartition" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//



 /**
 * @brief  Enable/disable development error detection for Gpio Ip API
 */
#define DIO_GPIO_IP_DEV_ERROR_DETECT      ([!IF "DioGeneral/DioPortIPDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


/**
 * @brief  Enable or disable Dio_GetVersionInfo API IP function.
 */
#define DIO_GPIO_IP_VERSION_INFO_API    [!IF "DioGeneral/DioVersionInfoApi"!][!WS "8"!]STD_ON[!ELSE!][!WS "4"!]STD_OFF[!ENDIF!]


/**
 * @brief  Enable or disable Dio_FlipChannel API IP function.
 */
#define DIO_GPIO_IP_FLIP_CHANNEL_API    [!IF "DioGeneral/DioFlipChannelApi"!][!WS "8"!]STD_ON[!ELSE!][!WS "4"!]STD_OFF[!ENDIF!]


/**
 * @brief  Enable or disable DioMaskedWritePort API IP function.
 */
#define DIO_GPIO_IP_MASKEDWRITEPORT_API [!IF "DioGeneral/DioMaskedWritePortApi"!][!WS "8"!]STD_ON[!ELSE!][!WS "4"!]STD_OFF[!ENDIF!]


/**
 * @brief  Enable or disable Dio_ReadZeroForUndefinedPortPins API IP function.
 */
#define DIO_GPIO_IP_READZERO_UNDEFINEDPORTS [!IF "DioGeneral/DioReadZeroForUndefinedPortPins"!][!WS "8"!]STD_ON[!ELSE!][!WS "4"!]STD_OFF[!ENDIF!]


/**
 * @brief  Enable/Disable multicore IP function from the driver
 */
#define DIO_GPIO_IP_MULTICORE_ENABLED          [!IF "DioGeneral/DioMulticoreSupport"!][!WS "8"!]STD_ON[!ELSE!][!WS "4"!]STD_OFF[!ENDIF!]



/**
 * @brief  Channel number of the platform.
 */
#if (STD_ON == DIO_GPIO_IP_DEV_ERROR_DETECT)
    #define DIO_GPIO_IP_CHANNEL_NUMBER            ((uint16)[!"num:i(ecu:get('Dio.LastChannel'))"!]U)
#endif


/**
 * @brief  Port number of the platform.
 */
#define DIO_GPIO_IP_NUM_PORTS_U16               ((uint16)[!"num:inttohex(count(ecu:list('Dio.AvailablePortPinsForWrite')))"!])


/**
 * @brief  The number of partition on the port.
 */
#define DIO_PORT_GPIO_IP_PARTITION_U16          ((uint16)[!"num:i(count(ecu:list('Dio.AvailablePortPinsForWrite')))"!]U)


/**
* @brief  The number of partition on the channel.Used for channel validation.        
*/
#define DIO_GPIO_IP_CHANNEL_PARTITION_U16            ((uint16)[!"num:i(num:i(ecu:list('Dio.LastChannel')) + 1)"!]U)


/**
 * @brief  Port pin number of the platform.
 */
#define DIO_GPIO_IP_MAX_CHANNEL_ID             ((uint16)[!"num:i(ecu:get('Dio.MaxPinNumber')-1)"!]U)


/**
 * @brief   Enable or Disable Port driver Pre-Compile configuration.
 */
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' and variant:size()<=1"!][!//
#define DIO_GPIO_IP_PRECOMPILE_SUPPORT     (STD_ON)
[!ELSE!][!//
#define DIO_GPIO_IP_PRECOMPILE_SUPPORT     (STD_OFF)
[!ENDIF!][!//

/************************************DIO GPIO IP CONFIG*******************************************************/
[!SELECT "DioConfig"!][!//
[!VAR "ChannelGroupNumber" = "count(DioPort/*/DioChannelGroup/*)"!][!//
/**
 * @brief  Data structure for configuration [!"as:name(.)"!].
 */
#define DIO_GPIO_IP_NUM_CHANNELSGROUP_U32 [!WS "8"!]((uint32)[!"num:i($ChannelGroupNumber)"!]U)
#define DIO_GPIO_IP_NUM_CHANNELSGROUP_MOD_16_U32 [!WS "8"!]((uint32)[!"num:i(num:i(num:i($ChannelGroupNumber) div 16) + 1)"!]U)

[!VAR "ConfigName"="as:name(.)"!][!//
[!VAR "ChannelGroupdIdx"="0"!][!//
[!LOOP "DioPort/*"!][!/*
    */!][!VAR "PortId" = "DioPortId"!][!//

/**
 * @brief  Symbolic name for the port [!"node:name(.)"!].
 */
#define DioCfg_Gpio_Ip_[!"node:name(.)"!]  ((uint8)[!"num:inttohex($PortId,2)"!]U)

[!LOOP "DioChannel/*"!]
[!INDENT "0"!][!//
    [!VAR "PortChannelId" = "DioChannelId"!]
    [!VAR "ChannelId" = "16*$PortId + $PortChannelId"!][!//
    [!IF "(num:i(count(DioGeneral/DioEcucPartitionRef/*)) > 0) and (num:i(count(DioChannelEcucPartitionRef/*)) = 0)"!][!//
        [!ERROR!]The partition of Channel [!"$PortChannelId"!] in port [!"$PortId"!] was not configured[!ENDERROR!]
    [!ENDIF!][!//
/**
 * @brief  Symbolic name for the channel [!"node:name(.)"!].
 */
#define  DioCfg_Gpio_Ip_DioChannel_[!"node:name(.)"!] ((uint16)[!"num:inttohex($ChannelId,4)"!]U)

[!ENDINDENT!][!//
[!ENDLOOP!][!//
[!LOOP "DioChannelGroup/*"!][!//
[!INDENT "0"!][!//
    [!IF "(num:i(count(DioGeneral/DioEcucPartitionRef/*)) > 0) and (0 = num:i(count(DioChannelGroupEcucPartitionRef/*)))"!][!//
        [!ERROR!]The partition of ChannelGroupId [!"node:name(.)"!] in port [!"$PortId"!] was not configured[!ENDERROR!]
    [!ENDIF!][!//
/**
 * @brief  Symbolic name for the channel group [!"node:name(.)"!].
 *
 */
#define DioCfg_Gpio_Ip_ChannelGroupId_[!"node:name(.)"!]    (&[!"$ConfigName"!]_ChannelGroupList_a[[!"num:dectoint($ChannelGroupdIdx)"!]])[!//

[!VAR "ChannelGroupdIdx" = "$ChannelGroupdIdx + 1"!][!//
[!ENDINDENT!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//


[!ENDSELECT!][!//

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

#define START_CONST_32
#include "MemMap.h"
/**
* @brief Array containing list of mapping channel for partition
*/
extern const uint32 Dio_c_ChannelToPartitionMap_u32_a[DIO_GPIO_IP_CHANNEL_PARTITION_U16];

/**
* @brief Array containing list of mapping port for partition
*/
extern const uint32 Dio_c_PortToPartitionMap_u32_a[DIO_PORT_GPIO_IP_PARTITION_U16];

/**
* @brief Array of bitmaps of output pins available per port
*/
extern const Dio_Gpio_Ip_PortLevelType_u16 Dio_c_AvailablePinsForWrite_a[DIO_GPIO_IP_NUM_PORTS_U16];

/**
* @brief Array of bitmaps of input pins available per port
*/
extern const Dio_Gpio_Ip_PortLevelType_u16 Dio_c_AvailablePinsForRead_a[DIO_GPIO_IP_NUM_PORTS_U16];

#define STOP_CONST_32
#include "MemMap.h"

[!SELECT "DioConfig"!][!//
[!//
[!VAR "numChannelGroupsInConfig" = "count(DioPort/*/DioChannelGroup/*)"!][!//
[!IF "$numChannelGroupsInConfig != 0"!][!//

#define START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/**
* @brief  List of channel groups in configuration [!"node:name(.)"!].
*/
extern const Dio_Gpio_Ip_ChannelGroupType [!"as:name(.)"!]_ChannelGroupList_a[[!"num:dectoint($numChannelGroupsInConfig)"!]];

/**
* @brief  List of channel groups mapping with partition in configuration [!"node:name(.)"!].
*/
extern const Dio_Gpio_Ip_ChannelGroupType * const Dio_c_ChannelGroupsListForEachPartition_ptr[[!"num:i($maxPartition)"!]][[!"num:i($numChannelGroupsInConfig)"!]];

#define STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

[!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!//
[!LOOP "DioConfig/*/DioPort/*"!][!/*
    */!][!VAR "crt_name"="node:name(.)"!][!/*
    */!][!VAR "n"="0"!][!/*
    */!][!LOOP "../../DioPort/*"!][!/*
        */!][!IF "$crt_name=node:name(.)"!][!VAR "n"="$n+1"!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
    */!][!IF "$n > 1"!][!ERROR "Port name duplicated. Port names must be unique even across configurations"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!LOOP "DioConfig/DioPort/*/DioChannelGroup/*"!][!/*
    */!][!VAR "crt_name"="node:name(.)"!][!/*
    */!][!VAR "n"="0"!][!/*
    */!][!LOOP "../../../../DioPort/*/DioChannelGroup/*"!][!/*
        */!][!IF "$crt_name=node:name(.)"!][!VAR "n"="$n+1"!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
    */!][!IF "$n > 1"!][!ERROR "ChannelGroup name duplicated. Channel group names must be unique even across ports and configurations"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!LOOP "DioConfig/DioPort/*/DioChannel/*"!][!/*
    */!][!VAR "crt_name"="node:name(.)"!][!/*
    */!][!VAR "n"="0"!][!/*
    */!][!LOOP "../../../../DioPort/*/DioChannel/*"!][!/*
        */!][!IF "$crt_name=node:name(.)"!][!VAR "n"="$n+1"!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
    */!][!IF "$n > 1"!][!ERROR "Channel name duplicated. Channel names must be unique even across ports and configurations"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!//

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

#endif /* DIO_IP_CFG_H */

/*--------------------------------------------------- End Of File -----------------------------------------------------*/
[!ENDCODE!][!//