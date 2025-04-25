#include <bits/stdc++.h>


class Solution {
public:
	std::string sortVowels(std::string s) {
		std::vector<char> volve;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' || s[i] == 'A' || s[i] == 'u' || s[i] == 'U' || 
			s[i] == 'o' || s[i] == 'O' || s[i] == 'I' || s[i] == 'i' || s[i] == 'e' || s[i] == 'E') {
				volve.push_back(s[i]);
			}
		}
		std::stable_sort(volve.begin(), volve.end());
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' || s[i] == 'A' || s[i] == 'u' || s[i] == 'U' || 
			s[i] == 'o' || s[i] == 'O' || s[i] == 'I' || s[i] == 'i' || s[i] == 'e' || s[i] == 'E') {
				s[i] = volve[k];
				k++;
			}
		}
		return s;
	}
};