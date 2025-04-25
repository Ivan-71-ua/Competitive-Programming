
#include <bits/stdc++.h>

class Solution {
	int solve(std::vector<int>& locations, int start, int finish, int fuel, std::vector<std::vector<int>> &dp) {
		if(fuel < 0)
			return 0;
		if(dp[start][fuel] != -1)
			return dp[start][fuel];
		int ans = 0;
		if(start == finish)
			ans++;
		for (int next = 0; next < locations.size(); next++)
		{
			if(next != start) {
				int diff = abs(locations[start] - locations[next]);
				ans = (ans + solve(locations, next, finish, fuel - diff, dp)) % 1000000007;
			}
		}
		return dp[start][fuel] = ans;
	}
public:
	int countRoutes(std::vector<int>& locations, int start, int finish, int fuel) {
		std::vector<std::vector<int>> dp(locations.size(), std::vector<int>(fuel + 1, -1));
		return solve(locations, start, finish, fuel, dp);
	}
};


