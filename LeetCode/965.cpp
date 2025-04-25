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
	void dfs(TreeNode* rt, int parent, bool &ans) {
		if(rt == nullptr)
			return;
		if(rt->val != parent) {
			ans = false;
			return;
		}
		dfs(rt->left, rt->val, ans);
		dfs(rt->right, rt->val, ans);
	}
public:
	bool isUnivalTree(TreeNode* root) {
		bool ans = true;
		dfs(root, root->val, ans);
		return ans;
	}
};