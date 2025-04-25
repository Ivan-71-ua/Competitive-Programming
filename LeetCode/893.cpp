#include <bits/stdc++.h>


class Solution {
public:
	int numSpecialEquivGroups(std::vector<std::string>& words) {
		std::map<int, std::vector<int>> group_to_set;
		std::vector<std::vector<std::string>> group;
		for (auto word: words)
		{
			std::vector<int> f(26);
			std::vector<int> s(26);
			for (int i = 0; i < word.size(); i++)
			{
				if(i & 1) {
					s[word[i] - 'a']++;
				} else {
					f[word[i] - 'a']++;
				}
			}
			bool find = false;
			for (auto &gr: group)
			{
				if(find) break;
				std::vector<int> f_c(26);
				std::vector<int> s_c(26);
				for (int i = 0; i < gr[0].size(); i++)
				{
					if(i & 1) {
						s_c[gr[0][i] - 'a']++;
					} else {
						f_c[gr[0][i] - 'a']++;
					}
				}
				if(f_c == f && s_c == s) {
					gr.push_back(word);
					find = true;
				}
			}
			if(!find) {
				group.push_back({word});
				
			}
		}
		return group.size();
	}
};
