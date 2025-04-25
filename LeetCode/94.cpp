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
	void ToGoTree(TreeNode *rt, std::vector<int> &ans) {
		if(rt == nullptr) {
			return;
		}
		ToGoTree(rt->left, ans);
		ans.push_back(rt->val);
		ToGoTree(rt->right, ans);
	}
public:
	std::vector<int> inorderTraversal(TreeNode* root) {
		std::vector<int> ans;
		ToGoTree(root, ans);
		return ans;
	}
};