#include <bits/stdc++.h>



class Solution {
	int ans = 0;
	void backtrack(int mask, int n, std::vector<std::vector<int>>& requests) {
		std::vector<int> move(n, 0);
		int count = 0;
		for (int i = 0; i < requests.size(); i++)
		{
			if(mask & (1 << i)) {
				count++;
				int f = requests[i][0];
				int t = requests[i][1];
				move[f]--;
				move[t]++;
			}
		}
		for(auto &j: move) {
			if(j != 0)
				return;
		}
		ans = std::max(ans, count);
	}
public:
	int maximumRequests(int n, std::vector<std::vector<int>>& requests) {
		int r = 1 << requests.size();
		for (int i = 0; i < r; i++)
		{
			backtrack(i, n, requests);
		}
		return ans;
	}
};