#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> maxDepthAfterSplit(std::string seq) {
		int n = seq.size();
		std::vector<int> ans(n);
		std::stack<std::pair<char, int>> way;
		int g = 0;
		for (int i = 0; i < seq.size(); i++)
		{
			if(seq[i] == '(') {
				ans[i] = i & 1;
			} else {
				ans[i] = 1 - i & 1;
			}
		}
		return ans;
	}
};