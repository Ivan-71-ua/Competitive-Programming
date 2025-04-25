#include <bits/stdc++.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		std::stack<TreeNode *> way;
		if(root != nullptr) {
			way.push(root);
		}
		while(!way.empty()) {
			TreeNode *node = way.top();
			way.pop();
			std::swap(node->right, node->left);
			if(node->left != nullptr) {
				way.push(node->left);
			}
			if(node->right != nullptr) {
				way.push(node->right);
			}
		}
		return root;
	}
};
