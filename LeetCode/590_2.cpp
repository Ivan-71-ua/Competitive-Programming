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
	std::vector<int> postorder(Node* root) {
		if(root == nullptr)
			return {};
		std::vector<int> ans;
		std::stack<Node *> chld;
		chld.push(root);
		while(!chld.empty()) {
			Node *tmp = chld.top();
			chld.pop();
			ans.push_back(tmp->val);
			for (int i = 0; i < tmp->children.size(); i++)
			{
				if(tmp->children[i] != nullptr)
					chld.push(tmp->children[i]);
			}
		}
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
};