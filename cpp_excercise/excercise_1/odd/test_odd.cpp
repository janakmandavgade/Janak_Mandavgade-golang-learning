#include <gtest/gtest.h>
using namespace std;

#include "odd.h"  // Include your header!

// Test for correct output
TEST(OddNumbersTest, BasicTest) {
    std::vector<int> input = {1, 2, 3};
    std::vector<int> expected = {1, 3};

    vector<int> result = OddNumbers(input); 

    EXPECT_EQ(result, expected);
}

// Test for empty input
TEST(OddNumbersTest, ZeroInputTest) {
    std::vector<int> input = {};
    std::vector<int> expected = {};

    vector<int> result = OddNumbers(input); 

    EXPECT_EQ(result, expected);
}

// Test for empty output but filled input
TEST(OddNumbersTest, ZeroOutputTest) {
    std::vector<int> input = {2, 4, 6, 8};
    std::vector<int> expected = {};

    vector<int> result = OddNumbers(input); 

    EXPECT_EQ(result, expected);
}

// Test to check if CheckOdd returns correct result or not
TEST(OddNumbersTest, BasicNumIsOdd) {
    int in = 3;
    bool expected = true;
    bool result = CheckOdd(in); 

    EXPECT_EQ(result, expected);
}

// Test to check if CheckOdd returns correct result or not
TEST(OddNumbersTest, BasicNumIsNotOdd) {
    int in = 4;
    bool expected = false;
    bool result = CheckOdd(in); 

    EXPECT_EQ(result, expected);
}

// Test to check if CheckOdd returns correct result or not
TEST(OddNumbersTest, NegativeNumIsOdd) {
    int in = -3;
    bool expected = true;
    bool result = CheckOdd(in); 

    EXPECT_EQ(result, expected);
}

// Test to check if CheckOdd returns correct result or not
TEST(OddNumbersTest, NegativeNumIsNotOdd) {
    int in = -4;
    bool expected = false;
    bool result = CheckOdd(in);

    EXPECT_EQ(result, expected);
}

