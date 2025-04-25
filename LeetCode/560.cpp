#include <bits/stdc++.h>

class Solution {
public:
	int subarraySum(std::vector<int>& nums, int target) {
      int j=0,count=0,n=size(nums),sum=0;
      std::unordered_map<int,int>mp;
      while(j<n){
         sum+=nums[j];
         if(sum==target)count++;
         if(mp.find(sum-target)!=mp.end())count+=mp[sum-target];
         mp[sum]++;
         j++;
      } 
      return count;
   }
};