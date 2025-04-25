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
	void sum_in_range(TreeNode* rt, int l, int r, int &ans) {
		if(rt == nullptr)
			return;

		if(rt->val > l) sum_in_range(rt->left, l, r, ans);
		if(rt->val < r) sum_in_range(rt->right, l, r, ans);

		if(rt->val <= r && rt->val >= l)
			ans += rt->val;
	}
public:
	int rangeSumBST(TreeNode* root, int low, int high) {
		int ans = 0;
		sum_in_range(root, low, high, ans);
		return ans;
	}
};