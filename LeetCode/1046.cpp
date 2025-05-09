#include <bits/stdc++.h>


class Solution {
public:
	int lastStoneWeight(std::vector<int>& stones) {
		std::priority_queue<int> q;
		for (int i = 0; i < stones.size(); i++)
		{
			q.push(stones[i]);
		}
		while(q.size() > 1) {
			int x = q.top();
			q.pop();
			int y = q.top();
			q.pop();
			if(x != y) {
				q.push(abs(x - y));
			}
		}
		if(q.empty()) {
			return 0;
		}
		return q.top();
	}
};