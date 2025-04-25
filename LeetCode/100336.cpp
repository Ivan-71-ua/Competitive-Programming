#include <bits/stdc++.h>



class Solution {
public:
	int numberOfAlternatingGroups(std::vector<int>& colors) {
		int n = colors.size();
		for (int i = 0; i < 2; i++)
		{
			colors.push_back(colors[i]);
		}
		int ans = 0;
		for (int i = 1; i < colors.size() - 1; i++)
		{
			if((colors[i -1] == 0 && colors[i] == 1 && colors[i +1] == 0) || (colors[i -1] == 1 && colors[i] == 0 && colors[i +1] == 1))
				ans++;
		}
		return ans;
	}
};

