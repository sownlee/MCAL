
#if !defined(HEADER_SYSTICK_H_) 
#define HEADER_SYSTICK_H_

#include "Header.h"

typedef struct
{
  __IO uint32_t CSRr;                   /* Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IO uint32_t RVR;                   /* Offset: 0x004 (R/W)  SysTick Reload Value Register */
  __IO uint32_t CVR;                    /* Offset: 0x008 (R/W)  SysTick Current Value Register */
  __I  uint32_t CALIB;                  /* Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;
#define SysTick             ((SysTick_Type   *)     SysTick_BASE  )

/* CSR Bit Fields */
#define SysTick_CSR_ENABLE_MASK              0x1u
#define SysTick_CSR_ENABLE_SHIFT             0u
#define SysTick_CSR_ENABLE_WIDTH             1u
#define SysTick_CSR_ENABLE(x)                (((uint32_t)(((uint32_t)(x))<<SysTick_CSR_ENABLE_SHIFT))&SysTick_CSR_ENABLE_MASK)
#define SysTick_CSR_TICKINT_MASK             0x2u
#define SysTick_CSR_TICKINT_SHIFT            1u
#define SysTick_CSR_TICKINT_WIDTH            1u
#define SysTick_CSR_TICKINT(x)               (((uint32_t)(((uint32_t)(x))<<SysTick_CSR_TICKINT_SHIFT))&SysTick_CSR_TICKINT_MASK)
#define SysTick_CSR_CLKSOURCE_MASK           0x4u
#define SysTick_CSR_CLKSOURCE_SHIFT          2u
#define SysTick_CSR_CLKSOURCE_WIDTH          1u
#define SysTick_CSR_CLKSOURCE(x)             (((uint32_t)(((uint32_t)(x))<<SysTick_CSR_CLKSOURCE_SHIFT))&SysTick_CSR_CLKSOURCE_MASK)
#define SysTick_CSR_COUNTFLAG_MASK           0x10000u
#define SysTick_CSR_COUNTFLAG_SHIFT          16u
#define SysTick_CSR_COUNTFLAG_WIDTH          1u
#define SysTick_CSR_COUNTFLAG(x)             (((uint32_t)(((uint32_t)(x))<<SysTick_CSR_COUNTFLAG_SHIFT))&SysTick_CSR_COUNTFLAG_MASK)
/* RVR Bit Fields */
#define SysTick_RVR_RELOAD_MASK              0xFFFFFFu
#define SysTick_RVR_RELOAD_SHIFT             0u
#define SysTick_RVR_RELOAD_WIDTH             24u
#define SysTick_RVR_RELOAD(x)                (((uint32_t)(((uint32_t)(x))<<SysTick_RVR_RELOAD_SHIFT))&SysTick_RVR_RELOAD_MASK)
/* CVR Bit Fields */
#define SysTick_CVR_CURRENT_MASK             0xFFFFFFu
#define SysTick_CVR_CURRENT_SHIFT            0u
#define SysTick_CVR_CURRENT_WIDTH            24u
#define SysTick_CVR_CURRENT(x)               (((uint32_t)(((uint32_t)(x))<<SysTick_CVR_CURRENT_SHIFT))&SysTick_CVR_CURRENT_MASK)
/* CALIB Bit Fields */
#define SysTick_CALIB_TENMS_MASK             0xFFFFFFu
#define SysTick_CALIB_TENMS_SHIFT            0u
#define SysTick_CALIB_TENMS_WIDTH            24u
#define SysTick_CALIB_TENMS(x)               (((uint32_t)(((uint32_t)(x))<<SysTick_CALIB_TENMS_SHIFT))&SysTick_CALIB_TENMS_MASK)
#define SysTick_CALIB_SKEW_MASK              0x40000000u
#define SysTick_CALIB_SKEW_SHIFT             30u
#define SysTick_CALIB_SKEW_WIDTH             1u
#define SysTick_CALIB_SKEW(x)                (((uint32_t)(((uint32_t)(x))<<SysTick_CALIB_SKEW_SHIFT))&SysTick_CALIB_SKEW_MASK)
#define SysTick_CALIB_NOREF_MASK             0x80000000u
#define SysTick_CALIB_NOREF_SHIFT            31u
#define SysTick_CALIB_NOREF_WIDTH            1u
#define SysTick_CALIB_NOREF(x)               (((uint32_t)(((uint32_t)(x))<<SysTick_CALIB_NOREF_SHIFT))&SysTick_CALIB_NOREF_MASK)

#endif  /* #if !defined(HEADER_SYSTICK_H_) */
