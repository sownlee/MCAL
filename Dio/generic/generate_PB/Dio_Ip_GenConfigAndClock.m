[!NOCODE!]

[!MACRO "Uart_GenAllConfig","Type"!][!//
[!NOCODE!]
[!CODE!]
/**
* @brief    Data structure for the Uart driver.
*/
Uart_Ip_ConfigType Uart_Ip_g_c_ConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_st =
{
    /* Number Uart configuration. */
    (Uart_Ip_ConfigSetNumberType)[!"num:i(count(UartConfigSet/UARTConfig/*))"!]U,

    /* State machine and Error code of Uart. */
    (Uart_Ip_StateType){
        UART_DRIVER_UNINIT,
        UART_ERRORCODE_NO_ERROR
    },

    /* State Structure Uart. */
    (Uart_Ip_StateStructureType){
        NULL_PTR,
        NULL_PTR,
        0,
        0,
        FALSE,
        FALSE
    },
    
    /* Uart data configuration. */
    [!IF "num:i(count(UartConfigSet/UARTConfig/*))>0"!]&Uart_Ip_EachConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_a[!ELSE!](NULL_PTR)[!ENDIF!]
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!ENDNOCODE!]
