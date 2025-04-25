
#include <bits/stdc++.h>


class Solution {
public:
	int countOrders(int n) {
		int slot = n * 2;
		int res = 1;
		while(slot > 0) {
			int valid = ((slot * (slot - 1)) / 2) % (1000000000 + 7);
			res = ((res % (1000000000 + 7)) * (long long)valid) % (1000000000 + 7);
			slot -= 2;
		}
		return res % (1000000000 + 7);
	}
};

