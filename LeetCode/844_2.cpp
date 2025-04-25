#include <bits/stdc++.h>

class Solution {
public:
	bool backspaceCompare(std::string s, std::string t) {		
		int l1 = s.size() - 1;
		int l2 = t.size() - 1;
		while (true) {
			int balance = 0;
			while(true) {
				if(l1 < 0) {
					break;
				}
				if(s[l1] == '#') {
					balance--;
				} else {
					balance++;
				}
				if(balance > 0) {
					break;
				}
				l1--;
			}
			balance = 0;
			while(true) {
				if(l2 < 0) {
					break;
				}
				if(t[l2] == '#') {
					balance--;
				} else {
					balance++;
				}
				if(balance > 0) {
					break;
				}
				l2--;
			}
			if(l1 < 0 && l2 < 0) {
				return true;
			}
			if(l1 < 0 || l2 < 0 || s[l1] != t[l2]) {
				return false;
			}
			l1--;
			l2--;
		}
		return false;
	}
};

int main() {
	Solution ans;
	ans.backspaceCompare("bxj##tw", "bxo#j##tw");
}