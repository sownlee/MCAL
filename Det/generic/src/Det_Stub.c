/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Det_Stub.c
 *
 * Description: Implementation of Det_Stub File
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
#include "Compiler.h"
#include "Det_Stub.h"
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
#define START_CODE
#include "MemMap.h"

/**
 *  @brief          Tests if an expected error has been reported to DET
 *
 *  @details        Tests if an expected error has been reported to DET
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint16
 *  @param[in]      ModuleId          ID of the module reporting the error
 *  @arg            uint8
 *  @param[in]      InstanceId        ID of the Instance reporting the error
 *  @arg            uint8
 *  @param[in]      ApiId             ID of the API where the error has been generated from
 *  @arg            uint8
 *  @param[in]      ErrorId           Error Code
 * 
 *  @return         boolean     
 *  @retval         FALSE             
 *  @retval         TRUE             
 *
 *  @note           boolean - true in case expected error has been found
 *
 **/
boolean Det_TestLastReportError(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId)
{
    boolean Result = FALSE;
    Det_ConfigType *DetBuffer_ptr = &Det_g_DetErrBuffer[(Det_DetBuffIndex_u32 - 1) % DET_MAX_BUFFER];
    Result = (DetBuffer_ptr->ModuleId == ModuleId) && (DetBuffer_ptr->InstanceId == InstanceId) &&(DetBuffer_ptr->ApiId == ApiId) && (DetBuffer_ptr->ErrorId == ErrorId);

    DetBuffer_ptr->ModuleId = 0;
    DetBuffer_ptr->InstanceId = 0;
    DetBuffer_ptr->ApiId = 0;
    DetBuffer_ptr->ErrorId = 0;

    return Result;
}


/**
 *  @brief          Tests if an expected error has been reported to DET
 *
 *  @details        Tests if an expected error has been reported to DET
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint16
 *  @param[in]      ModuleId          ID of the module reporting the error
 *  @arg            uint8
 *  @param[in]      InstanceId        ID of the Instance reporting the error
 *  @arg            uint8
 *  @param[in]      ApiId             ID of the API where the error has been generated from
 *  @arg            uint8
 *  @param[in]      ErrorId           Error Code
 * 
 *  @return         boolean     
 *  @retval         FALSE             
 *  @retval         TRUE             
 *
 *  @note           boolean - true in case expected error has been found
 *
 **/
boolean Det_TestLastReportRuntimeError(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 RuntimeId)
{
    boolean Result = FALSE;
    Det_ConfigType *DetBuffer_ptr = &Det_g_DetErrBuffer[(Det_DetBuffIndex_u32 - 1) % DET_MAX_BUFFER];
    Result = (DetBuffer_ptr->ModuleId == ModuleId) && (DetBuffer_ptr->InstanceId == InstanceId) &&(DetBuffer_ptr->ApiId == ApiId) && (DetBuffer_ptr->RuntimeId == RuntimeId);

    DetBuffer_ptr->ModuleId = 0;
    DetBuffer_ptr->InstanceId = 0;
    DetBuffer_ptr->ApiId = 0;
    DetBuffer_ptr->RuntimeId = 0;

    return Result;
}

/**
 *  @brief          Tests if an expected error has been reported to DET
 *
 *  @details        Tests if an expected error has been reported to DET
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint16
 *  @param[in]      ModuleId          ID of the module reporting the error
 *  @arg            uint8
 *  @param[in]      InstanceId        ID of the Instance reporting the error
 *  @arg            uint8
 *  @param[in]      ApiId             ID of the API where the error has been generated from
 *  @arg            uint8
 *  @param[in]      ErrorId           Error Code
 * 
 *  @return         boolean     
 *  @retval         FALSE             
 *  @retval         TRUE             
 *
 *  @note           boolean - true in case expected error has been found
 *
 **/
boolean Det_TestLastReportTransientFault(uint16 ModuleId,uint8 InstanceId,uint8 ApiId, uint8 FaultId)
{
    boolean Result = FALSE;
    Det_ConfigType *DetBuffer_ptr = &Det_g_DetErrBuffer[(Det_DetBuffIndex_u32 - 1) % DET_MAX_BUFFER];
    Result = (DetBuffer_ptr->ModuleId == ModuleId) && (DetBuffer_ptr->InstanceId == InstanceId) &&(DetBuffer_ptr->ApiId == ApiId) && (DetBuffer_ptr->FaultId == FaultId);

    DetBuffer_ptr->ModuleId = 0;
    DetBuffer_ptr->InstanceId = 0;
    DetBuffer_ptr->ApiId = 0;
    DetBuffer_ptr->FaultId = 0;

    return Result;
}

