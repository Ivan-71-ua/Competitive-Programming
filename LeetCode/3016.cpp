#include <bits/stdc++.h>



class Solution {
public:
	int minimumPushes(std::string word) {
		std::vector<int> alph(26);
		for (auto ch: word)
		{
			alph[ch - 'a']++;
		}
		std::stable_sort(alph.begin(), alph.end(), std::greater());
		int ans = 0;
		int k = 0;
		for (auto now: alph)
		{
			if(k / 8 == 0) {
				ans += now;
			} else if(k / 8 == 1) {
				ans += now * 2;
			} else if( k / 8 == 2) {
				ans += now * 3;
			} else if(k / 8 == 3) {
				ans += now * 4;
			}
			k++;
		}
		return ans;
	}
};