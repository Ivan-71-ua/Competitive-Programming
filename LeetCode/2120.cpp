#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> executeInstructions(int n, std::vector<int>& startPos, std::string s) {
		std::vector<int> ans;
		int st_x = startPos[0];
		int st_y = startPos[1];
		for (int i = 0; i < s.size(); i++)
		{
			int tmp = 0;
			int x = st_x;
			int y = st_y;
			for (int j = i; j < s.size(); j++) {
				if(s[j] == 'L') {
					y--;
				} else if(s[j] == 'U') {
					x--;
				} else if(s[j] == 'D') {
					x++;
				} else if(s[j] == 'R') {
					y++;
				}
				if(x < 0 || x >= n || y < 0 || y >= n) {
					break;
				} else {
					tmp++;
				}
			}
			ans.push_back(tmp);
		}
		return ans;
	}
};