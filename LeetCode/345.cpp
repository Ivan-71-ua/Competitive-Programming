#include <bits/stdc++.h>


class Solution {
public:
	std::string reverseVowels(std::string s) {
		std::string al = "aeiouAEIOU";
		int i = 0;
		int j = s.size() - 1;
		while(i < j) {
			if(find(al.begin(), al.end(), s[i]) == al.end())
				i++;
			if(find(al.begin(), al.end(), s[j]) == al.end())
			j--;
			if(find(al.begin(), al.end(), s[i]) != al.end() && find(al.begin(), al.end(), s[j]) != al.end()) {
				std::swap(s[i], s[j]);
				i++;
				j--;
			}
		}
		return s;
	}
};