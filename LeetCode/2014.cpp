#include <bits/stdc++.h>


class Solution {
public:
	std::string longestSubsequenceRepeatedK(std::string s, int k) {
		int n = s.size();
		std::string res = "";
		std::queue<std::string> q;
		q.push(res);
		while(!q.empty()) {
			std::string cur = q.front();
			q.pop();
			for (char c = 'a'; c <= 'z'; c++) {
				std::string next = cur + c;
				if(check(next, s, k)) {
					res = next;
					q.push(next);
				}
			}
		}
		return res;
	}
	bool check(std::string sub, std::string s, int k) {
		int cnt = 0, i = 0;
		for(char c : s) {
			if(c == sub[i]) {
				i++;
				if(i == sub.size()) {
					i = 0;
					cnt++;
					if(cnt == k) {
						return true;
					}
				}
			}
		}
		return false;
	}
};