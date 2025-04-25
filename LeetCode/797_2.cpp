#include <bits/stdc++.h>



class Solution {
	void DFS(std::vector<std::vector<int>> &graph, int start, 
	std::vector<int> &way, std::vector<std::vector<int>> &ans) {
		way.push_back(start);
		if(start == graph.size() - 1) {
			ans.push_back(way);
		} else {
			for (int i = 0; i < graph[start].size(); i++)
			{
				DFS(graph, graph[start][i], way, ans);
			}
		}
      way.pop_back();
	}
public:
	std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
		std::vector<std::vector<int>> ans;
		std::vector<int> way;
		DFS(graph, 0, way, ans);
		return ans;
	}
};