
#include <bits/stdc++.h>


class Solution {
public:
	int minimumDeletions(std::string word, int k) {
		std::vector<int> cnt(26, 0);
		int ans = INT32_MAX;
		for(char c : word) {
			cnt[c - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] == 0) continue;
			int cur_remove = 0;
			for (int j = 0; j < 26; j++) {
				if(cnt[j] == 0 || i == j) continue;
				if(cnt[i] > cnt[j]) {
					cur_remove += cnt[j];
				} else {
					cur_remove += std::max(0, cnt[j] - k - cnt[i]);
				}
			}
			ans = std::min(ans, cur_remove);
		}
		return ans;
	}
};