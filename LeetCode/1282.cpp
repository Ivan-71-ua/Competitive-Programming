#include <bits/stdc++.h>


const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
	std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
		std::unordered_map<int, std::vector<int>> group;
		for (int i = 0; i < groupSizes.size(); i++)
		{
			group[groupSizes[i]].push_back(i);
		}
		std::vector<std::vector<int>> ans;
		for (auto now: group)
		{
			std::vector<int> tmp;
			for (int i = 0; i < now.second.size(); i++)
			{
				if(i + 1 % now.first == 0)  {
					tmp.push_back(now.second[i]);
					ans.push_back(tmp);
					tmp.clear();
				} else {
					tmp.push_back(now.second[i]);
				}
			}
		}
		return ans;
	}
};