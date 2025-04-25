#include <bits/stdc++.h>


class Solution {
public:
	long long maxSpending(std::vector<std::vector<int>>& values) {
		int n = values.size();
		int m = values[0].size();
		int d = 1;
		long long res = 0;
		std::vector<int> add;
		add.reserve(n * m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				add.push_back(values[i][j]);
			}
		}
		std::stable_sort(add.begin(), add.end());
		for (auto num : add) 
		{
			res += 1LL * d++ * num;
		}
		
		return res;
	}
};

int main() {
	std::vector<std::vector<int>> ss{{8, 5, 2}, {6, 4, 1}, {9, 7, 3}};
	Solution ans;
	ans.maxSpending(ss);
}