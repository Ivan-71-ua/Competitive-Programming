#include <bits/stdc++.h>


class Solution {
public:
	long long maximumValueSum(std::vector<std::vector<int>>& board) {
		int m = board.size();
		int n = board[0].size();
		std::vector<std::vector<std::pair<int, int>>> max_in_r(m);
		for (int i = 0; i < m; i++)
		{
			std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
			for (int j = 0; j < n; j++)
			{
				q.push({board[i][j], j});
				if(q.size() > 3)
					q.pop();
			}
			while(!q.empty()) {
				max_in_r[i].push_back(q.top());
				q.pop();
			}
		}
		long long ans = LLONG_MIN;
		for (int i = 0; i < m - 2; i++)
		{
			for (int j = i + 1; j < m - 1; j++)
			{
				for (int k = j + 1; k < m; k++)
				{
					for(auto [val1, col1]: max_in_r[i]) {
						for (auto [val2, col2]: max_in_r[j])
						{
							if(col1 == col2) continue;
							for (auto [val3, col3]: max_in_r[k])
							{
								if(col1 == col3 || col2 == col3) continue;
								ans = std::max(ans, (long long)(val1) + val2 + val3);
							}
						}
					}
				}
			}
		}
		return ans;
	}
};