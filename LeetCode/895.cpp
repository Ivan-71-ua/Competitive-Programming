#include <bits/stdc++.h>


class FreqStack {
	std::vector<std::vector<int>> stak;
	std::unordered_map<int, int> freaq;
	int max = 0;
public:
	FreqStack() {
		stak.push_back({});
	}
	
	void push(int val) {
		freaq[val]++;
		if(max < freaq[val]) {
			stak.push_back({});
			max = freaq[val];
		}
		stak[freaq[val]].push_back(val);
	}
	
	int pop() {
		int val = stak[max].back();
		freaq[val]--;
		stak[max].pop_back();
		if(stak[max].empty()) {
			stak.pop_back();
			max--;
		}
		return val;
	}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */