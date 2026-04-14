#include "unity.h"
#include "odd.h"

// // Runs before every test
// void setUp(void) {}

// // Runs after every test
// void tearDown(void) {}

void test_Unit_Odd_CheckOdd_BasicIsOdd_01(void)
{
    int num = 3;
    bool expected = true;
    bool result = CheckOdd(num);

    TEST_ASSERT_EQUAL_INT_MESSAGE(result, expected, "Failed in basic test for BasicIsOdd");
}

void test_Unit_Odd_CheckOdd_BasicIsNotOdd_02(void)
{
    int num = 4;
    bool expected = false;
    bool result = CheckOdd(num);

    TEST_ASSERT_EQUAL_INT_MESSAGE(result, expected, "Failed in basic test for BasicIsNotOdd");
}

void test_Unit_Odd_CheckOdd_NegativeNumIsOdd_03(void)
{
    int num = -3;
    bool expected = true;
    bool result = CheckOdd(num);

    TEST_ASSERT_EQUAL_INT_MESSAGE(result, expected, "Failed in test for Negative number is Odd");
}

void run_odd_tests(void)
{
    RUN_TEST(test_Unit_Odd_CheckOdd_BasicIsOdd_01);
    RUN_TEST(test_Unit_Odd_CheckOdd_BasicIsNotOdd_02);
    RUN_TEST(test_Unit_Odd_CheckOdd_NegativeNumIsOdd_03);
}
