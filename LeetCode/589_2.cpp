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
public:
	std::vector<int> preorder(Node* rt) {
		if(rt == nullptr)
			return {};
		std::vector<int> ans;
		std::stack<Node *> chldr;
		chldr.push(rt);
		while(!chldr.empty()) {
			Node *tmp = chldr.top();
			chldr.pop();
			ans.push_back(tmp->val);
			for (int i = tmp->children.size() - 1; i >= 0; i--)
			{
				if(tmp->children[i] != nullptr) {
					chldr.push(tmp->children[i]);
				}
			}
		}
		return ans;
	}
};