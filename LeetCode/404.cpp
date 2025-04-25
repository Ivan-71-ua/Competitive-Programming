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
	void set_left(TreeNode *rt, int &sum) {
		if(rt == nullptr)
			return;
		if(rt->left != nullptr && rt->left->left == nullptr && rt->left->right == nullptr) {
			sum += rt->left->val;
		}
		set_left(rt->left, sum);
		set_left(rt->right, sum);
	}
public:
	int sumOfLeftLeaves(TreeNode* root) {
		int res = 0;
		set_left(root, res);
		return res;
	}
};