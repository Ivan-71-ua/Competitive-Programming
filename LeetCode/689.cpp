

#include <bits/stdc++.h>

class Solution {
	std::map<std::pair<int, int>, int> idx_cnt_to_val;

	int preproces(int idx, int cnt, const std::vector<int>& pref_k, int n, int k) {
		if (cnt == 3 || idx > n - k) {
			return 0;
		}
		if (idx_cnt_to_val.count({idx, cnt})) {
			return idx_cnt_to_val[{idx, cnt}];
		}
		int include = pref_k[idx] + preproces(idx + k, cnt + 1, pref_k, n, k);

		int skip = preproces(idx + 1, cnt, pref_k, n, k);

		idx_cnt_to_val[{idx, cnt}] = std::max(include, skip);
		return idx_cnt_to_val[{idx, cnt}];
	}

public:
	std::vector<int> maxSumOfThreeSubarrays(std::vector<int>& nums, int k) {
		int n = nums.size();
		std::vector<int> pref_k(n - k + 1);
		int cur_sum = 0;

		for (int i = 0; i < n; ++i) {
			cur_sum += nums[i];
			if (i >= k - 1) {
				pref_k[i - k + 1] = cur_sum;
				cur_sum -= nums[i - k + 1];
			}
		}

		preproces(0, 0, pref_k, n, k);

		std::vector<int> res;
		int i = 0;
		while (i <= n - k && res.size() < 3) {
			int include = pref_k[i] + idx_cnt_to_val[{i + k, res.size() + 1}];
			int skip = idx_cnt_to_val[{i + 1, res.size()}];
			if (include > skip || (include == skip && res.size() < 3)) {
				res.push_back(i);
				i += k;
			} else {
				i++;
			}
		}
		return res;
	}
};
