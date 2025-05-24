#include <bits/stdc++.h>



class Solution {
	std::vector<std::vector<int>> res;
	std::vector<int> cur;
	int sum = 0;
	void backTrack(int k, int n, int start) {
		if(cur.size() == k) {
			if(sum == n) {
				res.push_back(cur);
			}
			return;
		}
		for (int i = start; i < 10; i++) {
			cur.push_back(i);
			sum += i;
			backTrack(k, n, i + 1);
			sum -= i;
			cur.pop_back();
		}
	}
public:
	std::vector<std::vector<int>> combinationSum3(int k, int n) {
		backTrack(k, n, 1);
		return res;
	}
};