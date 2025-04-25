#include <bits/stdc++.h>



class Solution {
public:
   bool isPalindrome(int x) {
      if(x<0 || x!=0 && x%10 == 0){
         return false;
      }
      long long reversed = 0;
      while (x > reversed){
         reversed = reversed*10+x%10;
         x=x/10;
      }
      return (x == reversed || x == reversed/10);
   }
};