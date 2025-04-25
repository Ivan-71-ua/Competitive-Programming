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
	void way_tree(TreeNode * rt, std::vector<int> &ans) {
		if(rt == nullptr)
			return;
		ans.push_back(rt->val);
		way_tree(rt->left, ans);
		way_tree(rt->right, ans);
	}
public:
	std::vector<int> preorderTraversal(TreeNode* root) {
		if(root == nullptr)
			return {};
		std::vector<int> ans;
		way_tree(root, ans);
		return ans;
	}
};