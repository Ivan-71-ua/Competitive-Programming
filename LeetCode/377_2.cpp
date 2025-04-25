#include <bits/stdc++.h>

/*
    Given an array of distinct integers nums and a target integer 'target', 
    return the number of possible combinations that add up to target.
    
    Ex. nums = [1,2,3] target = 4
    Possible Combinations: (1,1,1,1) (1,1,2) (1,2,1) (1,3) (2,1,1,)
    (2,2) (3,1). 
    So, total number of combinations possible is 7.

    Time: O(n * m)
    Space: O(m)
*/

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    std::vector<unsigned int> dp(target+1, 0);
    dp[0] = 1;
    for(int total=1; total<=target; total++) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= total) dp[total] += dp[total - nums[i]];
            else break;
        }
    }
    return dp[target];
    }
};