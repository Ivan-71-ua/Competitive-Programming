#include <bits/stdc++.h>


class Solution {
	bool help_topo(int v, std::vector<std::vector<int>> &graf, std::vector<bool> &used, std::set<int> &visited, std::vector<int> &ans) {
		if(visited.count(v))
			return false;
		if(used[v])
			return true;
		used[v] = true;
		visited.insert(v);
		for (auto next: graf[v])
		{
			if(!help_topo(next, graf, used, visited, ans)) {
				return false;
			}
		}
		visited.erase(v);
		ans.push_back(v);
		return true;
	}
	std::vector<int> topo_sort(std::vector<std::vector<int>> &graf) {
		std::vector<int> ans;
		std::vector<bool> used(graf.size());
		std::set<int> visited;
		ans.reserve(graf.size());
		for (int i = 1; i < graf.size(); i++)
		{
			if(!help_topo(i, graf, used, visited, ans)) {
				return {};
			}
		}
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
public:
	std::vector<std::vector<int>> buildMatrix(int k, std::vector<std::vector<int>>& rowConditions, std::vector<std::vector<int>>& colConditions) {
		std::vector<std::vector<int>> graf(k + 1);
		for (int i = 0; i < rowConditions.size(); i++)
		{
			graf[rowConditions[i][0]].push_back(rowConditions[i][1]);
		}
		std::vector<int> row = topo_sort(graf);
		graf.clear();
		graf.resize(k + 1);
		for (int i = 0; i < colConditions.size(); i++)
		{
			graf[colConditions[i][0]].push_back(colConditions[i][1]);
		}
		std::vector<int> col = topo_sort(graf);
		if(col.empty() || row.empty()) {
			return {};
		}
		std::vector<std::vector<int>> ans(k, std::vector<int>(k, 0));
		std::unordered_map<int, std::pair<int, int>> ver_cord;
		for (int i = 0; i < row.size(); i++)
		{
			ver_cord[row[i]].first = i;
			ver_cord[col[i]].second = i;
		}
		for (int i = 1; i <= k; i++)
		{
			auto [x, y] = ver_cord[i];
			ans[x][y] = i;
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<int>> r = {{1,2}, {2,3}, {3,1}, {2,3}};
	std::vector<std::vector<int>> c = {{2,1}, {3,2}};
	ans.buildMatrix(3, r, c);
}