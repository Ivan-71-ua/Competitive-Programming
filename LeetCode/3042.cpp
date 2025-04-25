#include <bits/stdc++.h>




class Solution {
	bool isPreAndSuf(std::string s1, std::string s2) {
		int i = 0, j = s2.size() - 1, n = s1.size() - 1;
		while(i < s2.size()) {
			if(s1[i] != s2[i] && s1[n] != s2[j])
				return false;
			i++;
			j--;
			n--;
		}
		return true;
	}
public:
	int countPrefixSuffixPairs(std::vector<std::string>& words) {
		int n = words.size();
		int res = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i - 1; j > -1; j--) {
				if(words[i].size() < words[j].size()) continue;
				if(isPreAndSuf(words[i], words[j])) {
					res++;
				}
			}
		}
		return res;
	}
};