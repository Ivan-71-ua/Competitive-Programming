#include <bits/stdc++.h>


class Solution {
public:
	int scoreOfString(std::string s) {
		int res = 0;
		for (int i = 1; i < s.size(); i++)
		{
			res += abs(s[i - 1] - s[i]);
		}
		return res;
	}
};


int main() {
	Solution ans;
	std::cout << ans.scoreOfString("hello");
}