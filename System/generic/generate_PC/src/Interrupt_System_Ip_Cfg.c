[!CODE!][!//
[!AUTOSPACING!]
/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Interrupt_System_Ip_Cfg.c
 *
 * Description: Implementation of Interrupt_System_Ip_Cfg High Level layer
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
#include "Interrupt_System_Ip_Cfg.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define Interrupt_System_Ip_Cfg_VENDOR_ID_C                     15
#define Interrupt_System_Ip_Cfg_AR_RELEASE_MAJOR_VERSION_C      4
#define Interrupt_System_Ip_Cfg_AR_RELEASE_MINOR_VERSION_C      4
#define Interrupt_System_Ip_Cfg_AR_RELEASE_REVISION_VERSION_C   0
#define Interrupt_System_Ip_Cfg_SW_MAJOR_VERSION_C              1
#define Interrupt_System_Ip_Cfg_SW_MINOR_VERSION_C              0
#define Interrupt_System_Ip_Cfg_SW_PATCH_VERSION_C              0
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

/***********************************************************************************************************************
 *                                                 GLOBAL VARIABLES
 **********************************************************************************************************************/
[!NOCODE!][!//
  [!VAR "NumberOfINTCConfigSet" ="0"!][!//
  [!LOOP "InterruptGeneral/InterruptConfigSet/*"!][!//
  [!VAR "NumberOfINTCConfigSet" = "$NumberOfINTCConfigSet + '1'"!][!//
  [!ENDLOOP!][!//
[!ENDNOCODE!][!//

[!IF "num:i($NumberOfINTCConfigSet)>num:i(0)"!][!//
[!VAR "Index" = "-1"!][!//
[!LOOP "InterruptGeneral/InterruptConfigSet/*"!][!//
[!VAR "IrqIndex" = "0"!][!//
[!VAR "IndexConfig" = "0"!][!//
[!VAR "Index" = "num:i($Index + '1')"!][!//
[!VAR "NumberOfINTCConfig" = "num:i(count(./InterruptConfig/*))"!][!//
[!LOOP "./InterruptConfig/*"!][!//
[!VAR "IrqIndex" = "num:i($IrqIndex + '1')"!][!//
[!ENDLOOP!][!//
static Interrupt_System_Ip_InterruptConfigSetElementMemberType s_Interrupt_System_Ip_ConfigSet[!"num:i($Index)"!]_Element_Member[[!"num:i($IrqIndex)"!]] = 
{
  [!LOOP "./InterruptConfig/*"!][!//
  [!VAR "IndexConfig" = "num:i($IndexConfig + '1')"!][!//
    [!CODE!][!//
	{
		/* Irq number */
		.IrqNum = [!"node:value(./InterrupConfigIRQ/InterruptRequest/InterruptIRQ)"!],
		/* Irq handler for interrupt */
		.IrqHandler = [!"node:value(./InterrupConfigIRQ/InterruptRequest/HandleInterrupt)"!],
		/* Interrupt priority configurations */
		.IntPriority = (Interrupt_System_Ip_IntPriorityType)[!"node:value(./InterrupConfigIRQ/InterruptRequest/IsrPriority)"!],
    [!ENDCODE!][!// 
    }[!IF "num:i($IndexConfig) > num:i(num:i($IrqIndex)-1)"!] [!ELSE!],[!ENDIF!][!//

  [!ENDLOOP!][!//
};

[!ENDLOOP!][!//

[!ENDIF!][!//

[!IF "num:i($NumberOfINTCConfigSet)>num:i(0)"!][!//
[!VAR "Index" = "-1"!][!//
[!LOOP "InterruptGeneral/InterruptConfigSet/*"!][!//
[!VAR "IrqIndex" = "0"!][!//
[!VAR "Index" = "num:i($Index + '1')"!][!//
[!VAR "NumberOfINTCConfig" = "num:i(count(./InterruptConfig/*))"!][!//
[!LOOP "./InterruptConfig/*"!][!//
[!VAR "IrqIndex" = "num:i($IrqIndex + '1')"!][!//
[!ENDLOOP!][!//

[!CODE!]
#define START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

const Interrupt_System_IP_InterruptConfigSetElementType g_Interrupt_System_Ip_ConfigSet[!"num:i($Index)"!] =
{
    /* Number of config */
	.NumberOfConfigIrq_u8 = [!"num:i($IrqIndex)"!],
  [!IF "num:i($IrqIndex)>num:i(0)"!][!//
    /* Interrupt element member configuration */
    .InterruptConfigSetElementMem_ptr = s_Interrupt_System_Ip_ConfigSet[!"num:i($Index)"!]_Element_Member
  [!ELSE!][!//
    /* Interrupt element member configuration */
    .InterruptConfigSetElementMem_ptr = NULL_PTR
  [!ENDIF!][!//
};

#define STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
[!ENDCODE!][!//

[!ENDLOOP!][!//

[!ENDIF!][!//



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
