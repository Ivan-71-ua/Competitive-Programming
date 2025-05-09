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
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if(root == nullptr && subRoot == nullptr)
			return true;
		if(root == nullptr && subRoot != nullptr || root != nullptr && subRoot == nullptr)
			return false;
		if(root->val == subRoot->val)
			return true;
		return isSubtree(root->left, subRoot->left) && isSubtree(root->right, subRoot->right);
	}
};