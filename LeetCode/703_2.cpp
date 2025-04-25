
#include <bits/stdc++.h>


class KthLargest {
	std::priority_queue<int, std::vector<int>, std::greater<int>> stream;
	int position;
public:
	KthLargest(int k, std::vector<int>& nums) {
		position = k;
		for (int i = 0; i < nums.size(); i++) {
			stream.push(nums[i]);
			if(stream.size() > k)
				stream.pop();
		}
	}
	
	int add(int val) {
		if(stream.size() == position && stream.top() >= val) {
			return stream.top();
		}
		stream.push(val);
		if(stream.size() > position) {
			stream.pop();
		}
		return stream.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */