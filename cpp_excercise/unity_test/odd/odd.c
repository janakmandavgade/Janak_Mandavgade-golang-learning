#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool CheckOdd(int num) {
    return (abs(num) % 2 == 1);
}

void FilterOddNumbers(int* arr, int sz, int* output, int* sz_op) {
    int j = 0;
    for (int i = 0; i < sz; i++) {
        if (CheckOdd(arr[i])) {
            output[j] = arr[i];
            j++;
        }
    }
    // Update the caller's variable with the number of odds found
    *sz_op = j;
}

void PrintArr(int *arr, int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// int main() {
//     // 1. Input data
//     int arr[4] = {1, 2, 3, 4};
//     int sz = 4;

//     // 2. Output buffer (Reserved on the stack of main)
//     // In embedded, we usually make this the same size as input to be safe
//     int output_buffer[4]; 
//     int sz_op = 0;

//     // 3. Pass the buffer to be filled
//     FilterOddNumbers(arr, sz, output_buffer, &sz_op);

//     // 4. Use the result
//     PrintArr(output_buffer, sz_op);

//     return 0;
// }