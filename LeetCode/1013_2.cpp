#include <bits/stdc++.h>

class Solution {
public:
	bool canThreePartsEqualSum(std::vector<int>& arr) {
		int sum = 0;
		sum = std::accumulate(arr.begin(), arr.end(), 0);
		if(sum % 3 != 0)
			return false;
		sum /= 3;
		int cur_s = 0;
		bool first = false, second = false, third = false;
		for (int i = 0; i < arr.size(); i++)
		{
			cur_s += arr[i];
			if(cur_s == sum && !first) {
				first = true;
			} else if(cur_s == sum * 2 && first && !second) {
				second = true;
			} else if(cur_s == sum * 3 && first && second && !third) {
				third = true;
			}
		}
		return first && second && third;
	}
};