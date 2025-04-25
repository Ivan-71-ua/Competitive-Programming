#include <bits/stdc++.h>



class Solution {
	int n, per_s;
	std::bitset<21> used;
	std::vector<int> ans;
	bool can(int idx) {
		if(idx == per_s)
			return used.count() == n;
		if(ans[idx] != 0)
			return can(idx + 1);
		for (int j = n; j > 0; j--) {
			if(used[j]) continue;
			int next_idx = (j > 1) ? idx + j	: idx;
			if(next_idx > per_s || ans[next_idx] != 0) continue;
			ans[idx] = ans[next_idx] = j;
			used[j] = 1;
			if(can(idx +1))
				return true;
			ans[idx] = ans[next_idx] = used[j] = 0;
		}
		return false;
	}
public:
	std::vector<int> constructDistancedSequence(int n) {
		this->n = n;
		this->per_s = n * 2 - 1;
		ans.assign(per_s, 0);
		can(0);
		return ans;
	}
};