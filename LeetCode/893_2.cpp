#include <bits/stdc++.h>


class Solution {
public:
	int numSpecialEquivGroups(std::vector<std::string>& words) {
		std::map<std::string, int> group;
		for (auto wd: words)
		{
			std::string odd, even;
			for (int i = 0; i < wd.size(); i++)
			{
				if(i & 1)
					even += wd[i];
				else
					odd += wd[i];
			}
			std::stable_sort(even.begin(), even.end());
			std::stable_sort(odd.begin(), odd.end());
			group[even + odd]++;
		}
		return group.size();
	}
};
