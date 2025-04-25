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
	void del_leav(TreeNode* rt, int target) {
		if(rt == nullptr)
			return;
		if(rt->left && rt->left->left == nullptr && rt->left->right == nullptr && rt->left->val == target) {
			delete rt->left;
			rt->left = nullptr;
		}
		if(rt->right && rt->right->left == nullptr && rt->right->right == nullptr && rt->right->val == target) {
			delete rt->right;
			rt->right = nullptr;
		}
		del_leav(rt->left, target);
		del_leav(rt->right, target);
		if(rt->left && rt->left->left == nullptr && rt->left->right == nullptr && rt->left->val == target) {
			delete rt->left;
			rt->left = nullptr;
		}
		if(rt->right && rt->right->left == nullptr && rt->right->right == nullptr && rt->right->val == target) {
			delete rt->right;
			rt->right = nullptr;
		}
	}
public:
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
		del_leav(root, target);
		if(root && root->val == target && root->left == nullptr && root->right == nullptr)
			return nullptr;
		return root;
	}
};