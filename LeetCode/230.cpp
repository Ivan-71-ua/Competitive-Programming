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
	void dfs(TreeNode* rt, std::vector<int> &res) {
		if(rt == nullptr)
			return;
		dfs(rt->left, res);
		res.push_back(rt->val);
		dfs(rt->right, res);
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		std::vector<int> nums;
		nums.reserve(100000);
		dfs(root, nums);
		return nums[k - 1];
	}
};