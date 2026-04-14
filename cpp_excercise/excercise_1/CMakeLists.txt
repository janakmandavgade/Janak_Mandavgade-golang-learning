cmake_minimum_required(VERSION 3.11.0)

# 1. Locate the GTest package on your system
find_package(GTest REQUIRED)

add_executable(run_tests 
    ./odd/test_odd.cpp 
    ./odd/odd.cpp
    
    ./even/test_even.cpp
    ./even/even.cpp

    ./5multiples/fivemultiples.cpp
    ./5multiples/test_fivemultiples.cpp

    ./3multiples/threemultiples.cpp 
    ./3multiples/test_threemultiples.cpp

    ./prime/prime.cpp 
    ./prime/test_prime.cpp

    test_main.cpp
)

# 2. Link the targets found by find_package
target_link_libraries(run_tests GTest::gtest_main)