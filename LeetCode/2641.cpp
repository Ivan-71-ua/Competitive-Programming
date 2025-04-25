
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
	std::vector<int> deep;
	void dfs_f(TreeNode* rt, int level) {
		if(rt == nullptr)
			return;
		if(level >= deep.size()) {
			deep.push_back(rt->val);
		} else {
			deep[level] += rt->val;
		}
		dfs_f(rt->left, level + 1);
		dfs_f(rt->right, level + 1);
	}
	void dfs_s(TreeNode* rt, int level, int val) {
		if(rt == nullptr)
			return;
		rt->val = val;
		int sum = 0;
		if(level + 1 < deep.size()) {
			sum = deep[level + 1];
		}
		sum -= rt->left ? rt->left->val : 0;
		sum -= rt->right ? rt->right->val : 0;
		if(rt->left) dfs_s(rt->left, level + 1, sum);
		if(rt->right) dfs_s(rt->right, level  + 1, sum);
	}
public:
	TreeNode* replaceValueInTree(TreeNode* root) {
		dfs_f(root, 0);
		dfs_s(root, 0, 0);
		return root;
	}
};