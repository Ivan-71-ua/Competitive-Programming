
#include <bits/stdc++.h>

class Solution {
public:
	int minChanges(std::string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i+= 2)
		{
			if(s[i] != s[i +1])
				res++;
		}
		return res;
	}
};