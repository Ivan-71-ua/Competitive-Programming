#include <bits/stdc++.h>


class Solution {
	long long maximumValueSum2(std::vector<std::vector<int>>& board) {
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
public:
	long long maximumValueSum(std::vector<std::vector<int>>& board) {
		int m = board.size();
		int n = board[0].size();
		if(m < 11 && n < 11) {
			return maximumValueSum2(board);
		}
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
		for (int row1 = 0; row1 < m; row1++)
		{
			for (auto [val1, col1]: max_in_r[row1])
			{
				std::priority_queue < std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> q;
				std::vector<std::vector<int>> max4;
				for (int row2 = 0; row2 < m; row2++)
				{
					if(row1 == row2) continue;
					for (auto [val2, col2]: max_in_r[row2])
					{
						if(col1 == col2) continue;
						q.push({val2, row2, col2});
						if(q.size() > 4)
							q.pop();
					}
				}
				while(!q.empty()) {
					max4.push_back(q.top());
					q.pop();
				}
				for (int i = 0; i < 3; i++)
				{
					long long val2 = max4[i][0];
					int row2 = max4[i][1];
					int col2 = max4[i][2];
					if(col1 == col2 || row1 == row2) {
						continue;
					}
					for (int p = i + 1; p < max4.size(); p++)
					{
						long long val3 = max4[p][0];
						int row3 = max4[p][1];
						int col3 = max4[p][2];
						if(col3 == col2 || row2 == row3) {
							continue;
						}
						ans = std::max(ans, (long long)val1 + (long long)val2 + (long long)val3);
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	
	std::vector<std::vector<int>> ss{{1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
	ans.maximumValueSum(ss);
}