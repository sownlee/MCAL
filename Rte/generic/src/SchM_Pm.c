/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: SchM_Pm.c
 *
 * Description: Implementation of SchM_Pm High Level layer
 *              
 * AutoSAR Version:         4.4.0
 *
 * Compiler: GCC IAR
 *
 * Revision:
 *              Version         Date                Change History
 *              0.9.3          23/02/2024           Initial version
 *
 **********************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES
 **********************************************************************************************************************/
#include "Std_Types.h"
#include "SchM_Pm.h"
#include "Common.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define SCHM_PM_AR_RELEASE_MAJOR_VERSION_C     4
#define SCHM_PM_AR_RELEASE_MINOR_VERSION_C     4
#define SCHM_PM_AR_RELEASE_REVISION_VERSION_C  0
#define SCHM_PM_SW_MAJOR_VERSION_C             1
#define SCHM_PM_SW_MINOR_VERSION_C             0
#define SCHM_PM_SW_PATCH_VERSION_C             0
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

/***********************************************************************************************************************
 *                                                  LOCAL VARIABLES
 **********************************************************************************************************************/
#define START_VAR_CLEARED_32_NO_CACHEABLE
#include "MemMap.h"
static volatile uint32 Counter_00;
static volatile uint32 Counter_01;
static volatile uint32 Counter_02;
static volatile uint32 Counter_03;
static volatile uint32 Counter_04;
static volatile uint32 Counter_05;
static volatile uint32 Counter_06;
static volatile uint32 Counter_07;
static volatile uint32 Counter_08;
static volatile uint32 Counter_09;
static volatile uint32 Counter_10;
static volatile uint32 Counter_11;
static volatile uint32 Counter_12;
static volatile uint32 Counter_13;
static volatile uint32 Counter_14;
static volatile uint32 Counter_15;
static volatile uint32 Counter_16;
static volatile uint32 Counter_17;
static volatile uint32 Counter_18;
static volatile uint32 Counter_19;
static volatile uint32 Counter_20;
static volatile uint32 Counter_21;
static volatile uint32 Counter_22;
static volatile uint32 Counter_23;
static volatile uint32 Counter_24;
static volatile uint32 Counter_25;
static volatile uint32 Counter_26;
static volatile uint32 Counter_27;
static volatile uint32 Counter_28;
static volatile uint32 Counter_29;
static volatile uint32 Counter_30;
static volatile uint32 Counter_31;
static volatile uint32 Counter_32;
static volatile uint32 Counter_33;
static volatile uint32 Counter_34;
static volatile uint32 Counter_35;
static volatile uint32 Counter_36;
static volatile uint32 Counter_37;
static volatile uint32 Counter_38;
static volatile uint32 Counter_39;
static volatile uint32 Counter_40;
static volatile uint32 Counter_41;
static volatile uint32 Counter_42;
static volatile uint32 Counter_43;
static volatile uint32 Counter_44;
static volatile uint32 Counter_45;
static volatile uint32 Counter_46;
static volatile uint32 Counter_47;
static volatile uint32 Counter_48;
static volatile uint32 Counter_49;
static volatile uint32 Counter_50;
static volatile uint32 Counter_51;
static volatile uint32 Counter_52;
static volatile uint32 Counter_53;
static volatile uint32 Counter_54;
static volatile uint32 Counter_55;
static volatile uint32 Counter_56;
static volatile uint32 Counter_57;
static volatile uint32 Counter_58;
static volatile uint32 Counter_59;
static volatile uint32 Counter_60;
static volatile uint32 Counter_61;
static volatile uint32 Counter_62;
static volatile uint32 Counter_63;
static volatile uint32 Counter_64;
static volatile uint32 Counter_65;
static volatile uint32 Counter_66;
static volatile uint32 Counter_67;
static volatile uint32 Counter_68;
static volatile uint32 Counter_69;
static volatile uint32 Counter_70;
#define STOP_VAR_CLEARED_32_NO_CACHEABLE
#include "MemMap.h"
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

/**
 *  Enter Exclusive Area
 */
