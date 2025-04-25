#include <bits/stdc++.h>

class Solution {
public:
   int numDecodings(std::string s) {
		std::vector<unsigned int> count(s.size() + 1, 0);
		count[0] = 1;
		for (int sz = 1; sz <= s.size(); sz++)
		{
			int last1 = s[sz - 1] - '0';
			if(1 <= last1 &&  last1 <= 9) {
				count[sz] += count[sz - 1];
			}
			if(sz >= 2) {
				int last2 = ((s[sz - 2] - '0') * 10 + s[sz - 1] - '0');
				if(10 <= last2 && last2 <= 26) {
					count[sz] += count[sz - 2];
				}
			}
		}
		return (int)count.back();
	}
};

int main() {
	Solution ans;
	ans.numDecodings("06");
}