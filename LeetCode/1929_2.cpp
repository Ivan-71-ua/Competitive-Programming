#include <bits/stdc++.h>

class Solution{    
   public:    
      std::vector<int> getConcatenation(std::vector<int>& nums){            
         std::vector<int> ans;            
         int len;            
         len = nums.size();            
         for(int i = 0; i < 2 * len; i++){                
            ans.push_back(nums[i % len]);                
         }
         return ans;            
      }
};