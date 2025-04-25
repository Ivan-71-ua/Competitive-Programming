
#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
		std::map<int, int> lose;
		std::map<int, int> win;
		std::set<int> players;
		for (int i = 0; i < matches.size(); i++)
		{
			players.insert(matches[i][0]);
			players.insert(matches[i][1]);
			lose[matches[i][1]]++;
			win[matches[i][0]]++;
		}
		std::vector<std::vector<int>> res(2, std::vector<int>());
		for (auto now: players)
		{
			if(win[now] > 0 && lose[now] == 0) {
				res[0].push_back(now);
			} else if(lose[now] == 1) {
				res[1].push_back(now);
			}
		}
		return res;
	}
};