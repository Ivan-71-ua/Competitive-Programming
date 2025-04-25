#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
		std::vector<int> pref(arr.size() + 1);
		for (int i = 0; i < arr.size(); i++)
		{
			pref[i + 1] = pref[i] ^ arr[i];
		}
		std::vector<int> ans;
		for (int i = 0; i < queries.size(); i++)
		{
			ans.push_back(pref[queries[i][1] + 1] ^ pref[queries[i][0]]);
		}
		return ans;
	}
};