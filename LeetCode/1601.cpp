#include <bits/stdc++.h>


class Solution {
	int ans = 0;
	std::vector<int> move;
	void backtrack(int i, int count, int length, std::vector<std::vector<int>>& requests) {
		if(i == length) {
			for (auto &k: move)
			{
				if(k != 0) {
					return;
				}
			}
			ans = std::max(ans, count);
			return;
		}
		int f = requests[i][0];
		int t = requests[i][1];
		move[f]--;
		move[t]++;
		backtrack(i + 1, count + 1, length, requests);
		move[f]++;
		move[t]--;
		backtrack(i + 1, count, length, requests);
	}
public:
	int maximumRequests(int n, std::vector<std::vector<int>>& requests) {
		move.resize(n, 0);
		backtrack(0, 0, requests.size(), requests);
		return ans;
	}
};