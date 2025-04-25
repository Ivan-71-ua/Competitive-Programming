#include <bits/stdc++.h>

class RecentCounter {
	std::queue<int> time;
public:
	RecentCounter() {
	}
	int ping(int t) {
		while(!time.empty() && time.front() < t) {
			time.pop();
		}
		time.push(t + 3000);
		return time.size();   
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */