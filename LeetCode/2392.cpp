#include <bits/stdc++.h>


class Solution {
	bool curle(std::vector<std::vector<int>> &graf) {
		std::vector<int> used(graf.size());
		bool is = false;
		for (int i = 1; i < graf.size(); i++)
		{
			if(used[i] == 0) {
				dfs(i, graf, used, is);
				if (is)
				{
					return true;
				}
			}
		}
		return false;
	}
	void dfs(int v, std::vector<std::vector<int>> &graf, std::vector<int> &used, bool &is) {
		if(is)
			return;
		used[v] = 1;
		for (auto next: graf[v])
		{
			if(used[next] == 1) {
				is = true;
				return;
			} else {
				dfs(next, graf, used, is);
			}
		}
		used[v] = 2;
	}
	void help_topo(int v, std::vector<std::vector<int>> &graf, std::vector<bool> &used, std::vector<int> &ans) {
		used[v] = true;
		for (auto next: graf[v])
		{
			if(!used[next]) {
				help_topo(next, graf, used, ans);
			}
		}
		ans.push_back(v);
	}
	std::vector<int> topo_sort(std::vector<std::vector<int>> &graf) {
		std::vector<int> ans;
		std::vector<bool> used(graf.size());
		ans.reserve(graf.size());
		for (int i = 1; i < graf.size(); i++)
		{
			if(!used[i]) {
				help_topo(i, graf, used, ans);
			}
		}
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
public:
	std::vector<std::vector<int>> buildMatrix(int k, std::vector<std::vector<int>>& rowConditions, std::vector<std::vector<int>>& colConditions) {
		std::vector<std::vector<int>> graf_r(k + 1);
		std::vector<std::vector<int>> graf_c(k + 1);
		//std::vector<bool> used(k + 1);
		for (int i = 0; i < rowConditions.size(); i++)
		{
			graf_r[rowConditions[i][0]].push_back(rowConditions[i][1]);
		}
		for (int i = 0; i < colConditions.size(); i++)
		{
			graf_c[colConditions[i][0]].push_back(colConditions[i][1]);
		}
		if(curle(graf_c) || curle(graf_r)) {
			return {};
		}
		std::vector<int> row = topo_sort(graf_r);
		std::vector<int> col = topo_sort(graf_c);
		std::vector<std::vector<int>> ans(k, std::vector<int>(k, 0));
		std::map<int, std::pair<int, int>> ver_cord;
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
	std::vector<std::vector<int>> r = {{1, 2}, {3, 2}};
	std::vector<std::vector<int>> c = {{2,1}, {3,2}};
	ans.buildMatrix(3, r, c);
}