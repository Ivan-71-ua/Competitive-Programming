#include <bits/stdc++.h>



class Solution {
public:
	bool canArrange(vector<int>& arr, int k) {
		std::map<int, int> nums;
		for(auto num: arr){
			nums[((num % k) + k) % k]++;
		}
		if(nums[0] % 2 != 0) return false;
		if(!(k & 1)) {
			if(!(nums[k / 2] & 1))
				return false;
		}
		for (int i = 1; i < k / 2; i++)
		{
			if(nums[i] != nums[k - i])
				return false;
		}
		return true;
	}
};