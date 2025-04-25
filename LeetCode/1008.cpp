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
	TreeNode* bstFromPreorder(std::vector<int>& preorder) {
		if (preorder.empty()) return nullptr;
		std::stack<TreeNode *> BST;
		TreeNode *root = new TreeNode(preorder[0]);
		BST.push(root);
		for (int i = 1; i < preorder.size(); i++) {
				TreeNode *node = new TreeNode(preorder[i]);
				if (preorder[i] < BST.top()->val) {
					BST.top()->left = node;
				} else {
					TreeNode *parent = nullptr;
					while (!BST.empty() && BST.top()->val < preorder[i]) {
						parent = BST.top();
						BST.pop();
					}
					parent->right = node;
				}
				BST.push(node);
		}
		return root;
	}
};