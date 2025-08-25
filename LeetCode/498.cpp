
#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		int mn_max = std::max(n, m);
		std::vector<std::vector<int>> tmp(mn_max * 2);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i + j].push_back(mat[i][j]);
			}
		}
		std::vector<int> res;
		int k = 0;
		for(auto st: tmp) {
			if(!st.empty()) {
				if(k & 1) {
					for (int j = 0; j < st.size(); j++) {
						res.push_back(st[j]);
					}
				} else {
					for (int j = st.size() - 1; j > -1; j--) {
						res.push_back(st[j]);
					}
				}
				k++;
			}
		}
		return res;
	}
};