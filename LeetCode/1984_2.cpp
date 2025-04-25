#include <bits/stdc++.h>

class Solution {
public:
    int minimumDifference(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = k - 1;
        int res = INT_MAX;
        
        while(r < nums.size()) {
            res = std::min(res, nums[r] - nums[l]);
            l = l + 1;
            r = r + 1;
        }
        return res;
    }
};