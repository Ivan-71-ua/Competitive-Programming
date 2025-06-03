#include <bits/stdc++.h>


class Solution {
public:
	int maxCandies(std::vector<int>& status, std::vector<int>& candies, std::vector<std::vector<int>>& keys, std::vector<std::vector<int>>& containedBoxes, std::vector<int>& initialBoxes) {
		int n = status.size(), res = 0;
		std::vector<bool> vis(n, false);
		std::vector<bool> can_open(n, false);
		std::vector<bool>has_box(n, false);
		std::queue<int> q;
		for (int i = 0; i < n; i++) {
			if(status[i] == 1) {
				can_open[i] = true;
			}
		}
		for(int g: initialBoxes) {
			has_box[g] = true;
			if(can_open[g]) {
				q.push(g);
				vis[g] = true;
				res += candies[g];
			}
		}
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			for(auto g: keys[cur]) {
				can_open[g] = true;
				if(!vis[g] && has_box[g]) {
					vis[g] = true;
					q.push(g);
					res += candies[g];
				}
			}
			for(auto g: containedBoxes[cur]) {
				has_box[g] = true;
				if(can_open[g] && !vis[g]) {
					vis[g] = true;
					q.push(g);
					res += candies[g];
				}
			}
		}
		return res;
	}
};