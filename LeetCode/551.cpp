#include <bits/stdc++.h>

class Solution {
public:
	bool checkRecord(std::string s) {
		if (std::count(s.begin(), s.end(), 'A') > 1 || s.find("LLL") != std::string::npos) {
			return false;
		}
		return true;
	}
};

int main() {
	Solution ans;
	ans.checkRecord("PPALLL");
}