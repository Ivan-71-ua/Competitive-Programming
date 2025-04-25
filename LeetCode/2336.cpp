#include <bits/stdc++.h>




class SmallestInfiniteSet {
public:
	std::priority_queue<int, std::vector<int>, std::greater<>> q;
	SmallestInfiniteSet() {
		for (int i = 1; i < 10001; i++) {
			q.push(i);
		}
	}

	int popSmallest() {
		int k = q.top();
		while(q.top() == k)
			q.pop();
		return k;
	}
	
	void addBack(int num) {
		q.push(num);
	}
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */