
#include <bits/stdc++.h>





class Solution {
	std::vector<std::string> res;
	void create(int n, std::string s) {
		if(s.size() == n) {
			res.push_back(s);
			return;
		}
		if(s.empty()) {
			create(n, s + '0');
			create(n, s + '1');
		} 
		else if(s.back() == '0') {
			create(n, s + '1');
		} 
		else {
			create(n, s + '0');
			create(n, s + '1');
		}
	}
public:
	std::vector<std::string> validStrings(int n) {
		create(n, "");
		return res;
	}
};