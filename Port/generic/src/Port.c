/***********************************************************************************************************************
 * Project Name: Classic_Autosar_02
 * 
 * File Name: Port.c
 *
 * Description: Implementation of PORT High Level layer
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

#include "Port.h"
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#include "Port_VersionInfo.h"

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
#if (STD_ON == PORT_PRECOMPILE_SUPPORT)
#define START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/**
 * @brief  Extern variable to get data from generated config
 */
extern const Port_ConfigType Port_g_c_Config;
#define STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#endif

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
#define START_CODE
#include "MemMap.h"

/**
 *  @brief          Initializes the Port Driver module.
 *
 *  @details        
 *                  Service ID:        0x00
 *                  SRS ID:            SWS_Port_00001,SWS_Port_00002,SWS_Port_00079
 *                                     SWS_Port_00081,SWS_Port_00005,SWS_Port_00140
 *                                     SWS_Port_00041,SWS_Port_00042,SWS_Port_00043
 *                                     SWS_Port_00004,SWS_Port_00121,SWS_Port_00232
 *                                     SWS_Port_00113,SWS_Port_HuLa_00003
 *                                     SWS_Port_HuLa_00007,SWS_Port_00075
 *                                     SWS_Port_CONSTR_00233,SWS_Port_00051,SWS_Port_00087
 *                  Design ID:         Port_Init_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            Port_ConfigType *    
 *  @param[in]      ConfigPtr          Pointer to configuration set.
 *
 *  @return         void     
 *  @retval         None                                
 *
 *  @note           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Port_Init(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr
)
{
    
}

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/**
 *  @brief          Set the port pin direction.
 *
 *  @details
 *                  Service ID:        0x01
 *                  SRS ID:            SWS_Port_00051,SWS_Port_00054,SWS_Port_00063
 *                                     SWS_Port_00077,SWS_Port_00086,SWS_Port_00087
 *                                     SWS_Port_00137,SWS_Port_00138,SWS_Port_00141
 *                                     SWS_Port_00146,SWS_Port_HuLa_00002,SWS_Port_HuLa_00005
 *                  Design ID:         Port_SetPinDirection_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            Port_PinType  
 *  @param[in]      Pin                 Port Pin ID number.
 *  @arg            Port_PinDirectionType  
 *  @param[in]      Direction           Port Pin Direction.
 *
 *  @return         void     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            Port_Init must have been called.
 *
 *  @post           None
 *
 **/
void Port_SetPinDirection(
    Port_PinType Pin,
    Port_PinDirectionType Direction
)
{

}
#endif /*(STD_ON == PORT_SET_PIN_DIRECTION_API)*/

/**
 *  @brief          Refresh port pin direction.
 *
 *  @details        
 *                  Service ID:        0x02
 *                  SRS ID:            SWS_Port_00060,SWS_Port_00061,SWS_Port_00066
 *                                     SWS_Port_00077,SWS_Port_00087,SWS_Port_00142
 *                                     SWS_Port_00146
 *                  Design ID:         Port_RefreshPortDirection_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Non Reentrant
 *
 *  @arg            None
 *  @param[in]      None
 *
 *  @return         None     
 *  @retval         None     
 *
 *  @note           None
 *
 *  @pre            Port_Init must have been called.
 *
 *  @post           None
 *
 **/
void Port_RefreshPortDirection(
    void
)
{

}

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
 *  @brief          Set the port pin mode.
 *
 *  @details        
 *                  Service ID:        0x03
 *                  SRS ID:            SWS_Port_00051,SWS_Port_00077,SWS_Port_00087
 *                                     SWS_Port_00125,SWS_Port_00128,SWS_Port_00145
 *                                     SWS_Port_00146,SWS_Port_00212,SWS_Port_00214
 *                                     SWS_Port_00223,SWS_Port_HuLa_00004
 *                  Design ID:         Port_SetPinMode_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            Port_PinType
 *  @param[in]      Pin                Port Pin ID number
 *  @arg            Port_PinModeType
 *  @param[in]      Mode               New Port Pin mode to be set on port pin
 *
 *  @return         None     
 *  @retval         None   
 *
 *  @note           None
 *  
 *  @pre            Port_Init must have been called.
 *
 *  @post           None
 *
 **/
void Port_SetPinMode(
    Port_PinType Pin,
    Port_PinModeType Mode
)
{

}
#endif /*(STD_ON == PORT_SET_PIN_MODE_API)*/

#if (STD_ON == PORT_RESET_PIN_MODE_API)
/**
 *  @brief          Reset the port pin mode.
 *
 *  @details        
 *                  Service ID:        0x04
 *                  SRS ID:            SWS_Port_HuLa_00008
 *                  Design ID:         Port_ReSetPinMode_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            Port_PinType
 *  @param[in]      Pin                Port Pin ID number
 *
 *  @return         None     
 *  @retval         None   
 *
 *  @note           None
 *  
 *  @pre            Port_Init must have been called.
 *
 *  @post           None
 *
 **/
void Port_ReSetPinMode(
    VAR(Port_PinType, AUTOMATIC) Pin
)
{

}
#endif /*(STD_ON == PORT_RESET_PIN_MODE_API)*/

#if (STD_ON == PORT_VERSION_INFO_API)
/**
 *  @brief          Returns the version information of this module.
 *
 *  @details        
 *                  Service ID:        0x05
 *                  SRS ID:            SWS_Port_00077,SWS_Port_00087,SWS_Port_00129
 *                                     SWS_Port_00143,SWS_Port_00146,SWS_Port_00225
 *                  Design ID:         Port_GetVersionInfo_Activity
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            Versioninfo *
 *  @param[in]      versioninfo        Pointer to where to store the version information of this module.
 *
 *  @return         None     
 *  @retval         None    
 *
 *  @note           None
 *
 *  @pre            None
 *
 *  @post           None
 *  
 *  @pre            None
 *
 *  @post           None
 *
 **/
void Port_GetVersionInfo(
    Std_VersionInfoType *versioninfo
)
{

}
#endif /*(STD_ON == PORT_VERSION_INFO_API)*/


#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- End Of File -----------------------------------------------------*/
