
#include <bits/stdc++.h>



class Solution {
public:
	bool canMakeSubsequence(std::string str1, std::string str2) {
		int n = str1.size(), m = str2.size();
		int j = 0;
		for (int i = 0; i < n && j < m; i++)
		{
			char next = 'a' + ((str1[i] - 'a') + 1) % 26;
			if(str1[i] == str2[j] || next == str2[j]) {
				j++;
			} 
		}
		if(j >= m)
			return true;
		return false;
	}
};