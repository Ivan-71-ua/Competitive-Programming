#include <bits/stdc++.h>


class Solution {
	std::vector<std::vector<int>> list_edg;
	std::vector<std::set<int>> list_of_group; //суміжності
	std::map<int, int> el_to_group;
	std::map<int, std::vector<int>> group_elements;
	std::vector<int> used;
	std::vector<int> topo_el;
	std::vector<int> topo_grop;
	void dfs(int i, int &flag) {
		used[i] = 1;
		for (auto next: list_edg[i])
		{
			if(used[next] == 0)
			{
				dfs(next, flag);
			} 	else if(used[next] == 1) {
				flag = 1;
				return;
			}
		}
		topo_el.push_back(i);
		used[i] = 2;
	}
	bool topo_sort(int n) {
		used.resize(n);
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if(flag == 1) 
				break;
			if(used[i] == 0) {
				dfs(i, flag);
			}
		}
		if(flag == 1)
			return false;
		std::reverse(topo_el.begin(), topo_el.end());
		return true;
	}
	void dfs2(int i, int &flag) {
		used[i] = 1;
		for (auto next: list_of_group[i])
		{
			if(used[next] == 0)
			{
				dfs(next, flag);
			} 	else if(used[next] == 1) {
				flag = 1;
				return;
			}
		}
		topo_grop.push_back(i);
		used[i] = 2;
	}
	bool topo_sort2(int n) {
		int m = list_of_group.size();
		used.resize(m);
		int flag = 0;
		for (int i = 0; i < m; i++)
		{
			if(flag == 1) 
				break;
			if(used[i] == 0) {
				dfs(i, flag);
			}
		}
		if(flag == 1)
			return false;
		std::reverse(topo_grop.begin(), topo_grop.end());
		return true;
	}
public:
	std::vector<int> sortItems(int n, int m, std::vector<int>& group, std::vector<std::vector<int>>& beforeItems) {
		std::vector<int> ans;
		list_edg.resize(n);
		list_of_group.resize(m);
		for (int i = 0; i < beforeItems.size(); i++)
		{
			if(group[i] == -1) {
				list_of_group.push_back({});
				el_to_group[i] = list_of_group.size() - 1;
			} else {
				el_to_group[i] = group[i];
			}
		}
		for (int i = 0; i < beforeItems.size(); i++)
		{
			for (auto bef: beforeItems[i])
			{
				list_edg[i].push_back(bef);
				if(el_to_group[i] != el_to_group[bef]) {
					list_of_group[el_to_group[i]].insert(el_to_group[bef]);
				}
			}
		}
		if(!topo_sort(n)) {
			return {};
		} 
		if(!topo_sort2(n)) {
			return {};
		}  
		for (int i = 0; i < topo_el.size(); i++)
		{
			group_elements[el_to_group[topo_el[i]]].push_back(topo_el[i]);
		}
		for (int i = 0; i < topo_grop.size(); i++)
		{
			for (auto el: group_elements[topo_grop[i]])
			{
				ans.push_back(el);
			}
		}
		return ans;
	}
};