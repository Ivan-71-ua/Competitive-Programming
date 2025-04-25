#include <bits/stdc++.h>

class Solution {
public:
   int maxProduct(std::vector<int>& nums) {
      int biggest = 0;
      int secondBiggest = 0;
      for (int num : nums) {
         if (num > biggest) {
            secondBiggest = biggest;
            biggest = num;
         } else {
            secondBiggest = std::max(secondBiggest, num);
         }
      }
      return (biggest - 1) * (secondBiggest - 1);
   }
};


int main() {
	Solution ans;
	std::vector p{3, 4, 5, 2};
	std::cout << ans.maxProduct(p);
}