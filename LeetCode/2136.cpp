#include <bits/stdc++.h>

class Solution {
public:
	int earliestFullBloom(std::vector<int>& plantTime, std::vector<int>& growTime) {
		std::vector<std::pair<int, int>> grow_do(plantTime.size());
		for (int i = 0; i < plantTime.size(); i++)
		{
			grow_do[i] = {growTime[i], plantTime[i]};
		}
		std::stable_sort(grow_do.begin(), grow_do.end(), std::greater());
		for (auto &now: grow_do)
		{
			std::cout << now.first  << ' ' << now.second << '\n';
		}
		int doing = 0;
		int grow = 0;
		for (auto &now: grow_do)
		{
			doing += now.second;
			grow = std::max(grow, doing + now.first);
		}
		return grow;
	}
};