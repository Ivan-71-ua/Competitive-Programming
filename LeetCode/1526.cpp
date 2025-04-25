#include <bits/stdc++.h>


class Solution {
public:
	int minNumberOperations(std::vector<int>& target) {
		int ans = 0;
		int cur_val = 0;
		for (int i = 0; i < target.size(); i++)
		{
			if(target[i] > cur_val) {
				ans += target[i] - cur_val;
			}
			cur_val = target[i];
		}
		return ans;
	}
};