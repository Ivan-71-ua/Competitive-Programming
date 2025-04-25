#include <bits/stdc++.h>


class Solution {
public:
	int countSeniors(std::vector<std::string>& details) {
		int cnt = 0;
		for (auto human: details)
		{
			if(human[11] > '6' || (human[11] == '6' && human[12] != '0')) {
				cnt++;
			}
		}
		return cnt;
	}
};