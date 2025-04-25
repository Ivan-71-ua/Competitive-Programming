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
	void rev_un(TreeNode* rt,TreeNode* lf, int lev) {
		if(rt == nullptr)
			return;
		if(lev % 2 == 0) {
			std::swap(rt->val, lf->val);
		}
		rev_un(rt->left, lf->right, lev + 1);
		rev_un(rt->right, lf->left, lev + 1);
	}
public:
	TreeNode* reverseOddLevels(TreeNode* root) {
		rev_un(root->left, root->right, 0);
		return root;
	}
};