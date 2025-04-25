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
	TreeNode *ans = nullptr;
	int lca(TreeNode* rt, int cur_level, int &max_level) {
		max_level = std::max(cur_level, max_level);
		if(rt == nullptr)
			return cur_level;
		int left = lca(rt->left, cur_level + 1, max_level);
		int right = lca(rt->right, cur_level + 1, max_level);
		if(left == right && max_level == left) {
			ans = rt;
		}
		return std::max(left, right);
	}
public:
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		int max_level = -1;
		lca(root, 0, max_level);
		return ans;
	}
};