#include <bits/stdc++.h>



class Solution {
public:
	int maxDifference(std::string s) {
		int max_od = 0, max_ev = 1000;
		std::vector<int> cnt(26, 0);
		for(char c : s) {
			cnt[c - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if(cnt[i] == 0){ 
				continue;
			}
			if(i & 1) {
				max_od = std::max(max_od, cnt[i]);
			} else {
				max_ev = std::min(max_ev, cnt[i]);
			}
		}
		return max_od - max_ev;
	}
};