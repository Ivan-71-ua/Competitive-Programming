
#include <bits/stdc++.h>



class Solution {
	std::vector<int> give_alph(std::string s) {
		std::vector<int> alph(26);
		for(auto &v: s) {
			alph[v - 'a']++;
		}
		return alph;
	}
public:
	std::vector<std::string> wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2) {
		std::vector<int> sets(26);
		for(auto &s: words2) {
			std::vector<int> cur(26);
			for(auto &ch : s) {
				cur[ch - 'a']++;
			}
			for (int i = 0; i < 26; i++) {
				sets[i] = std::max(sets[i], cur[i]);
			}
		}
		std::vector<std::string> ans;
		for(auto &s: words1) {
			std::vector<int> cur = give_alph(s);
			int flag = 0;
			for (int i = 0; i < 26; i++) {
				if(flag) break;
				if(sets[i] > cur[i])
					flag = 1;
			}
			if(!flag) {
				ans.push_back(s);
			}
		}
		return ans;
	}
};