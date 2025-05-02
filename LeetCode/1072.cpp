
#include <bits/stdc++.h>



class Solution {
public:
	int maxEqualRowsAfterFlips(std::vector<std::vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		int res = 0;
		std::unordered_map<std::string, int> mp;
		for (int i = 0; i < n; i++) {
			std::string s = "";
			bool zero = matrix[i][0] == 1;
			for (int j = 0; j < m; j++) {
				if(zero) {
					s += '0' +(1 - matrix[i][j]);
				} else {
					s += '0' + matrix[i][j];
				}
			}
			mp[s]++;
			if(mp[s] > res) {
				res = mp[s];
			}
		}
		return res;
	}
};


