#include <bits/stdc++.h>

class Solution {
public:
   bool hasAllCodes(std::string s, int k) {
		std::set<std::string> varois {};
		if(s.size() < k)
			return false;
		for (int i = 0; i <= s.size() - k; i++)
		{
			std::string tp = s.substr(i, k);
			varois.insert(tp);
		}
		return varois.size() == 2 << k;
	}
};

int main() {
	Solution ans;
	ans.hasAllCodes("0", 20);
}