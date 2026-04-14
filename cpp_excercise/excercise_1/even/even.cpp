#include <iostream>
#include <vector>
using namespace std;

bool CheckEven(int num){
    num = num < 0 ? abs(num) : num;
    if(num%2 == 0) return true;
    return false;
}

vector<int> EvenNumbers(vector<int> &arr){
    int n = arr.size();
    vector<int> output;
    for(int i = 0 ; i < n ; i++){
        if(CheckEven(arr[i])){
            output.push_back(arr[i]);
        }
    }
    return output;
}