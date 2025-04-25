#include <bits/stdc++.h>

class Solution {
public:
   int findSpecialInteger(std::vector<int>& arr) {
      if (arr.size() == 1) return arr[0];
      double condition = arr.size()*0.25;
      int freq = 1;
      for (int i = 1; i < arr.size(); ++i) {
         if (arr[i] == arr[i-1]) {
            ++freq;
            if (freq > condition) return arr[i];
         }else{
            freq = 1;
         }
      }
      return -1;
   }
};

int main() {
	Solution ans;
	std::vector<int> nums{1,1};
	std::cout << ans.findSpecialInteger(nums);
}