#include <bits/stdc++.h>

class Solution {
public:
   bool checkSubarraySum(std::vector<int>& nums, int k) {
      std::unordered_map<int,int>m;
      m[0] = -1;
      int sum = 0;
      for(int i = 0;i < nums.size();i++){
         sum += nums[i];
         if(k != 0){
            sum %= k;
         }
         if(m.count(sum) > 0){
            if(i - m[sum] > 1) return true;
         }
         else{
            m[sum] = i;
         }
      }
      return false;
	}
};
int main() {
	Solution ans;
	std::vector<int> nums{5,0,0,0};

	std::cout << ans.checkSubarraySum(nums,3);
}