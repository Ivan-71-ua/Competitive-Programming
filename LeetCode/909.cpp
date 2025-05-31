#include <bits/stdc++.h>



class Solution {
public:
std::pair<int, int> getIdx(int num, int n) {
		int row = (num - 1) / n;
		int col = (num - 1) % n;
		if (row % 2 == 0) {
			return {n - 1 - row, col};
		} 
		return {n - 1 - row, n - 1 - col};
	}
	int snakesAndLadders(std::vector<std::vector<int>>& board) {
		int n = board.size();
		std::vector<int> dist(n * n + 1, -1);
		std::queue<int> q;
		q.push(1);
		dist[1] = 0;
		while(!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int i = 1; i < 7; i++) {
				int next = curr + i;
				if(next > n * n)
					continue;
				auto [row, col] = getIdx(next, n);
				if (board[row][col] != -1) {
					next = board[row][col];
				} 
				if(next == n * n) {
					return dist[curr] + 1;
				}
				if(dist[next] == -1) {
					dist[next] = dist[curr] + 1;
					q.push(next);
				}
			}
		}
		return -1;
	}
};