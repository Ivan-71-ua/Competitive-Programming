#include <bits/stdc++.h>


	class Solution {
	public:
		bool doesAliceWin(std::string s) {
			std::map<int, int> volv;
			for (int i = 0; i < s.size(); i++)
			{
				if(s[i]== 'a' || s[i]== 'e' || s[i]== 'i' || s[i]== 'o' || s[i]== 'u') {
					volv[i]++;
				}
			}
			if(volv.size() > 0) {
				return true;
			}
			return false;
		}
	};