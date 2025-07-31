#include <bits/stdc++.h>


class Solution {
public:
	int subarrayBitwiseORs(std::vector<int>& arr) {
		std::unordered_set<int> cnt, cur;
		for(auto num: arr) {
			std::unordered_set<int> next;
			for(auto n: cur) {
				next.insert(n | num);
			}
            next.insert(num);
			cur = next;
			cnt.insert(cur.begin(), cur.end());
		}
		return cnt.size();
	}
};