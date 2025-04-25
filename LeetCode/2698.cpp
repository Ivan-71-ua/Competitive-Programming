
#include <bits/stdc++.h>



class Solution {
void backtrac(std::string k, int idx, bool &can, int cur, int  size, const int need) {
		if(can)
			return;
		if(idx >= size) {
			if(need == cur)
				can = true;
		}
		for (int i = 1; i <= size - idx; i++) {
			int tmp = std::stoi(k.substr(idx, i));
			backtrac(k, idx + i, can, cur + tmp, size, need);
		}
}
public:
int punishmentNumber(int n) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			std::string sq = std::to_string(i * i);
			bool can = false;
			backtrac(sq, 0, can, 0, sq.size(), i);
			if(can)
				res += i * i;
		}
		return res;
}
};