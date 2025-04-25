#include <bits/stdc++.h>


class KthLargest {
	std::multiset<int> stream;
	int pos;
public:
	KthLargest(int k, std::vector<int>& nums) {
		pos = k;
		for (int i = 0; i < nums.size(); i++) {
			stream.insert(nums[i]);
		}
	}
	
	int add(int val) {
		stream.insert(val);
		auto it = stream.end();
		for (int i = 0; i < pos; i++)
		{
			it--;
		}
		return *it;
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */