cmake_minimum_required(VERSION 3.10)
project(UnityOddTest C)

# 1. Include paths for headers
include_directories(odd unity_lib)

# 2. Collect all source files
# We include main.c because it holds the entry point
set(SOURCES
    main.c
    odd/odd.c
    odd/test_odd.c
    unity_lib/unity.c
)

# 3. Create the executable
add_executable(run_tests ${SOURCES})

# 4. Compiler warnings for better debugging (optional)
target_compile_options(run_tests PRIVATE -Wall -Wextra)