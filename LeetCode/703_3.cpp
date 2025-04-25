
#include <bits/stdc++.h>


class KthLargest {
	std::multiset<int> stream;
	int position;
public:
	KthLargest(int k, std::vector<int>& nums) {
		position = k;
		for (int i = 0; i < nums.size(); i++) {
			stream.insert(nums[i]);
			if(stream.size() > k)
				stream.erase(stream.begin());
		}
	}
	
	int add(int val) {
		stream.insert(val);
		if(stream.size() > position) {
			stream.erase(stream.begin());
		}
		return *stream.begin();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */