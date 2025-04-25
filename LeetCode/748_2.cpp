#include <bits/stdc++.h>


class Solution {
public:
	std::string shortestCompletingWord(std::string licensePlate, std::vector<std::string>& words) {         
		std::vector<int> harsh(26, 0);
		for (auto ch : licensePlate) {
				if (isalpha(ch)) {
					++harsh[tolower(ch) - 'a'];
				}
		}
		
		std::string res="";
		for (auto& str : words) {
				std::vector<int> aksh(26, 0);
				for (auto ch : str) {
					++aksh[ch - 'a'];
				}
				
				bool complete = true;
				for (int i = 0; i < 26; ++i) {
					if (aksh[i] < harsh[i]) {
						complete = false;
						break;
					}
				}
				if (complete && (res.size()==0 || res.size()>str.size())) {
					res = str;
				}
		}
		return res;
	}
};