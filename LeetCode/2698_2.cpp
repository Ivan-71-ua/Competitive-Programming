


#include <bits/stdc++.h>

class Solution {
	bool canPartition(const std::string &k, int idx, int cur, int need) {
		if (cur > need) return false;  
		if (idx == k.size()) return cur == need; 

		int num = 0;
		for (int i = idx; i < k.size(); i++) {
			num = num * 10 + (k[i] - '0'); 
			if (canPartition(k, i + 1, cur + num, need))
				return true;
		}
		return false;
	}

public:
	int punishmentNumber(int n) {
		static std::vector<int> save(1001, -1);
		if (save[n] != -1) return save[n];

		int res = 0;
		for (int i = 1; i <= n; i++) {
			std::string sq = std::to_string(i * i);
			if (canPartition(sq, 0, 0, i))
				res += i * i;
		}
		return save[n] = res;
	}
};
