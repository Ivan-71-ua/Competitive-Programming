#include <bits/stdc++.h>


class Solution {
public:
	std::string gcdOfStrings(std::string str1, std::string str2) {
		if(str2.size() > str1.size())
			std::swap(str1, str2);
		std::string ans;
		std::string sub;
		for (int p = 0; p < str2.size(); p++)
		{
			sub += str2[p];
			bool can = true;
			if(str1.size() % sub.size() != 0 || str2.size() % sub.size() != 0)
				can = false;
			else {
				for (int i = 0; i < str1.size(); i += sub.size())
				{
					if(!can)
						break;
					for (int j = 0; j < sub.size(); j++)
					{
						if(str1[i + j] != sub[j]) {
							can = false;
							break;
						}
					}
				}
				for (int i = 0; i < str2.size(); i += sub.size())
				{
					if(!can)
						break;
					for (int j = 0; j < sub.size(); j++)
					{
						if(str2[i + j] != sub[j]) {
							can = false;
							break;
						}
					}
				}
			}
			if(can) {
				if(ans.size() < sub.size())
					ans = sub;
			}
		}
		return ans;
	}
};