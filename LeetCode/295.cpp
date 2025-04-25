
#include <bits/stdc++.h>


class MedianFinder {
	std::priority_queue<int> small;
	std::priority_queue<int, std::vector<int>, std::greater<>> big;
public:
	MedianFinder() {
		
	}
	void addNum(int num) {
		small.push(num);
		if(!small.empty() && !big.empty() && small.top() > big.top()) {
			int tmp = small.top();
			small.pop();
			big.push(tmp);
		}
		if(small.size() > big.size() + 1) {
			int tmp = small.top();
			small.pop();
			big.push(tmp);
		}
		if(big.size() > small.size() + 1) {
			int tmp = big.top();
			big.pop();
			small.push(tmp);
		}
	}
	
	double findMedian() {
		if(small.size() > big.size()) {
			return small.top();
		} else if(small.size() < big.size()) {
			return big.top();
		}
		return (small.top() + big.top()) / 2.0;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */