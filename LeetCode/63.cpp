#include <bits/stdc++.h>

const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int uniquePathsWithObstacles(std::vector<std::vector<int>>& ob) {
		std::vector<long long> dp(ob[0].size());
		dp[ob[0].size() - 1] = 1;
		for (int i = ob.size() - 1; i >= 0; i--)
		{
			for (int j = ob[0].size() - 1; j >= 0; j--)
			{
				if(ob[i][j] == 1)
					dp[j] = 0;
				else if(j + 1 < ob[0].size()) {
					dp[j] += dp[j + 1];
				}
			}
		}
		return dp[0];
	}
};


int main() {
	Solution ams;
	std::vector<std::vector<int>> ss{{0,0,0},{0,1,0},{0,0,0}};
	ams.uniquePathsWithObstacles(ss);
}