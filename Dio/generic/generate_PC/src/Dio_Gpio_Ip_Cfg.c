[!CODE!][!//
[!AUTOSPACING!]
/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Dio_Gpio_Ip_Cfg.c
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

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES
 **********************************************************************************************************************/

#include "Dio_Gpio_Ip_Cfg.h"
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


#define START_CONST_32
#include "MemMap.h"

[!SELECT "DioConfig"!][!//
/**
* @brief Array containing list of mapping channel for partition
*/
const uint32 Dio_c_ChannelToPartitionMap_u32_a[DIO_GPIO_IP_CHANNEL_PARTITION_U16] =
{
[!NOCODE!][!//
[!FOR "x" = "0" TO "num:i(ecu:list('Dio.LastChannel')[1])"!][!//
    [!VAR "CounterDioEcucPartitionRef"="num:i(count(../DioGeneral/DioEcucPartitionRef/*))"!][!//
    [!VAR "PartitionChannelValue"="0"!][!//
    [!VAR "GetThePartitionNumber"="0"!][!//
    [!LOOP "./DioPort/*"!][!//
        [!VAR "PortId" = "num:i(node:fallback(./DioPortId,0))"!][!//
        [!LOOP "./DioChannel/*"!][!//
            [!VAR "PortChannelId" = "num:i(node:fallback(./DioChannelId,0))"!][!//
            [!VAR "ChannelId" = "num:i(32*$PortId + $PortChannelId)"!][!//
            [!IF "$ChannelId = $x"!][!//
                [!LOOP "DioChannelEcucPartitionRef/*"!][!//
                    [!VAR "DioCrtPart" = "node:value(.)"!][!//
                    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                        [!IF "$DioCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                            [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                                [!VAR "GetThePartitionNumber"="node:value(./EcucCoreId)"!][!//
                                [!VAR "PartitionChannelValue"="bit:or($PartitionChannelValue,(bit:shl(1,$GetThePartitionNumber)))"!][!//
                            [!ENDSELECT!][!//
                        [!ENDIF!][!//
                    [!ENDLOOP!][!//
                [!ENDLOOP!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!IF "$CounterDioEcucPartitionRef = 0"!][!//
        [!VAR "PartitionChannelValue"="1"!][!//
        [!VAR "CounterDioEcucPartitionRef"="num:i($CounterDioEcucPartitionRef + 1)"!][!//
    [!ENDIF!][!//
[!CODE!][!//
    (uint32)[!"num:inttohex($PartitionChannelValue, 16)"!][!IF "$x < num:i(ecu:list('Dio.LastChannel')[1])"!],[!CR!][!ENDIF!]
[!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!CR!]};

/**
* @brief Array containing list of mapping port for partition
*/
const uint32 Dio_c_PortToPartitionMap_u32_a[DIO_PORT_GPIO_IP_PARTITION_U16] =
{
[!NOCODE!][!//
[!FOR "x" = "0" TO "num:i(count(ecu:list('Dio.AvailablePortPinsForWrite'))-1)"!][!//
    [!VAR "CounterDioEcucPartitionRef"="num:i(count(../DioGeneral/DioEcucPartitionRef/*))"!][!//
    [!VAR "PartitionPortValue"="0"!][!//
    [!VAR "GetThePartitionNumber"="0"!][!//
    [!LOOP "./DioPort/*"!][!//
        [!IF "num:i(node:fallback(./DioPortId,0)) = $x"!][!//
            [!LOOP "DioPortEcucPartitionRef/*"!][!//
                [!VAR "DioCrtPart" = "node:value(.)"!][!//
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                    [!IF "$DioCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                        [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                            [!VAR "GetThePartitionNumber"="node:value(./EcucCoreId)"!][!//
                            [!VAR "PartitionPortValue"="bit:or($PartitionPortValue,(bit:shl(1,$GetThePartitionNumber)))"!][!//
                        [!ENDSELECT!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDLOOP!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$CounterDioEcucPartitionRef = 0"!][!//
        [!VAR "PartitionPortValue"="1"!][!//
        [!VAR "CounterDioEcucPartitionRef"="num:i($CounterDioEcucPartitionRef + 1)"!][!//
    [!ENDIF!][!//
[!CODE!][!//
    (uint32)[!"num:inttohex($PartitionPortValue, 16)"!][!IF "$x < num:i(count(ecu:list('Dio.AvailablePortPinsForWrite'))-1)"!],[!CR!][!ENDIF!]
[!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!CR!]};

[!ENDSELECT!][!//


[!VAR "NumPorts"="count(ecu:list('Dio.AvailablePortPinsForWrite'))"!][!//
const Dio_Gpio_Ip_PortLevelType_u16 Dio_c_AvailablePinsForWrite_a[DIO_GPIO_IP_NUM_PORTS_U16] =
{
[!FOR "Loop" = "1" TO "$NumPorts"!][!//
    (Dio_Gpio_Ip_PortLevelType_u16)[!"ecu:list('Dio.AvailablePortPinsForWrite')[num:dectoint($Loop)]"!]UL[!//
[!IF "$Loop < $NumPorts "!],[!CR!][!ENDIF!]
[!ENDFOR!][!//
[!CR!]};

[!VAR "NumPorts"="count(ecu:list('Dio.AvailablePortPinsForRead'))"!][!//
const Dio_Gpio_Ip_PortLevelType_u16 Dio_c_AvailablePinsForRead_a[DIO_GPIO_IP_NUM_PORTS_U16] =
{
[!FOR "Loop" = "1" TO "$NumPorts"!][!//
    (Dio_Gpio_Ip_PortLevelType_u16)[!"ecu:list('Dio.AvailablePortPinsForRead')[num:dectoint($Loop)]"!]UL[!//
[!IF "$Loop < $NumPorts "!],[!CR!][!ENDIF!]
[!ENDFOR!][!//
[!CR!]};

[!//
[!MACRO "reverse_bits"!][!//
[!NOCODE!]
    [!VAR "Orig_mask"="DioPortMask"!]
    [!VAR "Orig_offset"="DioPortOffset"!]
    [!IF "../../../../../DioGeneral/DioReversePortBits"!]
        [!VAR "Reversed_mask"="0"!]
        [!VAR "Found_1"="0"!]
        [!FOR "Loop" = "0" TO "31"!]
            [!VAR "crt_bit" = "bit:shr($Orig_mask,$Loop)"!]
            [!VAR "crt_bit"="bit:and($crt_bit, 1)"!]
            [!VAR "Reversed_mask"="bit:or($Reversed_mask,$crt_bit)"!]
            [!IF "$Loop != 31"!][!//
                [!VAR "Reversed_mask"="bit:shl($Reversed_mask, 1)"!]
            [!ENDIF!]
            [!IF "$Found_1=1 and $crt_bit=0"!]
                [!VAR "right_bits"="$Loop"!]
                [!VAR "Found_1"="0"!]
            [!ENDIF!]
            [!IF "$crt_bit = 1"!]
                [!VAR "Found_1"="1"!]
            [!ENDIF!][!//
        [!ENDFOR!]
    [!ELSE!]
        [!VAR "Reversed_mask"="DioPortMask"!]
    [!ENDIF!]
    [!VAR "Reversed_offset"="DioPortOffset"!]Dio_Gpio_Ip_LevelType_u8
[!ENDNOCODE!][!//
(uint8)[!"num:inttohex($Reversed_offset,2)"!], (Dio_Gpio_Ip_PortLevelType_u16)[!"num:inttohex($Reversed_mask,8)"!]UL}[!//
[!ENDMACRO!][!//

#define STOP_CONST_32
#include "MemMap.h"


#define START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

[!SELECT "DioConfig"!][!//
[!VAR "numChannelGroupsInConfig" = "count(DioPort/*/DioChannelGroup/*)"!][!//

[!IF "$numChannelGroupsInConfig != 0"!][!//
[!VAR "nameConfigGroups" = "as:name(.)"!][!//
/**
* @brief List of channel groups in configuration [!"as:name(.)"!].
*/
const Dio_Gpio_Ip_ChannelGroupType [!"as:name(.)"!]_ChannelGroupList_a[[!"num:dectoint($numChannelGroupsInConfig)"!]] =
{
[!INDENT "4"!][!//
[!VAR "i" = "0"!][!//
[!LOOP "DioPort/*"!][!//
    [!LOOP "DioChannelGroup/*"!][!//
        { DioCfg_Gpio_Ip_[!"node:name(./../..)"!], [!CALL "reverse_bits"!][!//
        [!VAR "i"="$i+1"!][!//
        [!IF "$i != $numChannelGroupsInConfig"!],[!ENDIF!]
    [!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDINDENT!][!//
[!CR!]};[!//

[!NOCODE!][!//
[!VAR "maxPartition" = "num:i(0)"!][!//
[!IF "node:value(../DioGeneral/DioMulticoreSupport)='true'"!]
    [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!][!//
        [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$maxPartition = 0"!][!//
    [!VAR "maxPartition" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/**
* @brief  List of channel groups mapping with partition in configuration [!"as:name(.)"!].
*/
const Dio_Gpio_Ip_ChannelGroupType * const Dio_c_ChannelGroupsListForEachPartition_ptr[[!"num:i($maxPartition)"!]][[!"num:i($numChannelGroupsInConfig)"!]] =
{
[!INDENT "4"!][!//
[!VAR "CounterDioEcucPartitionRef"="num:i(count(../DioGeneral/DioEcucPartitionRef/*))"!][!//
[!FOR "x" = "0" TO "num:i($maxPartition - 1)"!][!//
{
    [!VAR "ChannelGroupCounter" = "0"!][!//
    [!LOOP "DioPort/*/DioChannelGroup/*"!][!//
        [!VAR "Counter" = "0"!][!//
        [!LOOP "DioChannelGroupEcucPartitionRef/*"!][!//
            [!VAR "DioCrtPart" = "node:value(.)"!][!//
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                [!IF "$DioCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                    [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                        [!IF "$x = node:value(./EcucCoreId)"!][!//
                            [!VAR "Counter" = "$Counter + 1"!][!//
                        [!ENDIF!][!//
                    [!ENDSELECT!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
        [!IF "$CounterDioEcucPartitionRef = 0"!][!//
            [!WS "4"!]&[!"$nameConfigGroups"!]_ChannelGroupList_a[[!"num:i($ChannelGroupCounter)"!]][!IF "$ChannelGroupCounter < num:i($numChannelGroupsInConfig - 1)"!],[!ENDIF!]
        [!ELSE!][!//
            [!IF "$Counter = 0"!][!//
                [!WS "4"!]NULL_PTR[!IF "$ChannelGroupCounter < num:i($numChannelGroupsInConfig - 1)"!],[!ENDIF!]
            [!ELSE!][!//
                [!WS "4"!]&[!"$nameConfigGroups"!]_ChannelGroupList_a[[!"num:i($ChannelGroupCounter)"!]][!IF "$ChannelGroupCounter < num:i($numChannelGroupsInConfig - 1)"!],[!ENDIF!]
            [!ENDIF!][!//
        [!ENDIF!][!//
        [!VAR "ChannelGroupCounter" = "$ChannelGroupCounter + 1"!][!//
    [!ENDLOOP!][!//
    [!VAR "CounterDioEcucPartitionRef"="num:i($CounterDioEcucPartitionRef + 1)"!][!//
[!CR!]}[!IF "$x < ($maxPartition -1)"!],[!CR!][!ENDIF!]
[!ENDFOR!][!//
[!ENDINDENT!][!//
[!CR!]};
[!//
[!ENDIF!][!//

/**
* @brief  Data structure for configuration [!"as:name(.)"!].
*/
[!INDENT "0"!][!//
const Dio_Gpio_Ip_ConfigType Dio_Gpio_Ip_g_c_Config =
{
[!INDENT "4"!][!//
(uint8)[!"num:inttohex($numChannelGroupsInConfig)"!],
[!IF "$numChannelGroupsInConfig != 0"!][!//
    &[!"as:name(.)"!]_ChannelGroupList_a[0],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
Dio_c_ChannelToPartitionMap_u32_a,
Dio_c_PortToPartitionMap_u32_a
[!ENDINDENT!][!//
};

[!ENDINDENT!][!//
[!ENDSELECT!][!//
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
