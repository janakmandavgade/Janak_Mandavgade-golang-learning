#include <math.h>
using namespace std;

bool CheckPrime(int num){
    if(num < 1) return false;
    // bool ans = true;
    for(int i = 2 ; i <= sqrt(num) ; i++){
        if(num % i == 0){
            // ans = false;
            return false;
        }
    }
    return true;

}