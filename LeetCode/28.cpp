#include <bits/stdc++.h>

class Solution {
public:
   int strStr(std::string haystack, std::string needle) {
		if(haystack.size() < needle.size())
			return -1;
		return haystack.find(needle);
		
	}
};