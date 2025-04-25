#include <bits/stdc++.h>

class Solution {
	std::set<std::pair<int, int>> obs;
	std::vector<std::vector<int>> way{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int direc = 0;
	int x = 0, y = 0;
	
public:
	int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
		for (int i = 0; i < obstacles.size(); i++)
		{
			int x = obstacles[i][0];
			int y = obstacles[i][1];
			obs.insert({x, y});
		}
		int res = 0;
		int n = commands.size();
		for (int i = 0; i < n; i++)
		{
			if(commands[i] == -1) {
				direc = (direc + 1) % 4;
			} else if(commands[i] == -2) {
				direc = (direc - 1) % 4;
				if(direc < 0)
					direc = 3;
			} else {
				int dx = way[direc][0];
				int dy = way[direc][1];
				for (int j = 0; j < commands[i]; j++)
				{
					if(obs.count({x + dx, y + dy})) {
						break;
					}
					x += dx;
					y += dy;
				}
			}
			res = std::max(res, y * y + x * x);
		}
		return res;
	}
};