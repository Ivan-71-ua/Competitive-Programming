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
	int sumOfLeftLeaves(TreeNode* root, bool lf) {
		if(root == nullptr)
			return 0;
		if(root->left == nullptr && root->right == nullptr) {
			if(lf) {
				return root->val;
			} else {
				return 0;
			}
		}
		return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
	}
public:
	int sumOfLeftLeaves(TreeNode* root) {
		return sumOfLeftLeaves(root, false);
	}
};