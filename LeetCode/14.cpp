#include <bits/stdc++.h>

class Solution {
public:
   std::string longestCommonPrefix(std::vector<std::string>& strs) {
		std::string str;
		int count = 0, min = 1000;
		for (int i = 0; i < strs.size(); i++)
		{
			if(strs[i].size() < min) {
				min = strs[i].size();
				str = strs[i];
			}
				
		}
		for (int i = 0; i < min; i++)
		{
			for (int j = 0; j < strs.size(); j++)
			{
				if(strs[j][i] != str[i])
					return str.substr(0, count);
			}
			count++;
		}
		return str.substr(0, count);
	}
};

int main () {
	Solution ans;
	std::vector<std::string> strs{""};
	ans.longestCommonPrefix(strs);
}