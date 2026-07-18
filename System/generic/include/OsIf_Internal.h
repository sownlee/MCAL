/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: OsIf_Internal.h
 *
 * Description: Implementation of OSIF_INTERNAL High Level layer
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

#ifndef OSIF_INTERNAL_H
#define OSIF_INTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES  
 **********************************************************************************************************************/
#include "Std_Types.h"
#include "Common.h"
#include "system_init.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define OSIF_INTERNAL_VENDOR_ID                    15
#define OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION     4
#define OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION     4
#define OSIF_INTERNAL_AR_RELEASE_REVISION_VERSION  0
#define OSIF_INTERNAL_SW_MAJOR_VERSION             1
#define OSIF_INTERNAL_SW_MINOR_VERSION             0
#define OSIF_INTERNAL_SW_PATCH_VERSION             0

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
#define START_CODE
#include "MemMap.h"

/***********************************************************************************************************************
 *                                                  LOCAL FUNCTION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  GLOBAL FUNCTION
 **********************************************************************************************************************/

/*
 * OsIf_Trusted_Call *
 */
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined(USING_OS_AUTOSAROS))
        #define OsIf_Trusted_Call(name)                                                  Call_##name##_TRUSTED()
        #define OsIf_Trusted_Call1param(name,param)                                      Call_##name##_TRUSTED(param)
        #define OsIf_Trusted_Call2params(name,param1,param2)                             Call_##name##_TRUSTED(param1,param2)
        #define OsIf_Trusted_Call3params(name,param1,param2,param3)                      Call_##name##_TRUSTED(param1,param2,param3)
        #define OsIf_Trusted_Call4params(name,param1,param2,param3,param4)               Call_##name##_TRUSTED(param1,param2,param3,param4)
        #define OsIf_Trusted_Call5params(name,param1,param2,param3,param4,param5)        Call_##name##_TRUSTED(param1,param2,param3,param4,param5)
        #define OsIf_Trusted_Call6params(name,param1,param2,param3,param4,param5,param6) Call_##name##_TRUSTED(param1,param2,param3,param4,param5,param6)

        #define OsIf_Trusted_Call_Return(name)                                                 Call_##name##_TRUSTED()
        #define OsIf_Trusted_Call_Return1param(name,param1)                                    Call_##name##_TRUSTED(param1)
        #define OsIf_Trusted_Call_Return2param(name,param1,param2)                             Call_##name##_TRUSTED(param1,param2)
        #define OsIf_Trusted_Call_Return3param(name,param1,param2,param3)                      Call_##name##_TRUSTED(param1,param2,param3)
        #define OsIf_Trusted_Call_Return4param(name,param1,param2,param3,param4)               Call_##name##_TRUSTED(param1,param2,param3,param4)
        #define OsIf_Trusted_Call_Return5param(name,param1,param2,param3,param4,param5)        Call_##name##_TRUSTED(param1,param2,param3,param4,param5)
        #define OsIf_Trusted_Call_Return6param(name,param1,param2,param3,param4,param5,param6) Call_##name##_TRUSTED(param1,param2,param3,param4,param5,param6)

    #else /* USING_OS_AUTOSAROS */
    /* Baremetal and FreeRTOS */
        #define OsIf_Trusted_Call(name)  \
            ((1UL == Sys_GoToSupervisor()) ? (name(), (void)Sys_GoToUser()) : (name(),(void)0U))
        #define OsIf_Trusted_Call1param(name,param)  \
            ((1UL == Sys_GoToSupervisor()) ? (name(param), (void)Sys_GoToUser()) : (name(param),(void)0U))
        #define OsIf_Trusted_Call2params(name,param1,param2)  \
            ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2), (void)Sys_GoToUser()) : (name(param1,param2),(void)0U))
        #define OsIf_Trusted_Call3params(name,param1,param2,param3)  \
            ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3), (void)Sys_GoToUser()) : (name(param1,param2,param3),(void)0U))
        #define OsIf_Trusted_Call4params(name,param1,param2,param3,param4)  \
            ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3,param4), (void)Sys_GoToUser()) : (name(param1,param2,param3,param4),(void)0U))
        #define OsIf_Trusted_Call5params(name,param1,param2,param3,param4,param5)  \
            ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3,param4,param5), (void)Sys_GoToUser()) : (name(param1,param2,param3,param4,param5),(void)0U))
        #define OsIf_Trusted_Call6params(name,param1,param2,param3,param4,param5,param6)  \
            ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3,param4,param5,param6), (void)Sys_GoToUser()) : (name(param1,param2,param3,param4,param5,param6),(void)0U))

        #define OsIf_Trusted_Call_Return(name)  \
            ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name()) :  Sys_GoToUser_Return(0U, name()))
        #define OsIf_Trusted_Call_Return1param(name,param)  \
            ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param)) :  Sys_GoToUser_Return(0U, name(param)))
        #define OsIf_Trusted_Call_Return2param(name,param1,param2)  \
            ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2)) : Sys_GoToUser_Return(0U, name(param1,param2)))
        #define OsIf_Trusted_Call_Return3param(name,param1,param2,param3)  \
            ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3)))
        #define OsIf_Trusted_Call_Return4param(name,param1,param2,param3,param4)  \
            ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3,param4)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3,param4)))
        #define OsIf_Trusted_Call_Return5param(name,param1,param2,param3,param4,param5)  \
            ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3,param4,param5)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3,param4,param5)))
        #define OsIf_Trusted_Call_Return6param(name,param1,param2,param3,param4,param5,param6)  \
            ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3,param4,param5,param6)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3,param4,param5,param6)))
    #endif /* USING_OS_AUTOSAROS */
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */

/*
 * OsIf_GetCoreID
 */
#ifdef USING_OS_AUTOSAROS
        #define OsIf_GetCoreID()    GetCoreID()
#else /* USING_OS_AUTOSAROS */
    /* Baremetal and FreeRTOS */
    #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        #define OsIf_GetCoreID()    OsIf_Trusted_Call_Return(Sys_GetCoreID)
    #else
        /* @implements OsIf_GetCoreID_define */
        #define OsIf_GetCoreID()    Sys_GetCoreID()
    #endif
#endif


/*
 * ISR macro definition
 */
#ifdef USING_OS_AUTOSAROS
    /* ISR() macro defined by Autosar OS*/
#else
    /* Baremetal or FreeRTOS case */
    #if defined (USE_SW_VECTOR_MODE)
        #define ISR(IsrName)       void IsrName(void)
    #else
        #define ISR(IsrName)       INTERRUPT_FUNC void IsrName(void)
    #endif /* defined (USE_SW_VECTOR_MODE) */
#endif /* USING_OS_AUTOSAROS */

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* OSIF_INTERNAL_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
