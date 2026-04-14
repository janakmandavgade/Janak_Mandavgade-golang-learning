#include <gtest/gtest.h>
#include <functional>
using namespace std;

#include "3multiples/threemultiples.h"
#include "5multiples/fivemultiples.h"
#include "even/even.h"
#include "odd/odd.h"
#include "prime/prime.h"

#define Filters vector<function<bool(int)>> 

bool AnyConditionCheck(int num, Filters f){
    for(auto &c : f){
        if(c(num)){
            return true;
        }
    }
    return false;
}

bool AllConditionCheck(int num, Filters f){
    for(auto &c : f){
        if(!c(num)){
            return false;
        }
    }
    return true;
}

vector<int> FilterAndReturn(vector<int> &input, Filters &f, bool isAny){
    int n = input.size();
    int m = f.size();

    vector<int> op;
    for(int i = 0 ; i < n ; i++){
        int ele = input[i];
        bool validCondition = isAny ? AnyConditionCheck(ele, f) : AllConditionCheck(ele, f);
        if(validCondition){
            op.push_back(ele);
        }
    }
    return op;
}

void PrintVec(vector<int> &v){
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i] << " ";
    }
    cout<<endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    vector<int> ip = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // CheckPrime, CheckOdd, CheckEven
    Filters f;

    bool isPrime, isOdd, isEven, isAny;
    cout<<"(Enter 0 or 1)\nIs Prime Required: ";
    cin>>isPrime;
    cout<<endl;

    cout<<"Is Odd Required: ";
    cin>>isOdd;
    cout<<endl;

    cout<<"Is Even Required: ";
    cin>>isEven;
    cout<<endl;

    cout<<"(0 -> All, 1 -> Any)\nAll or any Required: ";
    cin>>isAny;
    cout<<endl;

    if(isPrime) f.push_back(CheckPrime);
    if(isOdd) f.push_back(CheckOdd);
    if(isEven) f.push_back(CheckEven);
    // if(isPrime) f.push_back(CheckPrime);

    vector<int> op = FilterAndReturn(ip, f, isAny);

    PrintVec(op);

    return RUN_ALL_TESTS();
}