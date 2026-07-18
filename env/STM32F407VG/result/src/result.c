#include "result.h"
#include <setjmp.h>

#ifdef DEBUGGER_OZONE
    // #include "SEGGER_RTT.h"
#endif /* DGEBUGGER_OZONE */

#ifdef TEST_MULTICORE
    unsigned char CORE_NUM = 2;
    unsigned char volatile Core_Status[CORE_NUM]; 
    jmp_buf	jmpRESULT[CORE_NUM];
#else
    jmp_buf	jmpRESULT;
#endif /* TEST_MULTICORE */

// unsigned char volatile EndTest __attribute__((section(".mcal_bss_no_cacheable"))) = 0;
// unsigned char volatile TC __attribute__((section(".mcal_bss_no_cacheable"))) = 0;
// unsigned char volatile TestCaseResult[100] __attribute__((section(".mcal_bss_no_cacheable")));
// unsigned char volatile TestResultIndex  __attribute__((section(".mcal_bss_no_cacheable"))) = 0;

// unsigned char volatile HuLaLog[200] __attribute__((section(".mcal_bss_no_cacheable"))) = "===> YOUR TESTSUITE IS PASSED !!!@";
// unsigned char volatile Index_Log __attribute__((section(".mcal_bss_no_cacheable"))) = 0;

unsigned char volatile EndTest  = 0;
unsigned char volatile TC  = 0;
unsigned char volatile TestCaseResult[100] ;
unsigned char volatile TestResultIndex  = 0;

unsigned char volatile HuLaLog[200] = "===> YOUR TESTSUITE IS PASSED !!!@";
unsigned char volatile Index_Log = 0;



#ifdef TEST_MULTICORE
/* Set Core 1 Status is 0 */
/* Core 0 is MASTER, Core 1 is SLAVER */
void Clear_Slaves_Status()
{
    unsigned char Core;
    for (Core = 1; Core < CORE_NUM; Core++) 
    {
        Core_Status[Core] = 0;
    }
}
/* Set core 1 status */
void Set_Slaves_Status(unsigned char value)
{
    unsigned char Core;
    for (Core = 1; Core < CORE_NUM; Core++) 
    {
        Core_Status[Core] = value;
    }
}
/* Wait status Core 1 */
unsigned char Wait_Slaves_Status()
{
    unsigned char Wait = 0;
    unsigned char Core;
    for (Core = 1; Core < CORE_NUM; Core++) 
    {
        Wait |= (Core_Status[Core] != 1);
    }
    return(Wait);
}
#endif /* TEST_MULTICORE */


void RESULT_Init(RESULT_ThoNV_Full const* ResultThoNV)
{
    /* Set all result is NOT RUN */
    for(TC =0; TC <= 99;TC ++)
    {
        TestCaseResult[TC] = 2;
    }

    #ifdef TEST_MULTICORE
        unsigned char volatile Core_ID;
        Core_ID = RESULT_GetCoreID();
    #endif /* TEST_MULTICORE */

    #ifdef TEST_MULTICORE
        if (Core_ID == 0) 
        {
    #endif /* TEST_MULTICORE */
            unsigned char TestSuiteId;
            unsigned char TestCaseId;
            for(TestSuiteId = 0; TestSuiteId < ResultThoNV->TestSuiteCount; TestSuiteId++)
            {
                const RESULT_TestSuite* TestSuite = ResultThoNV->TestSuitePointer[TestSuiteId];

                for(TestCaseId = 0; TestCaseId < TestSuite->TestCaseCount; TestCaseId++)
                {
                    /* Set All Test case is NOT RUN*/
                    TestCaseResult[TestResultIndex] = 2;
                    TestResultIndex++;
                }
            }
    #ifdef TEST_MULTICORE
        }
    #endif /* TEST_MULTICORE */

#ifdef TEST_MULTICORE
    /* MASTER CORE */
    if (Core_ID == 0) 
    {
        /* Set all status core is 0*/
        Clear_Slaves_Status();

        /* Wait status core 1 */
        while(Wait_Slaves_Status());

        /* Set 2 core status is Not Busy */
        Core_Status[0] = 2;
        Set_Slaves_Status(2);
    }
    else  /* Core ID = 1 => SLAVER CORE */
    {
        /* Set core 0 (main core) status is 1 */
        while(Core_Status[Core_ID] != 0);
        while(Core_Status[Core_ID] != 2) 
        {
            if (Core_Status[Core_ID] == 0) 
            {
                Core_Status[Core_ID] = 1;
            }
        }
    }
#endif /* TEST_MULTICORE */
}


