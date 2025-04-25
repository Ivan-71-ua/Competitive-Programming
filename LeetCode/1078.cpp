#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::string> findOcurrences(std::string text, std::string first, std::string second) {
		std::vector<std::string> ans;
		std::stringstream parse(text);
		std::string fr, cd, td;
		parse >> fr;
		parse >> cd;
		while(parse >> td) {
			if(first == fr && second == cd) {
				ans.push_back(td);
			}
			fr = cd;
			cd = td;
		}
		return ans;
	}
};