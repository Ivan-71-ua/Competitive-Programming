#include <bits/stdc++.h>




class Solution {
public:
	std::string triangleType(std::vector<int>& nums) {
		int a = nums[0], b = nums[1], c = nums[2];
		if(a + b < c || a + c < b || b + c < a) {
			return "none";
		}
		if(a == b && b == c) {
			return "equilateral";
		}
		if(a == b || a == c || b == c) {
			return "isosceles";
		}
		return "scalene";
	}
};