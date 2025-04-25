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
	void Preorder(Node *rt, std::vector<int> &an) {
		if(rt == nullptr)
			return;
		an.push_back(rt->val);
		for (auto now: rt->children)
		{
			Preorder(now, an);
		}
	} 
public:
	std::vector<int> preorder(Node* root) {
		std::vector<int> ans;
		Preorder(root, ans);
		return ans;
	}
};