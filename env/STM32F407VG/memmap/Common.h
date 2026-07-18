/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Common.h
 *
 * Description: Implementation of Common file
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

#ifndef COMMON_H
#define COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES AND 
 **********************************************************************************************************************/
#include "Std_Types.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define COMMON_VENDOR_ID                    15
#define COMMON_AR_RELEASE_MAJOR_VERSION     4
#define COMMON_AR_RELEASE_MINOR_VERSION     4
#define COMMON_AR_RELEASE_REVISION_VERSION  0
#define COMMON_SW_MAJOR_VERSION             1
#define COMMON_SW_MINOR_VERSION             0
#define COMMON_SW_PATCH_VERSION             0
/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/
#define MCAL_ARM_MARCH      (16)  /* for ARM M4 Thumb2 */
#define MCAL_ARM_AARCH32    (32)  /* for ARM ARCH32    */
#define MCAL_ARM_AARCH64    (64)  /* for ARM ARCH64    */

#define MCAL_PLATFORM_ARM  MCAL_ARM_MARCH

/**
* @brief Compiler abstraction for the intrinsic wait instruction.
*/
#define EXECUTE_WAIT()    ASM_KEYWORD("  wfi")

#if defined(AUTOSAR_OS_NOT_USED)
    #if defined (USE_SW_VECTOR_MODE)
        /**
        * @brief Compiler abstraction for creating an interrupt handler if no OS is present.
        */
        #define ISR(IsrName)       void IsrName(void)
    #else
        /**
        * @brief Compiler abstraction for creating an interrupt handler if no OS is present.
        */
        #define ISR(IsrName)       INTERRUPT_FUNC void IsrName(void)

    #endif /*USE_SW_VECTOR_MODE*/

    /**
    * @brief Compiler abstraction for returning from an ISR if no OS is present.
    */
    #define EXIT_INTERRUPT()

    /**
    * @brief Compiler abstraction for disabling all interrupts if no OS is present.
    */
    #if(MCAL_ARM_AARCH64 == MCAL_PLATFORM_ARM)
        #define SuspendAllInterrupts() ASM_KEYWORD(" msr DAIFSet,#0xf")
    #else
        #if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
            #if (defined MCAL_PLATFORM_ARM_M0PLUS)
                #define SuspendAllInterrupts()
            #else
                #define SuspendAllInterrupts()  ASM_KEYWORD("svc 0x3")  /* BASEPRI will be set to 0x10 from SVC handler  */
            #endif
        #else
            /* Disable interrupts and configurable fault handlers in ARM */
            #define SuspendAllInterrupts()  ASM_KEYWORD(" cpsid i")
        #endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
    #endif

    /**
    * @brief Compiler abstraction for re-enabling all interrupts if no OS is present.
    */
    #if(MCAL_ARM_AARCH64 == MCAL_PLATFORM_ARM)
        #define ResumeAllInterrupts() ASM_KEYWORD(" msr DAIFClr,#0xf")
    #else
        #if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
            #if (defined MCAL_PLATFORM_ARM_M0PLUS)
                #define ResumeAllInterrupts()
            #else
                #define ResumeAllInterrupts() ASM_KEYWORD("svc 0x2")  /* BASEPRI will be set to 0x0 from SVC handler  */
            #endif
        #else
            /* Enable interrupts and configurable fault handlers in ARM */
            #define ResumeAllInterrupts()  ASM_KEYWORD(" cpsie i")
        #endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
    #endif
#else
    /**
    * @brief Compiler abstraction for returning from an ISR if OS is present must be empty.
    */
    #define EXIT_INTERRUPT()
#endif

/**
* @brief Data Synchronization Barrier (DSB) completes when all instructions before this instruction complete
*/
#define MCAL_DATA_SYNC_BARRIER()  ASM_KEYWORD(" DSB")


/**
* @brief  flushes the pipeline in the processor, so that all instructions following the ISB are fetched from cache or memory, after the ISB has been completed.
*/
#define MCAL_INSTRUCTION_SYNC_BARRIER()  ASM_KEYWORD(" ISB")
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


#ifdef __cplusplus
}
#endif

#endif /* COMMON_H */

/*--------------------------------------------------- EOF ------------------------------------------------------------*/
