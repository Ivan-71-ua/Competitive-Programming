
#include <bits/stdc++.h>




class Solution {
public:
	double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
		std::priority_queue<std::pair<double, std::pair<int, int>>> q;
		for (auto &p: classes)
		{
			int k = p[0], j = p[1];
			double dif = ((double)(k + 1) / (j + 1)) - ((double)k / j);
			q.push({dif, {k, j}});
		}
		while(extraStudents--) {
			int p = q.top().second.first + 1;
			int t = q.top().second.second + 1;
			double dif = ((double)(p + 1) / (t + 1)) - ((double)p / t);
			q.pop();
			q.push({dif, {p, t}});
		}
		double all = 0;
		while(!q.empty()) {
			int p = q.top().second.first;
			int t = q.top().second.second;
			double dif = (double)p / t;
			q.pop();
			all += dif;
		}
		return all / classes.size();
	}
};