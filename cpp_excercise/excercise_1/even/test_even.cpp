#include <gtest/gtest.h>
using namespace std;

#include "even.h"

TEST(EvenNumbersTest, BasicTest){
    vector<int> input = {1, 2, 3, 4};
    vector<int> output = {2, 4};

    vector<int> result = EvenNumbers(input);
    
    EXPECT_EQ(result, output);
}

TEST(EvenNumbersTest, ZeroInputTest){
    vector<int> input = {};
    vector<int> output = {};

    vector<int> result = EvenNumbers(input);
    
    EXPECT_EQ(result, output);
}

TEST(EvenNumbersTest, ZeroOutputTest){
    vector<int> input = {1, 3};
    vector<int> output = {};

    vector<int> result = EvenNumbers(input);
    
    EXPECT_EQ(result, output);
}

TEST(EvenNumbersTest, NumberIsEven){
    int input = 4;
    bool output = true;

    bool result = CheckEven(input);
    
    EXPECT_EQ(result, output);
}

TEST(EvenNumbersTest, NumberIsNotEven){
    int input = 5;
    bool output = false;

    bool result = CheckEven(input);
    
    EXPECT_EQ(result, output);
}

TEST(EvenNumbersTest, NegativeNumberIsEven){
    int input = -4;
    bool output = true;

    bool result = CheckEven(input);
    
    EXPECT_EQ(result, output);
}

TEST(EvenNumbersTest, NegativeNumberIsNotEven){
    int input = -5;
    bool output = false;

    bool result = CheckEven(input);
    
    EXPECT_EQ(result, output);
}
