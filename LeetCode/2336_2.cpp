#include <bits/stdc++.h>



class SmallestInfiniteSet {
	public:
		std::vector<int> nums;
		SmallestInfiniteSet() {
			nums.assign(1000 + 1, 0);
		}
	
		int popSmallest() {
			for (int i = 1; i <= 1000; i++) {
				if(nums[i] == 1) {
					nums[i] = 0;
					return i;
				}
			}
			return -1;
		}

		void addBack(int num) {
			nums[num] = 1;
		}
	};
