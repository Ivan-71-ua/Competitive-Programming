#include <bits/stdc++.h>


class Solution {
public:
	std::string robotWithString(std::string s) {
		std::string res;
		std::vector<int> cnt(26, 0);
		std::stack<int> st;
		int minChar = 0;
		for(char c : s) {
			cnt[c - 'a']++;
		}
		for(char c : s) {
			st.push(c - 'a');
			cnt[c - 'a']--;
			while(minChar != 26 && cnt[minChar] == 0) {
				minChar++;
			}
			while(!st.empty() && st.top() <= minChar) {
				res.push_back(st.top() + 'a');
				st.pop();
			}
		}
		return res;

	}
};