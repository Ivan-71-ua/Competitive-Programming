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
	int maxDepth(Node* root) {
		if(root == nullptr)
			return 0;
		int res = 1;
		for (auto now : root->children)
		{
			res = std::max(1 + maxDepth(now), res);
		}
		return res;
	}
};