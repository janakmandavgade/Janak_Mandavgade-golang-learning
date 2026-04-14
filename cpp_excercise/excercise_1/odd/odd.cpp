#include <iostream>
#include <vector>
using namespace std;

#include "odd.h"

bool CheckOdd(int num){
    num = num < 0 ? abs(num) : num;
    if(num%2 == 1) return true;
    return false;
}

vector<int> OddNumbers(vector<int> &ip){

    int n = ip.size();
    vector<int> op;
    if(n == 0){
        return {};
    }

    for(int i = 0 ; i < n ; i++){
        if(CheckOdd(ip[i])){
            op.push_back(ip[i]);
        }
    }

    return op;
}

// int main(){
    
//     vector<int> v = {1,3,5,7,9};
//     vector<int> op = OddNumbers(v);

//     for(int i = 0 ; i < op.size() ; i++){
//         cout<<op[i]<<" ";
//     }
//     cout<<endl;

//     return 0;
// }