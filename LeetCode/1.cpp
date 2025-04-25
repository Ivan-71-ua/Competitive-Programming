


#include <bits/stdc++.h>

    
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


   const int ZERO = []()
   {
      std::ios_base::sync_with_stdio(false);
      std::cin.tie(nullptr);
      return 0;
   }();


static const bool Booster = [](){
     std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);      
      std::cout.tie(nullptr);
    return true;
}();

class Solution {
public:
   std::vector<int> twoSum(std::vector<int>& nums, int target) {
       std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      std::cout.tie(nullptr);
      std::unordered_map<int, int> numMap;
      int n = nums.size();
      for (int i = 0; i < n; i++) {
         int complement = target - nums[i];
         if (numMap.count(complement)) {
            return {numMap[complement], i};
         }
         numMap[nums[i]] = i;
      }
      return {}; 
   }
   std::vector<double> find_numbers(std::vector<double> array, double persent) {
      std::vector<double> ans;
      for (int i = 0; i < array.size(); i++) {
         std::string num = std::to_string(array[i]);
         int ch = -1;
         for (int j = 0; j < num.size(); j++) {
            if(!isdigit(num[j])) {
               ch = i;
               break;
            }
         }
         std::string first = num.substr(0, ch);
         std::string second = num.substr(ch + 1);
         int d_first = std::stoi(first);
         int d_second = std::stoi(second);
         if((d_first * persent) / 100 < d_second) {
            ans.push_back(array[i]);
         }
      }
      return ans;
   }
};

int main() {
	Solution ans;
	std::vector<double> nums{60.30, 0};
   ans.find_numbers(nums, 20.0);
}