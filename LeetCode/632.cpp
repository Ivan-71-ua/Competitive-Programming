#include <bits/stdc++.h>


#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

class Solution {
	bool check(std::vector<int> &arr) {
		for (auto &n : arr) {
			if(n == 0)
					return false;
		}
		return true;
	}

public:
	std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
		std::vector<std::pair<int, int>> nums_group;
		std::vector<int> group(nums.size());

		for (int i = 0; i < nums.size(); i++) {
			for (auto &n : nums[i]) {
					nums_group.push_back({n, i});
			}
		}
		
		std::stable_sort(nums_group.begin(), nums_group.end());

		std::deque<std::pair<int, int>> q;
		std::vector<int> ans;
		int i = 0;
		int min_range = INT_MAX;

		for (int j = 0; j < nums_group.size(); ++j) {
			q.push_back(nums_group[j]);
			group[nums_group[j].second]++;
			while(check(group)) {
				int current_range = q.back().first - q.front().first;
				
				if (current_range < min_range) {
					min_range = current_range;
					ans = {q.front().first, q.back().first};
				}
				group[q.front().second]--;
				q.pop_front();
			}
		}
		return ans;
	}
};
