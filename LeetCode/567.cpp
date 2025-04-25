
#include <bits/stdc++.h>

void zeros(std::vector<int> &arr) {
	for(auto &ch: arr)
		ch = 0;
}

class Solution {
public:
	bool checkInclusion(std::string s1, std::string s2) {
		std::vector<int> alph(26);
		std::vector<int> need(26);
		for (auto &ch : s1)
		{
			need[ch - 'a']++;
		}
		int st = 0;
		for (int i = 0; i < s2.size(); i++)
		{
		alph[s2[i] - 'a']++;
		if(i - st + 1 > s1.size()) {
			alph[s2[st] - 'a']--;
			st++;
		}
		bool check = true;
		for (int i = 0; i < 26; i++)
		{
			if(need[i] != alph[i]) {
				check = false;
				break;
			} 
		}
		if(check)
			return true;
		}

		return false;
	}
};