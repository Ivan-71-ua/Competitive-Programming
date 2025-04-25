#include <bits/stdc++.h>




class Solution {
public:
	vector<int> arrayRankTransform(vector<int>& arr) {
		int n = arr.size();
		std::map<int, int> rank;
		for (auto& num : arr)
		{
			rank[num]++;
		}
		int cnt = 1;
		for (auto& now : rank)
		{
			now.second = cnt++;
		}
		std::vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] =  rank[arr[i]];
		}
		return ans;
	}
	
};