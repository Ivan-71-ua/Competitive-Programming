#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
		std::vector<int> lost(100000 + 1, -1);
		int maxs = -1, mins = 100000 + 7;
		for (auto now: matches)
		{
			if(lost[now[0]] == -1) {
				lost[now[0]] = 0;
				maxs = std::max(maxs, now[0]);
				mins = std::min(mins, now[0]);
			} 
			if(lost[now[1]] <= 0) {
				lost[now[1]] = 1;
				maxs = std::max(maxs, now[1]);
				mins = std::min(mins, now[1]);
			} else {
				lost[now[1]]++;
			}
		}
		std::vector<std::vector<int>> res(2);
		for (int i = mins; i <= maxs ; i++)
		{
			if(lost[i] == 0) {
				res[0].push_back(i);
			} else if(lost[i] == 1) {
				res[1].push_back(i);
			}
		}
		return res;
	}
};