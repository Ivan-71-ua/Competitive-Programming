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
	void dfs(TreeNode* rt, int &kth, int &res) {
		if(rt == nullptr)
			return;
		dfs(rt->left, kth, res);
		if(kth == 0) {
			return;
		}
		kth--;
		if(kth == 0) {
			res = rt->val;
			return;
		}
		dfs(rt->right, kth, res);
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		int ans;
		dfs(root, k, ans);
		return ans;
	}
};