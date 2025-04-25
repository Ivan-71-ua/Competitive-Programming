#include <bits/stdc++.h>


const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
	std::string sortVowels(std::string s) {
		std::vector<int> lover(26);
		std::vector<int> uper(26);
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'u' || s[i] == 'o') {
				lover[s[i] - 'a']++;
				s[i] = '$';
			}
			if(s[i] == 'A' || s[i] == 'I' || s[i] == 'E' || s[i] == 'U' || s[i] == 'O') {
				uper[s[i] - 'A']++;
				s[i] = '$';
			}
		}
		std::string tmp;
		for (int i = 0; i < 26; i++)
		{
			char j = 'A' + i;
			while(uper[i]) {
				tmp += j;
				uper[i]--;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			char j = 'a' + i;
			while(lover[i]) {
				tmp += j;
				lover[i]--;
			}
		}
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] == '$') {
				s[i] = tmp[k];
				k++;
			}
		}
		return s;
	}
};