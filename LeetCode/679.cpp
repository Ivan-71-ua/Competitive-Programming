#include <bits/stdc++.h>


class Solution {
public:
	bool judgePoint24(std::vector<int>& cards) {
		std::vector<double> ls_n(cards.begin(), cards.end());
		return solve(ls_n);
	}
	bool solve(std::vector<double> &ls_n) {
		if(ls_n.size() == 1) {
			return fabs(ls_n[0] - 24.0) < 1e-6;
		}
		int n = ls_n.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if(i == j) continue;

				std::vector<double> next;
				for (int k = 0; k < n; k++) {
					if(i != k && j != k) next.push_back(ls_n[k]);
				}
				double a = ls_n[i], b = ls_n[j];
				std::vector<double> res{a + b, a - b, b - a, a * b};
				if(fabs(a) > 1e-6) {
					res.push_back(b / a);
				}
				if(fabs(b) > 1e-6) {
					res.push_back(a / b);
				}

				for(auto v: res) {
					next.push_back(v);
					if(solve(next)) {
						return true;
					}
					next.pop_back();
				}
			}
		}
		return false;
	}
};