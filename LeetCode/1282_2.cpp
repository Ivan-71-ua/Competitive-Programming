#include <bits/stdc++.h>

static const auto _ = []{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	return 0;
}();

class Solution {
public:
	std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
		int n = groupSizes.size();
		std::map<int,std::vector<int>> mp;
		for(int i=0;i<n;i++){
				mp[groupSizes[i]].push_back(i);
		}
		std::vector<std::vector<int>> ans;
		for(auto i : mp){
				std::vector<int> tempi;
				for(auto j : i.second){
					tempi.push_back(j);
					if(tempi.size() == i.first){
						ans.push_back(tempi);
						tempi.clear();
					}
				}
		}
		return ans;
	}
};