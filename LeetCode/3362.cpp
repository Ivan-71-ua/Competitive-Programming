
#include <bits/stdc++.h>




class Solution {
public:
	int maxRemoval(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
		sort(queries.begin(), queries.end());
		std::priority_queue<int> heap;
		std::vector<int> diff_arr(nums.size() + 1, 0);
		int cur_dif = 0;
		for (int i = 0, j = 0; i < nums.size(); i++) {
			cur_dif += diff_arr[i];
			while (j < queries.size() && queries[j][0] == i) {
				heap.push(queries[j][1]);
				j++;
			}
			while (cur_dif < nums[i] && !heap.empty() && heap.top() >= i) {
				cur_dif += 1;
				diff_arr[heap.top() + 1] -= 1;
				heap.pop();
			}
			if (cur_dif < nums[i]) {
				return -1;
			}
		}
		return heap.size();
	}
};