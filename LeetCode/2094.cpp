
#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> findEvenNumbers(std::vector<int>& digits) {
		std::vector<int> ans;
		std::vector<int> cnt(10, 0);
		for (int i = 0; i < digits.size(); i++) {
			cnt[digits[i]]++;
		}
		for (int i = 100; i < 1000; i += 2){
			int a = i / 100;
			int b = (i / 10) % 10;
			int c = i % 10;
			bool fb = true, sb = true, tb = true;
			if(cnt[a]) {
				cnt[a]--;
			} else {
				fb = false;
			}
			if(cnt[b]) {
				cnt[b]--;
			} else {
				sb = false;
			}
			if(cnt[c]) {
				cnt[c]--;
			} else {
				tb = false;
			}
			if(fb && sb && tb) {
				ans.push_back(i);
			}
			if(fb) {
				cnt[a]++;
			}
			if(sb) {
				cnt[b]++;
			}
			if(tb) {
				cnt[c]++;
			}
		}
		return ans;
	}
};