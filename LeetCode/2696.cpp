#include <bits/stdc++.h>


	class Solution {
	public:
		int minLength(std::string s) {
			std::vector<char> ctack = {'#'};
			for (auto ch: s)
			{
				if(ch == 'B' && ctack.back() == 'A') {
					ctack.pop_back();
				} else if(ch == 'D' && ctack.back() == 'C') {
					ctack.pop_back();
				} else {
					ctack.push_back(ch);
				}
			}
			return ctack.size() - 1;
		}
	};