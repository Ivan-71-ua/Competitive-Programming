#include <bits/stdc++.h>





	class Solution {
	public:
		std::vector<int> singleNumber(std::vector<int>& nums) {
			int xors = 0;
			for (auto &&v : nums)
			{
				xors ^= v;
			}
			int d = 1;
			while(!(d & xors)) {
				d = d << 1;
			}
			int fist = 0;
			int second = 0;
			for(auto &&v : nums) {
				if(d & v) {
					fist ^= v;
				} else {
					second ^= v;
				}
			}
			return {fist, second};
		}
	};