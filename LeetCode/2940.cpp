#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> leftmostBuildingQueries(std::vector<int>& heights, std::vector<std::vector<int>>& queries) {
		int qsize = queries.size();
		std::vector<std::vector<std::pair<int, int>>> querys_end(heights.size());
		std::vector<int> ans(qsize, -1);
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q_idex_end;
		for (int i = 0; i < qsize; i++)
		{
			int a = queries[i][0], b = queries[i][1];
			if(a > b)
				std::swap(a, b);
			if(a == b || heights[a] < heights[b]) {
				ans[i] = b;
			} else {
				int maxs = std::max(heights[a], heights[b]);
				//int idx = std::max(a, b);
				querys_end[b].push_back({maxs, i});
			}
		}
		for (int i = 0; i < heights.size(); i++)
		{
			while(!q_idex_end.empty() && q_idex_end.top().first < heights[i]) {
				auto [ _ , idx ] = q_idex_end.top();
				q_idex_end.pop();
				ans[idx] = i;
				
			}
			while(!querys_end[i].empty()) {
				q_idex_end.push(querys_end[i].back());
				querys_end[i].pop_back();
			}
		}
		return ans;
	
	
	}
};


int main() {
	Solution ans;
	std::vector<int> heights{6, 4, 8, 5, 2, 7};
	std::vector<std::vector<int>> queries{{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
	ans.leftmostBuildingQueries(heights, queries);
}