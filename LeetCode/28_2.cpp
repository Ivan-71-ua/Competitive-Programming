#include <bits/stdc++.h>

class Solution {
public:
   int strStr(std::string haystack, std::string needle) {
		if(haystack.size() < needle.size())
			return -1;
		if(haystack == needle)
			return 0;
		std::string an;
		int16_t id = 0;
		for (int16_t i = 0; i <= haystack.size(); i++)
		{
			if(an.size() == needle.size()) {
				if(an == needle)
					return id;
				else {
					an.erase(an.begin());
					an.push_back(haystack[i]);
					id++;
				}
			} else {
				an.push_back(haystack[i]);
			}
		}
		return -1;
	}
};


int main() {
	Solution ans;
	ans.strStr("mississippi", "issip");
}