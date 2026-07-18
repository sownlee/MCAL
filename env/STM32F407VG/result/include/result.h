#ifndef RESULT_T
#define RESULT_T
#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef void (* const RESULT_TestCase)(void);
typedef struct {
    unsigned short          TestCaseCount;
    RESULT_TestCase* const    TestCasePointer;
} RESULT_TestSuite;

typedef struct {
    unsigned short          TestSuiteCount;
    const RESULT_TestSuite**    TestSuitePointer;
} RESULT_ThoNV_Full;

#define RESULT_TS_BEGIN(TestSuiteName) \
    static const RESULT_TestCase _##TestSuiteName##List[] = {
#define RESULT_TC(TestCaseName, testCaseDescription) TestCaseName
#define RESULT_TS_END(TestSuiteName) \
    }; \
    static const RESULT_TestSuite TestSuiteName = { \
        sizeof(_##TestSuiteName##List)/sizeof(_##TestSuiteName##List[0]), _##TestSuiteName##List \
    };

#define RESULT_THONV_BEGIN() \
	static const RESULT_TestSuite* Test_ThoNV_List[] = {
#define RESULT_TS(TestSuiteName, TestSuiteDescription) &(TestSuiteName)
#define RESULT_THONV_END() \
	}; \
	static const RESULT_ThoNV_Full ResultThoNVFull = { \
		sizeof(Test_ThoNV_List)/sizeof(Test_ThoNV_List[0]), Test_ThoNV_List};

#define LINE_QUOT(a) LINE_QUOT_AGAIN(a)
#define LINE_QUOT_AGAIN(a) #a

#define RESULT_RUN_ALL_TESTS() {RESULT_Init(&ResultThoNVFull); RESULT_RunAllTests(&ResultThoNVFull);}

#ifdef GET_LINE_FAILED
    #define RESULT_ASSERT(Result) \
        {RESULT_Assert(Result, "===> RESULT_ASSERT(" LINE_QUOT(#Result) "): TEST FAILED IN FILE: " LINE_QUOT(__FILE__) ", AT LINE: " LINE_QUOT(__LINE__)"@");}
    #define RESULT_ASSERT_END(Result) \
        {RESULT_Assert_End(Result, "===> RESULT_ASSERT(" LINE_QUOT(#Result) "): TEST FAILED IN FILE: " LINE_QUOT(__FILE__) ", AT LINE: " LINE_QUOT(__LINE__)"@");}
#else
    #define RESULT_ASSERT(Result) {RESULT_Assert(Result);}
    #define RESULT_ASSERT_END(Result) {RESULT_Assert_End(Result);}
#endif


void RESULT_Init(RESULT_ThoNV_Full const* ResultThoNV);
void RESULT_RunAllTests(RESULT_ThoNV_Full const* ResultThoNV);

#ifdef GET_LINE_FAILED
    void RESULT_Assert(unsigned char Result, char const * const Log);
    void RESULT_Assert_End(unsigned char Result, char const * const Log);
#else
    void RESULT_Assert(unsigned char Result);
    void RESULT_Assert_End(unsigned char Result);
#endif


#ifdef TEST_MULTICORE
void Clear_Slaves_Status(void);
void Set_Slaves_Status(unsigned char value);
unsigned char Wait_Slaves_Status(void);
extern unsigned char RESULT_GetCoreID(void);
#endif /* TEST_MULTICORE */

#endif /* RESULT_T */
