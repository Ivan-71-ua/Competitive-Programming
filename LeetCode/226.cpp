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
	TreeNode* Inver_Tree(TreeNode *rt) {
		if(rt == nullptr) {
			return nullptr;
		}
		TreeNode *ans = new TreeNode(rt->val);
		ans->left = Inver_Tree(rt->right);
		ans->right = Inver_Tree(rt->left);
		return ans;
	}
public:
	TreeNode* invertTree(TreeNode* root) {
		return Inver_Tree(root);
	}
};