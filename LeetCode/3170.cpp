#include <bits/stdc++.h>



class Solution {
public:
	std::string clearStars(std::string s) {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);      
      std::cout.tie(nullptr);
		std::vector<std::stack<int>> stacks(26);
		std::string res;
		for (int i = 0; i < s.size(); i++) {
			if(s[i] == '*') {
				for (int i = 0; i < 26; i++) {
					if(!stacks[i].empty()) {
						s[stacks[i].top()] = '*';
						stacks[i].pop();
                        break;
					}
				}
			} else {
				stacks[s[i] - 'a'].push(i);
			}
		}
		for (int i = 0; i < s.size(); i++) {
			if(s[i] != '*') {
				res += s[i];
			}
		}
		return res;
	}
};