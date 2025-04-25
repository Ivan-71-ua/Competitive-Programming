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
	void min_node(TreeNode* rt, int &min_val, int &max_val) {
		if(rt == nullptr) {
			return;
		}
		max_val = std::max(max_val, rt->val);
		min_val = std::min(min_val, rt->val);
		min_node(rt->left, min_val, max_val);
		min_node(rt->right, min_val, max_val);
	}

	void diff(TreeNode* rt, int &res) {
		if(rt == nullptr)
			return;
		if(rt->left) {
			int max_val = INT32_MIN;
			int min_val = INT32_MAX;
			min_node(rt->left, min_val, max_val);
			res = std::max({abs(rt->val - min_val), abs(rt->val - max_val), res});
		}
		if(rt->right) {
			int max_val = INT32_MIN;
			int min_val = INT32_MAX;
			min_node(rt->right, min_val, max_val);
			res = std::max({abs(rt->val - min_val), abs(rt->val - max_val), res});
		}
		diff(rt->left, res);
		diff(rt->right, res);
	}

public:
	int maxAncestorDiff(TreeNode* root) {
		int res = 0; 
		diff(root, res);
		return res;
	}
};
