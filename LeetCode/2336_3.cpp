

#include <bits/stdc++.h>


class SmallestInfiniteSet {
	int cur_min = 1;
	std::set<int> nums;

public:
	SmallestInfiniteSet() {
		
	}
	int popSmallest() {
		if(nums.empty()) {
			cur_min++;
			return cur_min - 1;
		}
		int ans = *nums.begin();
		nums.erase(ans);
		if(ans == cur_min)
			cur_min++;
		return ans;
	}
	
	void addBack(int num) {
		if(cur_min > num)
			nums.insert(num);
	}
};