void RESULT_RunAllTests(RESULT_ThoNV_Full const* ResultThoNV)
{
    unsigned char TestSuiteId;
    unsigned char TestCaseId;

    #ifdef TEST_MULTICORE
        unsigned char Core_ID;
        Core_ID = RESULT_GetCoreID();
    #endif /* TEST_MULTICORE */

    TestResultIndex = 0;

    for(TestSuiteId = 0; TestSuiteId < ResultThoNV->TestSuiteCount; ++TestSuiteId)
    {

        const RESULT_TestSuite* TestSuite = ResultThoNV->TestSuitePointer[TestSuiteId];
        for(TestCaseId = 0; TestCaseId < TestSuite->TestCaseCount; ++TestCaseId)
        {
        #ifdef TEST_MULTICORE
            if (Core_ID == 0) 
            {
                while(Wait_Slaves_Status());
                Clear_Slaves_Status();
                Core_Status[0] = 0;
            }
            else 
            {
                Core_Status[Core_ID] = 1;
                while(Core_Status[0] != 0);
            }
        #endif /* TEST_MULTICORE */

            /* set test result to pass before run test case */
            TestCaseResult[TestResultIndex] = 1;

            /* #ifdef TEST_MULTICORE
                if(!setjmp(jmpRESULT[Core_ID]))
            #else
                if(!setjmp(jmpRESULT))
            #endif 
            {
                TestSuite->TestCasePointer[TestResultIndex]();
            } */

            TestSuite->TestCasePointer[TestResultIndex]();

        #ifdef TEST_MULTICORE
            Core_ID = RESULT_GetCoreID();
            if (Core_ID == 0) 
            {
                while(Wait_Slaves_Status());
                Clear_Slaves_Status();
                TestResultIndex++;
                Core_Status[0] = 1;
            }
            else
            {
                Core_Status[Core_ID] = 1;
                while(Core_Status[0] == 0);
            }
        #else
            TestResultIndex++;
        #endif /* TEST_MULTICORE */
        }
    }
    EndTest = 1;
}

#ifdef GET_LINE_FAILED
    void RESULT_Assert(unsigned char Result, char const * const Log)
#else
    void RESULT_Assert(unsigned char Result)
#endif
{
	if(!Result)
	{
	    /* Assert test fail */
        TestCaseResult[TestResultIndex] = 0;
        #ifdef GET_LINE_FAILED
            for (Index_Log = 0; Index_Log < 200; Index_Log++)
            {
                HuLaLog[Index_Log] = Log[Index_Log];
            }
        #endif
	}

    #ifdef DEBUGGER_OZONE
        // SEGGER_RTT_WriteString(0, Log);
    #endif /* DEBUGGER_OZONE */
}

#ifdef GET_LINE_FAILED
    void RESULT_Assert_End(unsigned char Result, char const * const Log)
#else
    void RESULT_Assert_End(unsigned char Result)
#endif
{
	if(!Result)
	{
	    /* Assert test fail */
        TestCaseResult[TestResultIndex] = 0;
        #ifdef GET_LINE_FAILED
            for (Index_Log = 0; Index_Log < 200; Index_Log++)
            {
                HuLaLog[Index_Log] = Log[Index_Log];
            }
        #endif

        // #ifdef TEST_MULTICORE
        //     longjmp(jmpRESULT[RESULT_GetCoreID()], 1);
        // #else
        //     longjmp(jmpRESULT, 1);
        // #endif 
	}

    #ifdef DEBUGGER_OZONE
        // SEGGER_RTT_WriteString(0, Log);
    #endif /* DEBUGGER_OZONE */
}

