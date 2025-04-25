#include <bits/stdc++.h>

#include <string>

class Node {
public:
	Node *prev = nullptr;
	Node *next = nullptr;
	std::string url;
	Node(std::string &url) {
		this->url = url;
	}
};

class BrowserHistory {
	Node *cur = nullptr;
public:
	BrowserHistory(std::string homepage) {
		cur = new Node(homepage);
	}
	
	void visit(std::string url) {
		Node* nd = new Node(url);
		nd->prev = cur;
		cur->next = nd;
		cur = nd;
	}
	
	std::string back(int steps) {
		while(cur->prev && steps) {
			steps--;
			cur = cur->prev;
		}
		return cur->url;
	}
	
	std::string forward(int steps) {
		while(cur->next && steps) {
			steps--;
			cur = cur->next;
		}
		return cur->url;
	}
};
