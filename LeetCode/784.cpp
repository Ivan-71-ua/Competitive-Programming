
#include <bits/stdc++.h>

class Solution {
	std::set<std::string> ans;
	void permut(std::string &s, int idx) {
		if(idx == s.size())
			return;
		if(isdigit(s[idx])) {
			permut(s, idx + 1);
			return;
		}
			
	
		ans.insert(s);
		permut(s, idx + 1);
		if('a' <= s[idx] && 'z' >= s[idx]) {
			s[idx] = 'A' + (s[idx] - 'a');
		}	else {
			s[idx] = 'a' + (s[idx] - 'A');
		}
		ans.insert(s);
		permut(s, idx + 1);
		if('a' <= s[idx] && 'z' >= s[idx]) {
			s[idx] = 'A' + (s[idx] - 'a');
		}	else {
			s[idx] = 'a' + (s[idx] - 'A');
		}
	}
public:
	std::vector<std::string> letterCasePermutation(std::string s) {
		permut(s, 0);
		if (ans.empty()) {
			return {s};
		}
		return {ans.begin(), ans.end()};
	}
};

int main() {
	Solution ans;
	ans.letterCasePermutation("a1b2");
}