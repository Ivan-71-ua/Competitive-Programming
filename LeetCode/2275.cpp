#include <bits/stdc++.h>




class Solution {
public:
	int largestCombination(std::vector<int>& candidates) {
		long long mask = 1 << 23;
		int ans = 1;
		while(mask) {
			int tmp = 0;
			for (int i = 0; i < candidates.size(); i++)
			{
				if(mask & candidates[i]) {
					tmp++;
				}
			}
			ans = std::max(tmp, ans);
			mask >>= 1;	
		}
		return ans;
	}
};