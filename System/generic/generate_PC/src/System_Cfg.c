[!CODE!][!//
[!AUTOSPACING!]
/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: CDD_System_Cfg.c
 *
 * Description: Implementation of CDD_System_Cfg High Level layer
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
#include "System_Cfg.h"
#include "Interrupt_System_Ip_Cfg.h"
#if (USE_FREERTOS == STD_ON)
  #include "FreeRTOSConfig.h"
#endif
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/
#define CDD_System_Cfg_VENDOR_ID_C                     15
#define CDD_System_Cfg_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_System_Cfg_AR_RELEASE_MINOR_VERSION_C      4
#define CDD_System_Cfg_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_System_Cfg_SW_MAJOR_VERSION_C              1
#define CDD_System_Cfg_SW_MINOR_VERSION_C              0
#define CDD_System_Cfg_SW_PATCH_VERSION_C              0
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
[!VAR "Index" = "num:i($Index + '1')"!][!//
[!CODE!][!//
/* Interrupt ConfigSet [!"num:i($Index)"!] */
static System_InterruptConfigSetElementCoreType s_System_InterruptListConfigSet[!"num:i($Index)"!] =
{
	  .InterruptConfigSetElementCoreMem_ptr = &g_Interrupt_System_Ip_ConfigSet[!"num:i($Index)"!]
};

[!ENDCODE!][!//
[!ENDLOOP!][!//


/* Interrupt Config set List */
static System_InterruptConfigSetElementType s_System_InterruptListConfigSet[[!"num:i($NumberOfINTCConfigSet)"!]] =
{
[!NOCODE!][!//	
[!VAR "Index" = "-1"!][!//
[!LOOP "InterruptGeneral/InterruptConfigSet/*"!][!//
[!VAR "NumberOfIRQConfig" = "num:i(count(./InterruptConfig/*))"!]
[!VAR "Index" = "num:i($Index + '1')"!][!//

/* Get config number of config set */
[!VAR "Config_Number" = "0"!][!//
[!LOOP "./InterruptConfig/*"!][!//
	[!VAR "Config_Number" = "num:i($Config_Number + '1')"!][!//
[!ENDLOOP!][!//

[!CODE!][!//
  {
        /* Config Number Of Configset */
		.ConfigNumberOfConfigset_u8 = [!"num:i($Config_Number)"!]U,
		/*List of Interrupt Config Set */
		.InterruptConfigSetElementCore_ptr = &s_System_InterruptListConfigSet[!"num:i($Index)"!]
	}[!IF "num:i($Index) >= num:i(num:i($NumberOfINTCConfigSet)-1)"!] [!ELSE!],[!ENDIF!]

[!ENDCODE!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
};
[!ENDIF!][!//

[!CODE!][!//
[!IF "num:i($NumberOfINTCConfigSet)>num:i(0)"!][!//
/* Interrupt Config set */
static const System_InterruptConfigSetType s_System_InterruptConfigSet =
{
	/*Number of Config Set*/
	.NumberOfInteruptConfigSet_u8 = [!"num:i($NumberOfINTCConfigSet)"!]U,
	/*List of Config Set*/
	.InterruptConfigSetElement_ptr = s_System_InterruptListConfigSet
};
[!ENDIF!][!//
[!ENDCODE!][!//


[!CODE!]
const System_ConfigType g_System_ConfigPC =
{
    /* Number of Interrupt Config Set */
  [!IF "num:i($NumberOfINTCConfigSet)>num:i(0)"!][!//
    .SystemInterruptConfigSet_ptr = &s_System_InterruptConfigSet,
  [!ELSE!][!//
  /* Interrupt has not been configured */
    .SystemInterruptConfigSet_ptr = NULL_PTR,
  [!ENDIF!][!//
};
[!ENDCODE!]

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
