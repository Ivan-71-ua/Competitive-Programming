#include <bits/stdc++.h>


class Solution {
public:
	int possibleStringCount(std::string word) {
		int n = word.size(), res = 1, cnt = 1;
		char prev = word[0];
		for (int i = 1; i < n; i++) {
			if(word[i] == prev){
				cnt++;
			} else {
				res += cnt - 1;
				prev = word[i];
				cnt = 1;
			}
		}
		res += cnt - 1;
		return res;
	}
};