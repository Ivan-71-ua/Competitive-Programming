#include <bits/stdc++.h>

class Solution {
public:
	int minAnagramLength(std::string s) {
		int maxCnt = s.size();
		std::vector<int> cnt(26, 0);
		for(char& c : s) {
				maxCnt = std::max(maxCnt, ++cnt[c - 'a']);
		}
		for(int i = 0; i < 26; ++i) {
				if(cnt[i] == 0)
					continue;
				maxCnt = std::gcd(maxCnt, cnt[i]);
		}
		return s.size() / maxCnt;
	}
};

int main() {
	Solution ans;
	ans.minAnagramLength("abba");
}

/*
	"xxe"
	3
*/