#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> partitionLabels(std::string s) {
		std::vector<int> max_dis(26);
		for (int i = 0; i < s.size(); i++)
		{
			max_dis[s[i] - 'a'] = i;
		}
		int prev = 0;
		int length = 0;
		std::vector<int> ans;
		for (int i = 0; i < s.size(); i++)
		{
			length = std::max(length, max_dis[s[i] - 'a']);
			if(i == length) {
				ans.push_back(i - prev + 1);
				prev = i + 1;
			} 
		}
		return ans;
	}
};