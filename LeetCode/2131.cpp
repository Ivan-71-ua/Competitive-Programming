
#include <bits/stdc++.h>



class Solution {
public:
	int longestPalindrome(std::vector<std::string>& words) {
		std::vector<std::vector<int>> cnt(26, std::vector<int>(26, 0));
		int res = 0;
		for( auto& w: words){
			int a = w[0] - 'a';
			int b = w[1] - 'a';
			cnt[a][b]++;
		}
		bool odd = false;
		for (int i = 0; i < 26; i++) {
			for (int j = i; j < 26; j++) {
				if(i == j) {
					if(cnt[i][j] & 1 && !odd) {
						res += 2;
					}
					cnt[i][j] /= 2;
					res += cnt[i][j] * 4;
				} else {
					res += std::min(cnt[i][j], cnt[j][i]) * 4;
				}
			}
		}
		return res;
	}
};