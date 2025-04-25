#include <bits/stdc++.h>



class Solution {
	std::vector<int> path;
	std::unordered_map<int, std::vector<int>> list;
	std::unordered_map<int, int> in, out;
	std::set<int> nodes;
	void dfs(int cur_node) {
		while(out[cur_node]) {
			int next = list[cur_node][out[cur_node] - 1];
			out[cur_node]--;
			dfs(next);
		}
		path.push_back(cur_node);
	}
public:
	std::vector<std::vector<int>> validArrangement(std::vector<std::vector<int>>& pairs) {
		for(auto k : pairs) {
			int a = k[0], b = k[1];
			list[a].push_back(b);
			in[b]++;
			out[a]++;
			nodes.insert(a);
			nodes.insert(b);
		}
		int start = INT32_MAX;
		for(int cur : nodes) {
			if(out[cur] == in[cur] + 1) {
				start = cur;
				break;
			}
		}
		if(start == INT32_MAX)
			start = pairs[0][0];
		dfs(start);
		std::reverse(path.begin(), path.end());
		std::vector<std::vector<int>> ans;
		for (int i = 1; i < path.size(); i++) {
			ans.push_back({path[i - 1], path[i]});
		}
		return ans;
	}
};