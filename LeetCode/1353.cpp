#include <bits/stdc++.h>

class Solution {
public:
	int maxEvents(std::vector<std::vector<int>>& events) {
		int res = 0, n = events.size();
		std::stable_sort(events.begin(), events.end());
		std::priority_queue<int, std::vector<int>, std::greater<>> q;
		int day =  -1;
		int id = 0;
		while(!q.empty() || id < n) {
			if(q.empty()) {
				day = events[id][0];
			}
			while(id < n && events[id][0] <= day) {
				q.push(events[id][1]);
				id++;
			}
			day++;
			res++;
			q.pop();
			while(!q.empty() && q.top() < day) {
				q.pop();
			}
		}
		return res;
	}
};

int  main() {
	std::vector<std::vector<int>> ss{{1,5},{1,5},{1,5},{2,3},{2,3}};
	Solution ans;
	ans.maxEvents(ss);
}