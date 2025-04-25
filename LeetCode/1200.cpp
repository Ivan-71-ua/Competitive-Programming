#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
		std::stable_sort(arr.begin(), arr.end());
		int delta = INT16_MAX;
		for (int i = 1; i < arr.size(); i++)
		{
			delta = std::min(abs(arr[i] - arr[i - 1]), delta);
		}
		std::vector<std::vector<int>> ans;
		for (int i = 1; i < arr.size(); i++)
		{
			if(abs(arr[i] - arr[i - 1]) == delta) {
				int a = std::min(arr[i], arr[i - 1]);
				int b = std::max(arr[i], arr[i - 1]);
				ans.push_back({a, b});
			}
		}
		return ans;
	}
};