#include <bits/stdc++.h>


class Solution {
public:
	int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
		int res = 0;
		int i = 0;
		int j = 0;
		std::stable_sort(g.begin(), g.end());
		std::stable_sort(s.begin(), s.end());
		while(i < g.size() && j < s.size()) {
			if(s[j] >= g[i]) {
				res++;
				i++;
				j++;
			} else {
				j++;
			}
		}
		return res;
	}
};