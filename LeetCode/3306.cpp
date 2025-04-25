#include <bits/stdc++.h>







class Solution {
long long atLeastK(std::string s, int k) {
	std::unordered_map<char, int> volw;
	int another = 0;
	int l = 0;
	long long res = 0;
	
	for (int r = 0; r < s.size(); r++) {
		if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
			volw[s[r]]++;
		} else {
			another++;
		}
		
		while (volw.size() == 5 && another >= k) {
			res += s.size() - r;  
			
			if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
					volw[s[l]]--;
					if (volw[s[l]] == 0) {
						volw.erase(s[l]); 
					}
			} else {
					another--;
			}
			l++;  
		}
	}
	return res;
}

public:
long long countOfSubstrings(std::string word, int k) {
	return atLeastK(word, k) - atLeastK(word, k + 1);
}
};
