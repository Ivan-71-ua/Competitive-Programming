#include <bits/stdc++.h>

class Solution {
public:
	char nextGreatestLetter(std::vector<char>& letters, char target) {
		if(std::upper_bound(letters.begin(), letters.end(), target) != letters.end()) {
			return *std::upper_bound(letters.begin(), letters.end(), target);
		} else {
			return *letters.begin();
		}
	}
};