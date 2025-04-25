#include <bits/stdc++.h>


class CustomStack {
	std::vector<int> stack;
	int size;

public:
	CustomStack(int maxSize) {
		stack.reserve(maxSize);
		size = maxSize;
	}
	
	void push(int x) {
		if(stack.size() < size) {
			stack.push_back(x);
		}
	}
	
	int pop() {
		int tmp;
		if(!stack.empty()) {
			tmp = stack.back();
			stack.pop_back();
		} else {
			tmp = -1;
		}
		return tmp;
	}
	void increment(int k, int val) {
		for (int i = 0; i < std::min(k, (int)stack.size()); i++)
		{
			stack[i] += val;
		}
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */