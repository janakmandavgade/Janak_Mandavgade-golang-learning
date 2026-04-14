#include "unity.h"
#include "all_tests.h"

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();
    
    run_odd_tests();       // Runs all 10 odd tests
    
    return UNITY_END();
}
