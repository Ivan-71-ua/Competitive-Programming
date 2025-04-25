#include <bits/stdc++.h>

class Solution {
public:
	int getLucky(std::string s, int k) {
		std::string num;
		for (int i = 0; i < s.size(); i++)
		{
			num += std::to_string(s[i] - 'a' + 1);
		}
		for (int i = 0; i < k; i++)
		{
			int tmp = 0;
			for (int j = 0; j < num.size(); j++)
			{
				tmp += num[j] - '0';
			}
			num = std::to_string(tmp);
		}
		return std::stoi(num);
	}
};