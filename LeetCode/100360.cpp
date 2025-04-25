#include <bits/stdc++.h>

class Solution {
public:
	int maxOperations(std::string s) {
		int count = 0;
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] == '1')
				count++;
			if(s[i] == '1' && s[i +1] == '0')
				res += count;
		}
		return res;
	}
};