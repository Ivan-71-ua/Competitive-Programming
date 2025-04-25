#include <bits/stdc++.h>



class Solution {
public:
	std::string reverseOnlyLetters(std::string s) {
		int i = 0;
		int j = s.size() - 1;
		while(i < j) {
			if(isalpha(s[i]) && isalpha(s[j])) {
				std::swap(s[i], s[j]);
				i++;
				j--;
			}
			if(!isalpha(s[i]))
				i++;
			if(!isalpha(s[j]))
				j--;
		}
		return s;
	}
};