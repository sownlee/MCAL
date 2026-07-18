#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus
extern "C"{
#endif

/* https://www.autosar.org/fileadmin/standards/R20-11/CP/AUTOSAR_SWS_CompilerAbstraction.pdf */
#include "Compiler_Cfg.h"

#define COMPILER_VENDOR_ID                      15
#define COMPILER_AR_RELEASE_MAJOR_VERSION       4
#define COMPILER_AR_RELEASE_MINOR_VERSION       4
#define COMPILER_AR_RELEASE_REVISION_VERSION    0
#define COMPILER_SW_MAJOR_VERSION               1
#define COMPILER_SW_MINOR_VERSION               0
#define COMPILER_SW_PATCH_VERSION               0

/**
* @brief The memory class AUTOMATIC shall be provided as empty definition, used for the declaration of local pointers.
*/
#define AUTOMATIC
#define TYPEDEF
#define NULL_PTR ((void *)0)

#ifdef _GREENHILLS_HULA_
    #define INLINE              __inline
    #define LOCAL_INLINE        static __inline
    #define INTERRUPT_FUNC      __interrupt
    #define ASM_KEYWORD         __asm
    #define ASMV_KEYWORD        __asm volatile
    #define ALIGNED_VARS_START(sec_name, align)
    #define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
    #define PACKED __packed 
    /**
     * @brief Compiler abstraction for MCAL Fault Injection tests 
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        #define MCAL_PUT_IN_QUOTES(x) #x
        #define MCAL_FAULT_INJECTION_POINT(label) ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label::))
    #else
        #define MCAL_FAULT_INJECTION_POINT(label)
    #endif
#endif /* _GREENHILLS_ */

#ifdef _DIABDATA_
    #define INLINE              inline __attribute__((always_inline))
    #define LOCAL_INLINE        static inline __attribute__((always_inline))
    #define INTERRUPT_FUNC      __attribute__((interrupt))
    #define ASM_KEYWORD  __asm
    #define ASMV_KEYWORD  __asm volatile
    #define ALIGNED_VARS_START(sec_name, align)
    #define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
    #define PACKED __attribute__((packed)) 
    /**
     * @brief Compiler abstraction for MCAL Fault Injection tests 
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        #define MCAL_PUT_IN_QUOTES(x) #x
        #define MCAL_FAULT_INJECTION_POINT(label) ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label:))
    #else
        #define MCAL_FAULT_INJECTION_POINT(label)
    #endif

#endif /* _DIABDATA_ */

#ifdef _GCC_HULA_
    #define INLINE                  inline __attribute__((always_inline))
    #define LOCAL_INLINE            static inline __attribute__((always_inline))
    #define INTERRUPT_FUNC     
    #define ASM_KEYWORD             __asm__
    #define ASMV_KEYWORD            __asm__ volatile
    #define ALIGNED_VARS_START(sec_name, align)
    #define VAR_ALIGN(v, size)      __attribute__(( aligned(size) )) v;
    #define PACKED                  __attribute__((__packed__))
    #define WEAK                    __attribute__((weak))
    #define __NOP()                             ASM_KEYWORD volatile ("nop")

    /**
    * brief   Wait For Interrupt
    * details Wait For Interrupt is a hint instruction that suspends execution until one of a number of events occurs.
    */
    #define CALL_INSTRUCTION_WFI()                             ASM_KEYWORD volatile ("wfi")

    /**
     * brief   Wait For Event
     * details Wait For Event is a hint instruction that permits the processor to enter
            a low-power state until one of a number of events occurs.
    */
    #define CALL_INSTRUCTION_WFE()                             ASM_KEYWORD volatile ("wfe")

    /**
    * brief   Send Event
    * details Send Event is a hint instruction. It causes an event to be signaled to the CPU.
    */
    #define CALL_INSTRUCTION_SEV()                             ASM_KEYWORD volatile ("sev")

    /**
    * brief   Instruction Synchronization Barrier
    * details Instruction Synchronization Barrier flushes the pipeline in the processor,
            so that all instructions following the ISB are fetched from cache or memory,
            after the instruction has been completed.
    */
    LOCAL_INLINE void __ISB(void)
    {
        ASM_KEYWORD volatile ("isb 0xF":::"memory");
    }

    /**
    * brief   Data Synchronization Barrier
    * details Acts as a special kind of Data Memory Barrier.
            It completes when all explicit memory accesses before this instruction complete.
    */
    LOCAL_INLINE void __DSB(void)
    {
        ASM_KEYWORD volatile ("dsb 0xF":::"memory");
    }

    /**
    * brief   Data Memory Barrier
    * details Ensures the apparent order of the explicit memory operations before
            and after the instruction, without ensuring their completion.
    */
    LOCAL_INLINE void __DMB(void)
    {
        ASM_KEYWORD volatile ("dmb 0xF":::"memory");
    }

    /**
    * brief   Breakpoint
    * details Causes the processor to enter Debug state.
            Debug tools can use this to investigate system state when the instruction at a particular address is reached.
    * param [in]    value  is ignored by the processor.
                    If required, a debugger can use it to store additional information about the breakpoint.
    */
    #define __BKPT(value)                       ASM_KEYWORD volatile ("bkpt "#value)
    /**
     * @brief Compiler abstraction for MCAL Fault Injection tests 
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        #define MCAL_PUT_IN_QUOTES(x) #x
        #define MCAL_FAULT_INJECTION_POINT(label) ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label:))
    #else
        #define MCAL_FAULT_INJECTION_POINT(label)
    #endif
#endif /* _GCC_HULA_ */

#ifdef _IAR_HULA_
    #define INLINE              inline __attribute__((always_inline))
    #define LOCAL_INLINE        static inline __attribute__((always_inline))
    #define INTERRUPT_FUNC
    #define MCAL_PUT_IN_QUOTES(x) #x
    #define MCAL_PUT_IN_QUOTES1(x) MCAL_PUT_IN_QUOTES(x)
    #define ASM_KEYWORD  __asm
    #define ASMV_KEYWORD  __asm volatile
    #define ALIGNED_VARS_START(sec_name, align) 
    #define VAR_ALIGN(v, size)  _Pragma(MCAL_PUT_IN_QUOTES1(data_alignment=size)) v;
    #define PACKED __packed 
    /**
     * @brief Compiler abstraction for MCAL Fault Injection tests 
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        #define MCAL_FAULT_INJECTION_POINT(label)   ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label:))
    #else
        #define MCAL_FAULT_INJECTION_POINT(label)
    #endif
#endif /* _IAR_ */

#define FUNC(rettype, memclass) rettype
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)
#define CONST(consttype, memclass) const consttype
#define VAR(vartype, memclass) vartype
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)
#define FUNC_P2CONST(rettype, ptrclass, memclass) const ptrclass rettype * memclass
#define FUNC_P2VAR(rettype, ptrclass, memclass) ptrclass rettype * memclass

#ifdef __cplusplus
}
#endif

#endif /* COMPILER_H */