void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_00(void)
{
  if(0UL == Counter_00)
  {
    SuspendAllInterrupts();
  }
  Counter_00++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_01(void)
{
  if(0UL == Counter_01)
  {
    SuspendAllInterrupts();
  }
  Counter_01++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_02(void)
{
  if(0UL == Counter_02)
  {
    SuspendAllInterrupts();
  }
  Counter_02++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_03(void)
{
  if(0UL == Counter_03)
  {
    SuspendAllInterrupts();
  }
  Counter_03++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_04(void)
{
  if(0UL == Counter_04)
  {
    SuspendAllInterrupts();
  }
  Counter_04++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_05(void)
{
  if(0UL == Counter_05)
  {
    SuspendAllInterrupts();
  }
  Counter_05++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_06(void)
{
  if(0UL == Counter_06)
  {
    SuspendAllInterrupts();
  }
  Counter_06++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_07(void)
{
  if(0UL == Counter_07)
  {
    SuspendAllInterrupts();
  }
  Counter_07++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_08(void)
{
  if(0UL == Counter_08)
  {
    SuspendAllInterrupts();
  }
  Counter_08++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_09(void)
{
  if(0UL == Counter_09)
  {
    SuspendAllInterrupts();
  }
  Counter_09++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_10(void)
{
  if(0UL == Counter_10)
  {
    SuspendAllInterrupts();
  }
  Counter_10++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_11(void)
{
  if(0UL == Counter_11)
  {
    SuspendAllInterrupts();
  }
  Counter_11++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_12(void)
{
  if(0UL == Counter_12)
  {
    SuspendAllInterrupts();
  }
  Counter_12++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_13(void)
{
  if(0UL == Counter_13)
  {
    SuspendAllInterrupts();
  }
  Counter_13++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_14(void)
{
  if(0UL == Counter_14)
  {
    SuspendAllInterrupts();
  }
  Counter_14++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_15(void)
{
  if(0UL == Counter_15)
  {
    SuspendAllInterrupts();
  }
  Counter_15++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_16(void)
{
  if(0UL == Counter_16)
  {
    SuspendAllInterrupts();
  }
  Counter_16++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_17(void)
{
  if(0UL == Counter_17)
  {
    SuspendAllInterrupts();
  }
  Counter_17++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_18(void)
{
  if(0UL == Counter_18)
  {
    SuspendAllInterrupts();
  }
  Counter_18++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_19(void)
{
  if(0UL == Counter_19)
  {
    SuspendAllInterrupts();
  }
  Counter_19++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_20(void)
{
  if(0UL == Counter_20)
  {
    SuspendAllInterrupts();
  }
  Counter_20++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_21(void)
{
  if(0UL == Counter_21)
  {
    SuspendAllInterrupts();
  }
  Counter_21++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_22(void)
{
  if(0UL == Counter_22)
  {
    SuspendAllInterrupts();
  }
  Counter_22++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_23(void)
{
  if(0UL == Counter_23)
  {
    SuspendAllInterrupts();
  }
  Counter_23++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_24(void)
{
  if(0UL == Counter_24)
  {
    SuspendAllInterrupts();
  }
  Counter_24++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_25(void)
{
  if(0UL == Counter_25)
  {
    SuspendAllInterrupts();
  }
  Counter_25++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_26(void)
{
  if(0UL == Counter_26)
  {
    SuspendAllInterrupts();
  }
  Counter_26++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_27(void)
{
  if(0UL == Counter_27)
  {
    SuspendAllInterrupts();
  }
  Counter_27++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_28(void)
{
  if(0UL == Counter_28)
  {
    SuspendAllInterrupts();
  }
  Counter_28++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_29(void)
{
  if(0UL == Counter_29)
  {
    SuspendAllInterrupts();
  }
  Counter_29++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_30(void)
{
  if(0UL == Counter_30)
  {
    SuspendAllInterrupts();
  }
  Counter_30++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_31(void)
{
  if(0UL == Counter_31)
  {
    SuspendAllInterrupts();
  }
  Counter_31++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_32(void)
{
  if(0UL == Counter_32)
  {
    SuspendAllInterrupts();
  }
  Counter_32++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_33(void)
{
  if(0UL == Counter_33)
  {
    SuspendAllInterrupts();
  }
  Counter_33++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_34(void)
{
  if(0UL == Counter_34)
  {
    SuspendAllInterrupts();
  }
  Counter_34++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_35(void)
{
  if(0UL == Counter_35)
  {
    SuspendAllInterrupts();
  }
  Counter_35++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_36(void)
{
  if(0UL == Counter_36)
  {
    SuspendAllInterrupts();
  }
  Counter_36++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_37(void)
{
  if(0UL == Counter_37)
  {
    SuspendAllInterrupts();
  }
  Counter_37++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_38(void)
{
  if(0UL == Counter_38)
  {
    SuspendAllInterrupts();
  }
  Counter_38++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_39(void)
{
  if(0UL == Counter_39)
  {
    SuspendAllInterrupts();
  }
  Counter_39++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_40(void)
{
  if(0UL == Counter_40)
  {
    SuspendAllInterrupts();
  }
  Counter_40++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_41(void)
{
  if(0UL == Counter_41)
  {
    SuspendAllInterrupts();
  }
  Counter_41++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_42(void)
{
  if(0UL == Counter_42)
  {
    SuspendAllInterrupts();
  }
  Counter_42++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_43(void)
{
  if(0UL == Counter_43)
  {
    SuspendAllInterrupts();
  }
  Counter_43++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_44(void)
{
  if(0UL == Counter_44)
  {
    SuspendAllInterrupts();
  }
  Counter_44++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_45(void)
{
  if(0UL == Counter_45)
  {
    SuspendAllInterrupts();
  }
  Counter_45++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_46(void)
{
  if(0UL == Counter_46)
  {
    SuspendAllInterrupts();
  }
  Counter_46++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_47(void)
{
  if(0UL == Counter_47)
  {
    SuspendAllInterrupts();
  }
  Counter_47++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_48(void)
{
  if(0UL == Counter_48)
  {
    SuspendAllInterrupts();
  }
  Counter_48++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_49(void)
{
  if(0UL == Counter_49)
  {
    SuspendAllInterrupts();
  }
  Counter_49++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_50(void)
{
  if(0UL == Counter_50)
  {
    SuspendAllInterrupts();
  }
  Counter_50++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_51(void)
{
  if(0UL == Counter_51)
  {
    SuspendAllInterrupts();
  }
  Counter_51++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_52(void)
{
  if(0UL == Counter_52)
  {
    SuspendAllInterrupts();
  }
  Counter_52++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_53(void)
{
  if(0UL == Counter_53)
  {
    SuspendAllInterrupts();
  }
  Counter_53++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_54(void)
{
  if(0UL == Counter_54)
  {
    SuspendAllInterrupts();
  }
  Counter_54++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_55(void)
{
  if(0UL == Counter_55)
  {
    SuspendAllInterrupts();
  }
  Counter_55++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_56(void)
{
  if(0UL == Counter_56)
  {
    SuspendAllInterrupts();
  }
  Counter_56++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_57(void)
{
  if(0UL == Counter_57)
  {
    SuspendAllInterrupts();
  }
  Counter_57++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_58(void)
{
  if(0UL == Counter_58)
  {
    SuspendAllInterrupts();
  }
  Counter_58++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_59(void)
{
  if(0UL == Counter_59)
  {
    SuspendAllInterrupts();
  }
  Counter_59++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_60(void)
{
  if(0UL == Counter_60)
  {
    SuspendAllInterrupts();
  }
  Counter_60++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_61(void)
{
  if(0UL == Counter_61)
  {
    SuspendAllInterrupts();
  }
  Counter_61++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_62(void)
{
  if(0UL == Counter_62)
  {
    SuspendAllInterrupts();
  }
  Counter_62++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_63(void)
{
  if(0UL == Counter_63)
  {
    SuspendAllInterrupts();
  }
  Counter_63++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_64(void)
{
  if(0UL == Counter_64)
  {
    SuspendAllInterrupts();
  }
  Counter_64++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_65(void)
{
  if(0UL == Counter_65)
  {
    SuspendAllInterrupts();
  }
  Counter_65++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_66(void)
{
  if(0UL == Counter_66)
  {
    SuspendAllInterrupts();
  }
  Counter_66++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_67(void)
{
  if(0UL == Counter_67)
  {
    SuspendAllInterrupts();
  }
  Counter_67++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_68(void)
{
  if(0UL == Counter_68)
  {
    SuspendAllInterrupts();
  }
  Counter_68++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_69(void)
{
  if(0UL == Counter_69)
  {
    SuspendAllInterrupts();
  }
  Counter_69++;
}

void SchM_Enter_Pm_PM_EXCLUSIVE_AREA_70(void)
{
  if(0UL == Counter_70)
  {
    SuspendAllInterrupts();
  }
  Counter_70++;
}


/**
 *  Exit Exclusive Area
 */ 
void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_00(void)
{
  Counter_00--;
  if (0UL == Counter_00)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_01(void)
{
  Counter_01--;
  if (0UL == Counter_01)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_02(void)
{
  Counter_02--;
  if (0UL == Counter_02)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_03(void)
{
  Counter_03--;
  if (0UL == Counter_03)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_04(void)
{
  Counter_04--;
  if (0UL == Counter_04)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_05(void)
{
  Counter_05--;
  if (0UL == Counter_05)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_06(void)
{
  Counter_06--;
  if (0UL == Counter_06)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_07(void)
{
  Counter_07--;
  if (0UL == Counter_07)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_08(void)
{
  Counter_08--;
  if (0UL == Counter_08)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_09(void)
{
  Counter_09--;
  if (0UL == Counter_09)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_10(void)
{
  Counter_10--;
  if (0UL == Counter_10)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_11(void)
{
  Counter_11--;
  if (0UL == Counter_11)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_12(void)
{
  Counter_12--;
  if (0UL == Counter_12)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_13(void)
{
  Counter_13--;
  if (0UL == Counter_13)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_14(void)
{
  Counter_14--;
  if (0UL == Counter_14)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_15(void)
{
  Counter_15--;
  if (0UL == Counter_15)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_16(void)
{
  Counter_16--;
  if (0UL == Counter_16)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_17(void)
{
  Counter_17--;
  if (0UL == Counter_17)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_18(void)
{
  Counter_18--;
  if (0UL == Counter_18)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_19(void)
{
  Counter_19--;
  if (0UL == Counter_19)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_20(void)
{
  Counter_20--;
  if (0UL == Counter_20)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_21(void)
{
  Counter_21--;
  if (0UL == Counter_21)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_22(void)
{
  Counter_22--;
  if (0UL == Counter_22)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_23(void)
{
  Counter_23--;
  if (0UL == Counter_23)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_24(void)
{
  Counter_24--;
  if (0UL == Counter_24)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_25(void)
{
  Counter_25--;
  if (0UL == Counter_25)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_26(void)
{
  Counter_26--;
  if (0UL == Counter_26)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_27(void)
{
  Counter_27--;
  if (0UL == Counter_27)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_28(void)
{
  Counter_28--;
  if (0UL == Counter_28)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_29(void)
{
  Counter_29--;
  if (0UL == Counter_29)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_30(void)
{
  Counter_30--;
  if (0UL == Counter_30)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_31(void)
{
  Counter_31--;
  if (0UL == Counter_31)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_32(void)
{
  Counter_32--;
  if (0UL == Counter_32)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_33(void)
{
  Counter_33--;
  if (0UL == Counter_33)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_34(void)
{
  Counter_34--;
  if (0UL == Counter_34)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_35(void)
{
  Counter_35--;
  if (0UL == Counter_35)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_36(void)
{
  Counter_36--;
  if (0UL == Counter_36)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_37(void)
{
  Counter_37--;
  if (0UL == Counter_37)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_38(void)
{
  Counter_38--;
  if (0UL == Counter_38)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_39(void)
{
  Counter_39--;
  if (0UL == Counter_39)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_40(void)
{
  Counter_40--;
  if (0UL == Counter_40)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_41(void)
{
  Counter_41--;
  if (0UL == Counter_41)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_42(void)
{
  Counter_42--;
  if (0UL == Counter_42)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_43(void)
{
  Counter_43--;
  if (0UL == Counter_43)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_44(void)
{
  Counter_44--;
  if (0UL == Counter_44)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_45(void)
{
  Counter_45--;
  if (0UL == Counter_45)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_46(void)
{
  Counter_46--;
  if (0UL == Counter_46)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_47(void)
{
  Counter_47--;
  if (0UL == Counter_47)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_48(void)
{
  Counter_48--;
  if (0UL == Counter_48)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_49(void)
{
  Counter_49--;
  if (0UL == Counter_49)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_50(void)
{
  Counter_50--;
  if (0UL == Counter_50)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_51(void)
{
  Counter_51--;
  if (0UL == Counter_51)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_52(void)
{
  Counter_52--;
  if (0UL == Counter_52)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_53(void)
{
  Counter_53--;
  if (0UL == Counter_53)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_54(void)
{
  Counter_54--;
  if (0UL == Counter_54)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_55(void)
{
  Counter_55--;
  if (0UL == Counter_55)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_56(void)
{
  Counter_56--;
  if (0UL == Counter_56)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_57(void)
{
  Counter_57--;
  if (0UL == Counter_57)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_58(void)
{
  Counter_58--;
  if (0UL == Counter_58)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_59(void)
{
  Counter_59--;
  if (0UL == Counter_59)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_60(void)
{
  Counter_60--;
  if (0UL == Counter_60)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_61(void)
{
  Counter_61--;
  if (0UL == Counter_61)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_62(void)
{
  Counter_62--;
  if (0UL == Counter_62)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_63(void)
{
  Counter_63--;
  if (0UL == Counter_63)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_64(void)
{
  Counter_64--;
  if (0UL == Counter_64)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_65(void)
{
  Counter_65--;
  if (0UL == Counter_65)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_66(void)
{
  Counter_66--;
  if (0UL == Counter_66)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_67(void)
{
  Counter_67--;
  if (0UL == Counter_67)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_68(void)
{
  Counter_68--;
  if (0UL == Counter_68)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_69(void)
{
  Counter_69--;
  if (0UL == Counter_69)
  {
    ResumeAllInterrupts();
  }
}

void SchM_Exit_Pm_PM_EXCLUSIVE_AREA_70(void)
{
  Counter_70--;
  if (0UL == Counter_70)
  {
    ResumeAllInterrupts();
  }
}

#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/