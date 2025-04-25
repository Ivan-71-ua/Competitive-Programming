#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {
		std::unordered_map<int, int> num;
		for (auto now: nums)
		{
			num[now]++;
		}
		std::vector<std::vector<int>> ans;
		std::vector<int> tmp;
		while (true)
		{
			for(auto now: num) {
				if(now.second > 0) {
					tmp.push_back(now.first);
					now.second--;
				}
			}
			if(tmp.empty()) break;
			else {
				ans.push_back(tmp);
				tmp.clear();
			}
		}
		return ans;
	}
};