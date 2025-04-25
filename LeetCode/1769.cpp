#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> minOperations(std::string boxes) {
		std::vector<int> ans(boxes.size());
		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = 0; j < ans.size(); j++)
			{
				if(i != j && boxes[j] == '1') {
					ans[i] += abs(j - i);
				}
			}
		}
		return ans;
	}
};