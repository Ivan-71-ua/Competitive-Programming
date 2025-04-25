#include <bits/stdc++.h>


class MyQueue {
	std::stack<int> cur;
	std::stack<int> tmp;
public:
	MyQueue() {
	}
	
	void push(int x) {
		cur.push(x);
	}
	int pop() {
		while(!cur.empty()) {
			tmp.push(cur.top());
			cur.pop();
		}
		int res = tmp.top();
		tmp.pop();
		while (!tmp.empty())
		{
			cur.push(tmp.top());
			tmp.pop();
		}
		return res;
	}
	
	int peek() {
		while(!cur.empty()) {
			tmp.push(cur.top());
			cur.pop();
		}
		int res = tmp.top();
		while (!tmp.empty())
		{
			cur.push(tmp.top());
			tmp.pop();
		}
		return res;
	}
	
	bool empty() {
		return cur.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */