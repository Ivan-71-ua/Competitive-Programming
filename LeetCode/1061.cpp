#include <bits/stdc++.h>



class Solution {
	int min_value(std::vector<std::vector<int>> vertex, int st) {
		int min = st;
		std::vector<bool> used(26);
		std::stack<int> way;
		way.push(st);
		while(!way.empty()) {
			int cur = way.top();
			min = std::min(min, cur);
			way.pop();
			if(!used[cur]) {
				used[cur] = true;
				for (int i = 0; i < vertex[cur].size(); i++)
				{
					way.push(vertex[cur][i]);
				}
			}
		}
		return min;
	}
public:
   std::string smallestEquivalentString(std::string s1, std::string s2, std::string baseStr) {
		std::vector<std::vector<int>> vertex(26);
		for (int i = 0; i < s1.size(); i++)
		{
			vertex[s1[i] - 'a'].push_back(s2[i] - 'a');
			vertex[s2[i] - 'a'].push_back(s1[i] - 'a');
		}
		std::vector<int> minimum(26);
		for (int i = 0; i < 26; i++)
		{
			int cur = min_value(vertex, i);
			minimum[i] = cur;
		}
		for (int i = 0; i < baseStr.size(); i++)
		{
			baseStr[i] = 'a' + minimum[baseStr[i] - 'a'];
		}
		return baseStr;
	}
};