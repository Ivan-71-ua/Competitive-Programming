#include <bits/stdc++.h>




class Solution {
public:
	std::string compressedString(std::string word) {
		word += '#';
		std::string st;
		char cur_ch = '#';
		int cunt = 0;
		for (auto &ch: word)
		{
			if(cur_ch != ch) {
				if(cunt) {
					st += ('0' + cunt);
					st += cur_ch;
					
				}
				cur_ch = ch;
				cunt = 1;
			} else {
				if(cunt == 9) {
					st += '9';
					st += cur_ch;
					cunt = 0;
				} else {
					cunt++;
				}
			}
		}
		return st;
	}
};