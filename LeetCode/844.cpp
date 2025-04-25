#include <bits/stdc++.h>

class Solution {
public:
	bool backspaceCompare(std::string s, std::string t) {		
		int l1 = s.size() - 1;
		int l2 = t.size() - 1;
		int scape1 = 0;
		int scape2 = 0;
		while (true) {
			while (l1 > -1 && s[l1] == '#') {

				while (l1 > -1 && s[l1] == '#')
				{
					l1--;
					scape1++;
				}
				while(scape1 != 0) {
					if(l1 > -1 && s[l1] == '#')
						scape1 += 2;
					l1--;
					scape1--;
				}

			}
			while(l2 > -1 && t[l2] == '#') {

				while(l2 > -1 && t[l2] == '#') {
				l2--;
				scape2++;
				}
				while(scape2 != 0) {
					if(l2 > -1 && t[l2] == '#') {
						scape2+= 2;
					}
					l2--;
					scape2--;
				}

			}
			if(l1 < 0 && l2 < 0) {
				return true;
			}
			if(l1 < 0 || l2 < 0 || s[l1]!= t[l2]) {
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