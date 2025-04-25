#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> numberOfLines(std::vector<int>& widths, std::string s) {
		int row = 0;
		int sum = 0;
		for (int i = 0; i <s.size(); i++)
		{
			if(sum + widths[s[i] - 'a'] <= 100) {
				sum += widths[s[i] - 'a'];
			} else {
				sum = widths[s[i] - 'a'];
				row++;
			}
		}
		return {row + 1, sum};
	}
};