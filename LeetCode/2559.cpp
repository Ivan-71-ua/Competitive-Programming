#include <bits/stdc++.h>




class Solution {
	int is(std::string s) {
		if((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' ||s[0] == 'u' ||s[0] == 'o') && 
		(s.back() == 'a' || s.back() == 'e' || s.back() == 'i' || s.back() == 'u' || s.back() == 'o') ) {
			return 1;
		}
		return 0;
	}
public:
	std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {
		int n = words.size();
		std::vector<int> pref(n, 0);
		pref[0] = is(words[0]);
		for (int i = 1; i < n; i++) {
			pref[i] = pref[i - 1] + is(words[i]);
		}
		std::vector<int> res(queries.size());
		for (int i = 0; i < queries.size(); i++)
		{
			int a = queries[i][0], b = queries[i][1];
			int k = pref[b] - (a > 0 ? pref[a - 1] : 0);
			res[i] = k;
		}
		return res;
	}
};