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
	int Ball(TreeNode* rt) {
		if(rt == nullptr)
			return 0;
		int left =  Ball(rt->left);
		if(left == -1)
			return -1;
		int right = Ball(rt->right);
		if(right == -1)
			return -1;
		if(abs(left - right) > 1)
			return -1;
		return std::max(left, right) + 1;
	}
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;
		if(Ball(root) != -1)
			return true;
		return false;
	}
};