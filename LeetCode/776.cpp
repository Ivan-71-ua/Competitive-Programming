

#include <bits/stdc++.h>

class Solution {
public:
	int slidingPuzzle(std::vector<std::vector<int>>& board) {
		std::string patert = "123450";
		std::string cur;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cur += '0' + board[i][j];
			}
		}
		std::set<std::string> used;
		std::queue<std::pair<std::string, int>> q;
		q.push({cur, 0});
		while(!q.empty()) {
			auto [st, step] = q.front();
			q.pop();
			if(st == patert)
				return step;
			used.insert(st);
			int idx = -1;
			for (int i = 0; i < 6; i++)
			{
				if(st[i] == '0') {
					idx = i;
					break;
				}
			}
			if(idx - 3 >= 0) {
				std::swap(st[idx], st[idx - 3]);
				if(!used.count(st)) {
					q.push({st, step + 1});
				}
				std::swap(st[idx], st[idx - 3]);
			}
			if(idx + 3 <= 5) {
				std::swap(st[idx], st[idx + 3]);
				if(!used.count(st)) {
					q.push({st, step + 1});
				}
				std::swap(st[idx], st[idx + 3]);
			}
			if(idx != 2 && idx != 5) {
				std::swap(st[idx], st[idx + 1]);
				if(!used.count(st)) {
					q.push({st, step + 1});
				}
				std::swap(st[idx], st[idx + 1]);
			}
			if(idx != 0 && idx != 3) {
				std::swap(st[idx], st[idx - 1]);
				if(!used.count(st)) {
					q.push({st, step + 1});
				}
				std::swap(st[idx], st[idx - 1]);
			}
		}
		return -1;
	}
};