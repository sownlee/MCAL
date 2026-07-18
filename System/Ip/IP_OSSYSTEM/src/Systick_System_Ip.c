/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Systick_System_Ip.c
 *
 * Description: Implementation of Systick_System_Ip High Level layer
 *              
 * AutoSAR Version:         4.4.0
 *
 * Compiler: GCC IAR
 *
 * Revision:
 *              Version         Date                Change History
 *              0.9.0          23/02/2024           Initial version
 *
 **********************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES
 **********************************************************************************************************************/
#include "Systick_System_Ip.h"

/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
/* Common Published Information */
#define SYSTICK_SYSTEM_IP_VENDOR_ID_C                      15
#define SYSTICK_SYSTEM_IP_MODULE_ID_C                      255

/* AUTOSAR release version information */
#define SYSTICK_SYSTEM_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define SYSTICK_SYSTEM_IP_AR_RELEASE_MINOR_VERSION_C       4
#define SYSTICK_SYSTEM_IP_AR_RELEASE_REVISION_VERSION_C    0

/* File version information */
#define SYSTICK_SYSTEM_IP_SW_MAJOR_VERSION_C               0
#define SYSTICK_SYSTEM_IP_SW_MINOR_VERSION_C               9
#define SYSTICK_SYSTEM_IP_SW_PATCH_VERSION_C               0
/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/
#define SYSTICK_OVERFLOWED(current, reference)              (current > reference)
#define SYSTICK_DELTA_OUTER(high, low, max)                 ((max) - ((high) - (low)))
#define SYSTICK_DELTA_INNER(high, low)                      ((high) - (low))
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
static uint32 g_Systick_IP_Frequency;
/***********************************************************************************************************************
 *                                             LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL FUNCTION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  GLOBAL FUNCTION
 **********************************************************************************************************************/
#define START_CODE
#include "MemMap.h"


void SysTick_Ip_Init(uint32 p_SystemCounterFreq_u32)
{
    g_Systick_IP_Frequency = p_SystemCounterFreq_u32;
    SysTick_Hw_Init();
}

uint32 SysTick_Ip_GetCounter(void)
{
    return SysTick_Hw_GetCounter();
}

uint32 SysTick_Ip_GetElapsed(uint32 * const p_CurrentRef_ptr)
{
    uint32 CurrentVal_u32 = SysTick_Hw_GetCounter();
    uint32 Dif_u32 = 0u;
    if (SYSTICK_OVERFLOWED((CurrentVal_u32), (*p_CurrentRef_ptr)))
    {
        /* Overflow occurred */
        Dif_u32 = SYSTICK_DELTA_OUTER(CurrentVal_u32, *p_CurrentRef_ptr, SYSTICK_MAX);
    }
    else
    {
        /* Overflow did not occur */
        Dif_u32 = SYSTICK_DELTA_INNER(*p_CurrentRef_ptr, CurrentVal_u32);
    }

    *p_CurrentRef_ptr = CurrentVal_u32;

    return Dif_u32;
}

void SysTick_Ip_SetFreq(uint32 p_Freq_u32)
{
    g_Systick_IP_Frequency = p_Freq_u32;
}

/* Get Ticks by converting from Micro Second */
uint32 SysTick_Ip_UsToTick(uint32 p_Us_u32)
{
    uint64 Temp_u64;
    uint32 Ticks_u32 = 0u;
    Temp_u64 = p_Us_u32 * (uint64)g_Systick_IP_Frequency;
    Ticks_u32 = (uint32)(Temp_u64 & 0xFFFFFFFFu);
    return Ticks_u32;
}

/* Get Ticks by converting from Milli Second */
uint32 SysTick_Ip_MsToTick(uint32 p_Milli_u32)
{
    uint64 Temp_u64;
    uint32 Ticks_u32 = 0u;
    Temp_u64 = p_Milli_u32 * (uint64)g_Systick_IP_Frequency;
    Ticks_u32 = (uint32)(Temp_u64 & 0xFFFFFFFFu);
    return Ticks_u32;
}

#define STOP_CODE
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/