#include <bits/stdc++.h>



class Solution {
public:
	int trap(std::vector<int>& height) {
		int n = height.size();
		int res = 0;
		int l = 0, r = n - 1;
		int ml = height[l], mr = height[r];
		while(l < r) {
			if(ml < mr) {
				l++;
				ml = std::max(ml, height[l]);
				res += ml - height[l];
			} else {
				r--;
				mr = std::max(mr, height[r]);
				res += mr - height[r];
			}
		}
		return res;
	}
};