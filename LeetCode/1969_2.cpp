#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> rearrangeArray(std::vector<int>& nums) {
      std::vector<int> ans;
      for(int i=1;i<nums.size()-1;i++){
         int a=nums[i-1];
         int b=nums[i];
         int c=nums[i+1];
         if(a>b && b>c || a<b && b<c)
         {
            std::swap(nums[i],nums[i+1]);
         }
      }
      return nums;
   }
};
