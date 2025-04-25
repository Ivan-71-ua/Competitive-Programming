#include <bits/stdc++.h>


class Solution {
	bool zero(std::vector<std::vector<int>> &mat) {
		for (auto row: mat)
		{
			for (auto col: row)
			{
				if(col != 0)
					return false;
			}
		}
		return true;
	}
	std::pair<bool, int> bfs(std::vector<std::vector<int>> mat, int x, int y) {
		std::vector<std::vector<bool>> used(mat.size(), std::vector<bool>(mat[0].size()));
		std::queue<std::pair<int, int>> way;
		int count = 0;
		way.push({x, y});
		while(!way.empty()) {
			std::queue<std::pair<int, int>> tmp;
			while(!way.empty()) {
				count++;
				auto pr = way.front();
				way.pop();
				if(!used[pr.first][pr.second]) {
					used[pr.first][pr.second] = true;
					mat[pr.first][pr.second] = (mat[pr.first][pr.second] + 1) % 2;
					if(pr.first + 1 < mat.size()) {
						tmp.push({pr.first + 1, pr.second});
						mat[pr.first + 1][pr.second] = (mat[pr.first + 1][pr.second] + 1) % 2;
					}
					if(pr.second + 1 < mat[0].size()) {
						tmp.push({pr.first, pr.second + 1});
						mat[pr.first][pr.second + 1] = (mat[pr.first][pr.second + 1] + 1) % 2;
					}
					if(pr.first - 1 > -1) {
						tmp.push({pr.first - 1, pr.second});
						mat[pr.first - 1][pr.second] = (mat[pr.first - 1][pr.second] + 1) % 2;
					}
					if(pr.second -1 > -1) {
						tmp.push({pr.first, pr.second - 1});
						mat[pr.first][pr.second - 1] = (mat[pr.first][pr.second - 1] + 1) % 2;
					}
					if(zero(mat))
						return {true, count};
				}
			}
			way = tmp;
		}
		return {false, -1};
	}
public:
	int minFlips(std::vector<std::vector<int>>& mat) {
		if(zero(mat)) {
			return 0;
		}
		int res = INT32_MAX;
		for (int i = 0; i < mat.size(); i++)
		{
			for (int j = 0; j < mat[0].size(); j++) {
				auto ans = bfs(mat, i, j);
				if(ans.first) {
					res = std::min(res, ans.second);
				}
			}
		}
		if(res == INT32_MAX) {
			return -1;
		}
		return res;
	}
};