/**
 *  @brief          Tests if an expected error has been reported to DET
 *
 *  @details        Tests if an expected error has been reported to DET
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint16
 *  @param[in]      ModuleId          ID of the module reporting the error
 *  @arg            uint8
 *  @param[in]      InstanceId        ID of the Instance reporting the error
 *  @arg            uint8
 *  @param[in]      ApiId             ID of the API where the error has been generated from
 *  @arg            uint8
 *  @param[in]      ErrorId           Error Code
 * 
 *  @return         boolean     
 *  @retval         FALSE             
 *  @retval         TRUE             
 *
 *  @note           boolean - true in case of NO error has been reported to DET
 *
 **/
boolean Det_TestNoError(void) {
    uint16 Count = 0;
    boolean Result = FALSE, Check = FALSE;
    for (Count = 0;Count < Det_DetBuffIndex_u32; Count++)
    {
        Det_ConfigType *DetBuffer_ptr = &Det_g_DetErrBuffer[Count];
        Check = DetBuffer_ptr->ErrorId;
        if (Check == TRUE)
        {
            DetBuffer_ptr->ModuleId = 0;
            DetBuffer_ptr->InstanceId = 0;
            DetBuffer_ptr->ApiId = 0;
            DetBuffer_ptr->ErrorId = 0;
            Result = TRUE;
        }
    }
    return !Result;
}

/**
 *  @brief          Tests if an expected error has been reported to DET
 *
 *  @details        Tests if an expected error has been reported to DET
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint16
 *  @param[in]      ModuleId          ID of the module reporting the error
 *  @arg            uint8
 *  @param[in]      InstanceId        ID of the Instance reporting the error
 *  @arg            uint8
 *  @param[in]      ApiId             ID of the API where the error has been generated from
 *  @arg            uint8
 *  @param[in]      ErrorId           Error Code
 * 
 *  @return         boolean     
 *  @retval         FALSE             
 *  @retval         TRUE             
 *
 *  @note           boolean - true in case of NO error has been reported to DET
 *
 **/
boolean Det_TestNoRuntimeError(void) {
    uint16 Count = 0;
    boolean Result = FALSE, Check = FALSE;
    for (Count = 0;Count < Det_DetBuffIndex_u32; Count++)
    {
        Det_ConfigType *DetBuffer_ptr = &Det_g_DetErrBuffer[Count];
        Check = DetBuffer_ptr->RuntimeId;
        if (Check == TRUE)
        {
            DetBuffer_ptr->ModuleId = 0;
            DetBuffer_ptr->InstanceId = 0;
            DetBuffer_ptr->ApiId = 0;
            DetBuffer_ptr->RuntimeId = 0;
            Result = TRUE;
        }
    }
    return !Result;
}

/**
 *  @brief          Tests if an expected error has been reported to DET
 *
 *  @details        Tests if an expected error has been reported to DET
 *                  Service ID:        
 *                  SRS ID:            
 *                  Design ID:         
 *                  Sync/Async:        Synchronous
 *                  Reentrancy:        Reentrant
 *
 *  @arg            uint16
 *  @param[in]      ModuleId          ID of the module reporting the error
 *  @arg            uint8
 *  @param[in]      InstanceId        ID of the Instance reporting the error
 *  @arg            uint8
 *  @param[in]      ApiId             ID of the API where the error has been generated from
 *  @arg            uint8
 *  @param[in]      ErrorId           Error Code
 * 
 *  @return         boolean     
 *  @retval         FALSE             
 *  @retval         TRUE             
 *
 *  @note           boolean - true in case of NO error has been reported to DET
 *
 **/
boolean Det_TestNoTransientFault(void) {
    uint16 Count = 0;
    boolean Result = FALSE, Check = FALSE;
    for (Count = 0;Count < Det_DetBuffIndex_u32; Count++)
    {
        Det_ConfigType *DetBuffer_ptr = &Det_g_DetErrBuffer[Count];
        Check = DetBuffer_ptr->FaultId;
        if (Check == TRUE)
        {
            DetBuffer_ptr->ModuleId = 0;
            DetBuffer_ptr->InstanceId = 0;
            DetBuffer_ptr->ApiId = 0;
            DetBuffer_ptr->FaultId = 0;
            Result = TRUE;
        }
    }
    return !Result;
}

#define STOP_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/*--------------------------------------------------- EOF ------------------------------------------------------------*/