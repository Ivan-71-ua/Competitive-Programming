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
	void way_post(TreeNode *rt, std::vector<int> &ans) {
		if(rt == nullptr)
			return;
		way_post(rt->left, ans);
		
		way_post(rt->right, ans);
		ans.push_back(rt->val);
	}
public:
	std::vector<int> postorderTraversal(TreeNode* root) {
		if(root == nullptr)
			return {};
		std::vector<int> ans;
		way_post(root, ans);
		return ans;
	}
};