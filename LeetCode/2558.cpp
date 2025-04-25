#include <bits/stdc++.h>




class Solution {
public:
	long long pickGifts(std::vector<int>& gifts, int k) {
		std::priority_queue<int> q;
		for (auto &&i : gifts)
		{
			q.push(i);
		}
		while(k--) {
			int k = q.top();
			q.pop();
			q.push((int)sqrt(k));
		}
		long long res = 0;
		while(!q.empty()) {
			res += q.top();
			q.pop();
		}
		return res;
	}
};