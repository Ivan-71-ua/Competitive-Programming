#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> shortestToChar(std::string s, char c) {
		std::vector<int> position;
		std::vector<int> res(s.size(), INT32_MAX);
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] == c) {
				position.push_back(i);
				res[i] = 0;
			}
		}
		while(!position.empty()) {
			int right = position.back();
			int left = position.back();
			position.pop_back();
			while(right + 1 < s.size() && res[right +1] > res[right] + 1) {
				res[right + 1] = res[right] + 1;
				right++;
			}
			while(left - 1 > -1 && res[left - 1] > res[left] + 1) {
				res[left - 1] = res[left] + 1;
				left--;
			}
		}
		return res;
	}
};