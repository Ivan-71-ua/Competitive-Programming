#include <bits/stdc++.h>

class Solution {
public:
	std::string licenseKeyFormatting(std::string S, int K) {
		std::string res;
		for (auto i = S.rbegin(); i < S.rend(); i++)
		if (*i != '-') { // ignore '-' in original string
			if (res.size()%(K+1) == K) res += '-'; // every (K+1)th char is '-' from tail
			res += toupper(*i);
		}
		
		reverse(res.begin(), res.end());
		return res;
	}
};

int main() {
	Solution ans;
	ans.licenseKeyFormatting("5F3Z-2e-9-w", 4);
}