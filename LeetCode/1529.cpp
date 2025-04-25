#include <bits/stdc++.h>


class Solution {
public:
	int minFlips(std::string target) {
		int ans = 0;
		char now = '0';
		for (int i = 0; i < target.size(); i++)
		{
			if(target[i] != now) {
				now = now == '0' ? '1': '0';
				ans++;
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::string s = "10111";
	ans.minFlips(s);
}