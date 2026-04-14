#include <gtest/gtest.h>
using namespace std;

#include "fivemultiples.h"

TEST(FiveMultipleTest, BasicTest){
    vector<int> input = {1,2,3,4,5,10, 20, 10000};
    vector<int> output = {5,10, 20, 10000};

    vector<int> result = FiveMultiple(input);

    EXPECT_EQ(result, output);
}

TEST(FiveMultipleTest, ZeroInputTest){
    vector<int> input = {};
    vector<int> output = {};

    vector<int> result = FiveMultiple(input);

    EXPECT_EQ(result, output);
}

TEST(FiveMultipleTest, ZeroOutputTest){
    vector<int> input = {1,2,3,4};
    vector<int> output = {};

    vector<int> result = FiveMultiple(input);

    EXPECT_EQ(result, output);
}
