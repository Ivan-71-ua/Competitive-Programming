#include <bits/stdc++.h>





class Solution {
public:
	std::string stringHash(std::string s, int k) {
		int n = s.size();
		std::vector<int> pref(n);
		pref[0] = s[0] - 'a';
		for (int i = 1; i < n; i++) {
			pref[i] += pref[i - 1] + (s[i] - 'a');
		}
		std::string res;
		int j = 0;
		while(j < n) {
			int next = j + k -1;
			int ch = (pref[next] - (j > 0 ? pref[j - 1] : 0)) % 26;
			res += 'a' + ch;
			j += k;
		}
		return res;
	}
};