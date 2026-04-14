#include <gtest/gtest.h>
using namespace std;

#include "threemultiples.h"

TEST(ThreeMultipleTest, BasicTest){
    vector<int> input = {1,2,3,4,5,10, 20, 10000};
    vector<int> output = {5,10, 20, 10000};

    vector<int> result = ThreeMultiple(input);

    EXPECT_EQ(result, output);
}

TEST(ThreeMultipleTest, ZeroInputTest){
    vector<int> input = {};
    vector<int> output = {};

    vector<int> result = ThreeMultiple(input);

    EXPECT_EQ(result, output);
}

TEST(ThreeMultipleTest, ZeroOutputTest){
    vector<int> input = {1,2,3,4};
    vector<int> output = {};

    vector<int> result = ThreeMultiple(input);

    EXPECT_EQ(result, output);
}
