#include <bits/stdc++.h>


class Solution {
	void reverse(int i, int j, std::string &st) {
		while(i < j) {
			std::swap(st[i], st[j]);
			i++;
			j--;
		}
	}
public:
	std::string smallestNumber(std::string pattern) {
		std::string res;
		for (int i = 1; i <= pattern.size() + 1; i++)
		{
			res += '0' + i;
		}
		for (int i = 0; i < pattern.size(); i++)
		{
			int tmp = i;
			while(tmp < pattern.size() && pattern[tmp] == 'D') {
				tmp++;
			}
			reverse(i, tmp, res);
			if(tmp != i) {
				i = tmp - 1;
			}
		}
		return res;
	}
};