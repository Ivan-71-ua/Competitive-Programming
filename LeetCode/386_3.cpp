#include <bits/stdc++.h>


class Solution {
	std::vector<int> res;
public:
	std::vector<int> lexicalOrder(int n) {
		int cur = 1;
		while(res.size() < n) {
			res.push_back(cur);
			if(cur * 10 <= n) {
				cur *= 10;
			} else {
				while(cur == n || cur % 10 == 9) {
					cur /= 10;
				}
				cur++;
			}
		}
		return res;
	}
};