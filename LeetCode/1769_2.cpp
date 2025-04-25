#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> minOperations(std::string boxes) {
		std::vector<int> ans(boxes.size());
		for (int i = 0, ones = 0, add_by_step = 0; i < boxes.size(); i++) {
			ans[i] += add_by_step;
			ones += boxes[i] - '0';
			add_by_step += ones;
		}
		for (int i = boxes.size() - 1, ones = 0, add_by_step = 0; i > -1; i--) {
			ans[i] += add_by_step;
			ones += boxes[i] - '0';
			add_by_step += ones;
		}
		return ans;
	}
};