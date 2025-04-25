#include <bits/stdc++.h>



class Solution {
public:
	int heightChecker(std::vector<int>& heights) {
		std::vector<int> sorted(heights);
		std::stable_sort(sorted.begin(), sorted.end());
		int ans = 0;
		for (int i = 0; i < sorted.size(); i++)
		{
			if(heights[i] != sorted[i])
				ans++;
		}
		return ans;
	}
};