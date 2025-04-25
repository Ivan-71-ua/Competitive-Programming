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
	TreeNode* del_leav(TreeNode* rt, int target) {
		if(!rt)
			return nullptr;
		rt->left = del_leav(rt->left, target);
		rt->right = del_leav(rt->right, target);
		if(!rt->left && !rt->right && rt->val == target) {
			delete rt;
			return nullptr;
		}
		return rt;
	}
public:
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
		del_leav(root, target);
		return del_leav(root, target);
	}
};