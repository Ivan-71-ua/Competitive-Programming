#include <bits/stdc++.h>

static const auto _ = []{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	return 0;
}();

class Solution {
public:
	std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {
		std::unordered_map<int,int>mp;
		int cnt=0;
		for(auto it:nums){
		mp[it]++;
		cnt=std::max(cnt,mp[it]);
		}
		std::vector<std::vector<int>>ans(cnt);                  
		for(auto it:mp){
		int num = it.first;
		int freq=it.second;
		for(int i =0;i<freq;i++){
				ans[i].push_back(num);
		}
		}
		return ans;
	}
};