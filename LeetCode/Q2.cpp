#include <bits/stdc++.h>


class Solution {
public:

	bool are_almost_equal(int a, int b) {
		std::string str_a = std::to_string(a);
		std::string str_b = std::to_string(b);

	
		while (str_a.size() < str_b.size()) {
			str_a = "0" + str_a;
		}
		while (str_b.size() < str_a.size()) {
			str_b = "0" + str_b;
		}

	
		std::vector<int> diff_positions;
		for (int i = 0; i < str_a.size(); i++) {
			if (str_a[i] != str_b[i]) {
					diff_positions.push_back(i);
			}
		}


		if (diff_positions.size() > 2 || diff_positions.size() == 1) {
			return false;
		}

	
		if (diff_positions.size() == 2) {
			int i = diff_positions[0];
			int j = diff_positions[1];
			return (str_a[i] == str_b[j] && str_a[j] == str_b[i]);
		}

		
		return true;
	}

	
	int countPairs(std::vector<int>& nums) {
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				
					if (nums[i] == nums[j] || are_almost_equal(nums[i], nums[j])) {
						count++;
					}
			}
		}
		return count;
	}
};