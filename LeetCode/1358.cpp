
#include <bits/stdc++.h>





class Solution {
	public:
		int numberOfSubstrings(std::string s) {
			int res = 0;
			int a = 0, b = 0, c = 0;
			int j = 0;
			for (int i = 0; i < s.size(); i++) {
				if(s[i] == 'a') {
					a++;
				} else if(s[i] == 'b') {
					b++;
				} else {
					c++;
				}
				while(a * b * c > 0) {
					res += s.size() - i;
					if(s[j] == 'a') {
						a--;
					} else if(s[j] == 'b') {
						b--;
					} else {
						c--;
					}
					j++;
				}
			}
			return res;
		}
	};