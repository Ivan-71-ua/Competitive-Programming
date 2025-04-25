
#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> maxPoints(std::vector<std::vector<int>>& grid, std::vector<int>& queries) {
		std::map<int, std::vector<int>> mp_q_id;
		std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<>> pq;
		int cnt = 0;
		for (int i = 0; i < queries.size(); i++) {
			mp_q_id[queries[i]].push_back(i);
		}
		std::vector<int> ans(queries.size(), 0);
		int n = grid.size(), m = grid[0].size();
		std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, 0));
		pq.push({grid[0][0], 0, 0});
		visited[0][0] = 1;
		for(auto [val, arr_idx] : mp_q_id) {
			while(!pq.empty() && pq.top()[0] < val) {
				auto arr = pq.top();
				pq.pop();
				int x = arr[1], y = arr[2];
				cnt++;
				if(x + 1 < n && visited[x + 1][y] == 0) {
					pq.push({grid[x + 1][y], x + 1, y});
					visited[x + 1][y] = 1;
				}
				if(y + 1 < m && visited[x][y + 1] == 0) {
					pq.push({grid[x][y + 1], x, y + 1});
					visited[x][y + 1] = 1;
				}
				if(x - 1 > -1 && visited[x - 1][y] == 0) { 
					pq.push({grid[x - 1][y], x - 1, y});
					visited[x - 1][y] = 1;
				}
				if(y - 1 > -1 && visited[x][y - 1] == 0) {
					pq.push({grid[x][y - 1], x, y - 1});
					visited[x][y - 1] = 1;	
				}
			}
			for(auto idx: arr_idx) {
				ans[idx] = cnt;
			}
		}
		return ans;
	}
};

int main() {
	std::vector<std::vector<int>> grid{{1,2,3},{2,5,7},{3,5,1}};
	std::vector<int> queries{5,6,2};
	Solution s;
	auto ans = s.maxPoints(grid, queries);
	for(auto a: ans) {
		std::cout << a << ' ';
	}
	std::cout << '\n';
	return 0;
}



