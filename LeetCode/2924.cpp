#include <bits/stdc++.h>


class Solution {
public:
	int findChampion(int n, std::vector<std::vector<int>>& edges) {
		std::set<int> num;
		for (int i = 0; i < n; i++) {
			num.insert(i);
		}
		for (int i = 0; i < edges.size(); i++)
		{
			num.erase(edges[i][1]);
		}
		if(num.size() > 1)
			return -1;
		return *num.begin();
	}
};