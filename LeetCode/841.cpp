#include <bits/stdc++.h>


class Solution {
	bool dfs(std::vector<std::vector<int>>& rooms, std::vector<bool> &visit, int start) {
		std::stack<int> way;
		int visited_count = 0;
		way.push(start);
		while (!way.empty()) {
			int cur = way.top();
			way.pop();
			if (!visit[cur]) {
				visit[cur] = true;
				visited_count++;
				for (int key : rooms[cur]) {
					way.push(key);
				}
			}
		}
		return visited_count == rooms.size();
	}
public:
	bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
		int k = rooms.size();
		std::vector<bool> visit(k, false);
		return dfs(rooms, visit, 0);
	}
};