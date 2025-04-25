#include <bits/stdc++.h>







class Solution {
public:
	bool areAlmostEqual(std::string s1, std::string s2) {
		if(s1 == s2)
			return true;
		int f = -1, s = -1;
		int cnt = 0;
		for (int i = 0; i < s1.size(); i++) {
			if(s1[i] != s2[i] && cnt == 0) {
				f = i;
				cnt++;
			} else if(s1[i] != s2[i] && cnt == 1) {
				s = i;
				cnt++;
			} else if(s1[i]!= s2[i]){
				cnt++;
			}
		}
		if(cnt > 2 || cnt == 1)
			return false;
		std::swap(s2[f], s2[s]);
		return s1 == s2;
	}
};