#include <bits/stdc++.h>





class Solution {
public:
	std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
		int n = graph.size();
		std::vector<int> cnt(n);
		std::vector<std::vector<int>> revers(n);
		std::stack<int> del;
		for (int i = 0; i < n; i++) {
			if(graph[i].size() == 0) {
				cnt[i] = 0;
				del.push(i);
			} else {
				cnt[i] = graph[i].size();
				for(auto &k : graph[i]) {
					revers[k].push_back(i);
				}
			}
		}
		while(!del.empty()) {
			int d = del.top();
			del.pop();
			for (auto &&i : revers[d])
			{
				cnt[i]--;
				if(!cnt[i])
					del.push(i);
			}
		}
		std::vector<int> res;
		for (int i = 0; i < n; i++) {
			if(cnt[i] == 0)
				res.push_back(i);
		}
		return res;
	}
};

int main() {
	std::vector<std::vector<int>> ss{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
	Solution ans;
	ans.eventualSafeNodes(ss);
}