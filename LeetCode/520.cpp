#include <bits/stdc++.h>

class Solution {
public:
	bool detectCapitalUse(std::string word) {
		int big = 0;
		bool flag = false;
		for (int i = 0; i < word.size(); i++)
		{
			if(i == 0 && word[i] <= 'Z' && word[i] >= 'A') {
				big++;
				flag = true;
			} else {
				if(word[i] <= 'Z' && word[i] >= 'A') {
					big++;
				}
			}
		}
		if(big ==0 || big == word.size()) {
			return true;
		} else if(big == 1 && flag) {
			return true;
		} else {
			return false;
		}
	}
};