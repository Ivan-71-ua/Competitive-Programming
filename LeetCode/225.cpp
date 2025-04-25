#include <bits/stdc++.h>

class MyStack {
	std::queue<int> stack;
public:
	MyStack() {

	}
	
	void push(int x) {
		stack.push(x);
	}
	
	int pop() {
		for (int i = 0; i < stack.size() - 1; i++) {
			stack.push(stack.front());
			stack.pop();
		}
		int res = stack.front();
		stack.pop();
		return res;
	}
	
	int top() {
		return stack.back();
	}
	
	bool empty() {
		return stack.empty();
	}
};