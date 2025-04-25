#include <bits/stdc++.h>

class NumArray {
public:
   NumArray(std::vector<int>& nums) {
		this->val = nums;
	}

   int sumRange(int left, int right) {
		int sum = 0;
		for (int i = left; i <= right; i++)
		{
			sum += val[i];
		}
		return sum;
	}
	
private:
	std::vector<int> val;
};
