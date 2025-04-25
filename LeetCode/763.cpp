#include <bits/stdc++.h>


class Solution {
	int LastIndex(std::string &s, char find) {
		int res = -1;
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] == find)
				res = i;
		}
		return res;
	}
public:
	std::vector<int> partitionLabels(std::string s) {
		if(LastIndex(s, s[0]) == s.size())
			return {(int)s.size()};
		std::vector<int> ans;
		int prev = 0;
		int max_dis = LastIndex(s, s[0]);
		std::set<int> used;
		int id = 0;
		while(id < s.size()) {
			if(id == max_dis) {
				id++;
				ans.push_back(id - prev);
				prev = id;
				max_dis = LastIndex(s, s[id]);
				used.clear();
				used.insert(s[id]);
			} else {
				if(!used.count(s[id])) {
					used.insert(s[id]);
					max_dis = std::max(max_dis, LastIndex(s, s[id]));
				}
				id++;
			}
		}
		return ans;
	}
};