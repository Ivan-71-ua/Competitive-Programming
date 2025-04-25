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
	void serch(TreeNode* rt, int val, TreeNode* &ans) {
		if(rt == nullptr)
			return;
		if(rt->val == val) {
			ans = rt;
			return;
		}
		serch(rt->left, val, ans);
		serch(rt->right, val, ans);
	}
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		TreeNode *res = nullptr;
		serch(root, val, res);
		return res;
	}
};