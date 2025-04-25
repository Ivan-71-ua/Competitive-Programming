#include <bits/stdc++.h>

class Node {
public:
	int val;
	std::vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, std::vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
	void Postorder(Node* rt, std::vector<int> &an) {
		if(rt == nullptr) {
			return;
		}
		for (auto now : rt->children)
		{
			if(now != nullptr)
				Postorder(now, an);
		}
		an.push_back(rt->val);
	}
public:
	std::vector<int> postorder(Node* root) {
		std::vector<int> ans;
		Postorder(root, ans);
		return ans;
	}
};