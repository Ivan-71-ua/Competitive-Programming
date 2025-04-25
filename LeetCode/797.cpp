#include <bits/stdc++.h>



class Solution {
	void DFS(std::vector<std::vector<int>> &graph, std::vector<bool> &used, int start, 
	std::vector<int> way, std::vector<std::vector<int>> &ans) {
		used[start] = true;
		way.push_back(start);
		if(start == graph.size() -1) {
			ans.push_back(way);
			used[start] = false;
		}
		for (int i = 0; i < graph[start].size(); i++)
		{
			if(!used[graph[start][i]]) {
				DFS(graph, used, graph[start][i], way, ans);
				used[graph[start][i]] = false;
			}
		}
	}
public:
	std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
		std::vector<bool> used(graph.size(), false);
		std::vector<std::vector<int>> ans;
		std::vector<int> way;
		DFS(graph, used, 0, way, ans);
		return ans;
	}
};