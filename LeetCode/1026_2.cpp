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
	void diff(TreeNode* rt, int max, int min, int &res) {
		if(rt == nullptr)
			return;
		max = std::max(max, rt->val);
		min = std::min(min, rt->val);
		res = std::max(res, max - min);
		diff(rt->left, max, min, res);
		diff(rt->right, max, min, res);
	}
public:
	int maxAncestorDiff(TreeNode* root) {
		int res = INT32_MIN; 
		diff(root, INT32_MIN, INT32_MAX, res);
		return res;
	}
};
