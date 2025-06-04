#include <bits/stdc++.h>


class Solution {
	std::string lastSub(std::string s) {
		int i = 0, j = 1, n = s.size();
		while(j < n) {
			int k = 0;
			while(j + k < n && s[i + k] == s[j + k]) {
				k++;
			}
			if(j + k < n && s[i + k] < s[j + k]) {
				int tmp = i;
				i = j;
				j = tmp + k + 1;
			} else {
				j += k + 1;
			}
		}
		return s.substr(0, n - i);
	}
public:
	std::string answerString(std::string word, int numFriends) {
		if(numFriends == 1) {
			return word;
		}
		
		std::string last = lastSub(word);
		int n = word.size(), m = last.size(), max_s = n - numFriends + 1;
		return last.substr(0, std::min(m, max_s));
	}
};