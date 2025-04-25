#include <bits/stdc++.h>

class Solution {
public:
   void reverseString(std::vector<char>& s) {
		int r = 0, l = s.size() - 1;
		while(r < l) {
			std::swap(s[r], s[l]);
			r++;
			l--;
		}
	}
};