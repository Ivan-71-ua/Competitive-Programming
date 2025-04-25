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
	int del_sub_sero(TreeNode* rt) {
		if(rt == nullptr)
			return 0;
		int lft = del_sub_sero(rt->left);
		int rgh = del_sub_sero(rt->right);
		if(!lft) {
			rt->left = nullptr;
		}
		if(!rgh) {
			rt->right = nullptr;
		}
		return lft | rgh | rt->val;
	}
public:
	TreeNode* pruneTree(TreeNode* root) {
		TreeNode *rt = new TreeNode(0, nullptr, root);
		del_sub_sero(rt);
		return rt->right;
	}
};