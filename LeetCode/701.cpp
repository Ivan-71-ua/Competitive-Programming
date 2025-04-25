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
	void inset(TreeNode* root, TreeNode* parent, int val) {
		if(root == nullptr) {
			if(val > parent->val)  {
				parent->right = new TreeNode(val);
			} else {
				parent->left = new TreeNode(val);
			}
			return;
		}
		if(val > root->val) {
			inset(root->right, root, val);
		} else {
			inset(root->left, root, val);
		}
	}
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if(root == nullptr)
			return new TreeNode(val);
		inset(root, nullptr, val);
		return root;
	}
};