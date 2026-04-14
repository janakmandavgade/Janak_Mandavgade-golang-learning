#include <gtest/gtest.h>
using namespace std;

#include "prime.h"

TEST(PrimeNumbersTest, BasicIsPrimeTest){
    // vector<int> input = {1, 2, 3, 4, 5};
    // vector<int> output   = {1, 2, 3, 5}
    int input = 3;
    bool output = true;
    bool expected = CheckPrime(input);

    EXPECT_EQ(expected, output);
}

TEST(PrimeNumbersTest, BasicIsNotPrimeTest){
    // vector<int> input = {1, 2, 3, 4, 5};
    // vector<int> output   = {1, 2, 3, 5}
    int input = 4;
    bool output = false;
    bool expected = CheckPrime(input);

    EXPECT_EQ(expected, output);
}

TEST(PrimeNumbersTest, BasicNegNumIsNotPrimeTest){
    // vector<int> input = {1, 2, 3, 4, 5};
    // vector<int> output   = {1, 2, 3, 5}
    int input = -4;
    bool output = false;
    bool expected = CheckPrime(input);

    EXPECT_EQ(expected, output);
}

TEST(PrimeNumbersTest, ZeroIsNotPrimeTest){
    // vector<int> input = {1, 2, 3, 4, 5};
    // vector<int> output   = {1, 2, 3, 5}
    int input = 0;
    bool output = false;
    bool expected = CheckPrime(input);

    EXPECT_EQ(expected, output);
}

// TEST(PrimeNumbersTest, ZeroIsNotPrimeTest){
//     // vector<int> input = {1, 2, 3, 4, 5};
//     // vector<int> output   = {1, 2, 3, 5}
//     int input = 0;
//     bool output = false;
//     bool expected = CheckPrime(input);

//     EXPECT_EQ(expected, output);
// }



