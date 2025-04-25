#include <bits/stdc++.h>


	class Solution {
	public:
		std::vector<int> diStringMatch(std::string s) {
			std::vector<int> ans;
			ans.reserve(s.size() + 1);
			int i = 0;
			int j = s.size();
			for (int p = 0; p < s.size(); p++)
			{
				if(s[p] == 'I') {
					ans.push_back(i++);
				} else {
					ans.push_back(j--);
				}
			}
			ans.push_back(i++);
			return ans;
		}
	};