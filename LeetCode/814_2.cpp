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
		int lf = del_sub_sero(rt->left);
		int rg = del_sub_sero(rt->right);
		if(lf == 0)
			rt->left = nullptr;
		if(rg == 0)
			rt->right = nullptr;
		return rt->val | lf | rg;
	}
public:
	TreeNode* pruneTree(TreeNode* root) {
		return del_sub_sero(root) ? root : nullptr;
	}
};