#include <bits/stdc++.h> 


int main(){
   long long len;
   std::cin >> len;
    long long Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
     long long  missingNumber=0;
    for(int i=0;i < len; i++){
        int tmp;
        std::cin >> tmp;
        Sum_N -= tmp;
        Sum_NSq -= tmp * tmp;
    }
    if(Sum_N == 0) {
        std::cout << -1;
    } else {
        missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
        std::cout << missingNumber;
    }
}