
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
	int max_hig(TreeNode *rt) {
		if(rt == nullptr)
			return 0;
		return 1 + std::max(max_hig(rt->left), max_hig(rt->right));
	}
	int max_d(TreeNode *rt) {
		if(rt == nullptr)
			return 0;
		int left_h = max_hig(rt->left);
		int right_h = max_hig(rt->right);

		int left_d = max_d(rt->left);
		int right_d = max_d(rt->right);
		return std::max({left_h + right_h, left_d, right_d});
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		return max_d(root);
	}
};