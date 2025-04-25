
#include <bits/stdc++.h>



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* rt, int cur_max, int &ans) {
	if(rt == nullptr)
		return;
	if(cur_max <= rt->val) {
		ans++;
	}
	cur_max = std::max(cur_max, rt->val);
	dfs(rt->left, cur_max, ans);
	dfs(rt->right, cur_max, ans);
}

class Solution {
public:
	int goodNodes(TreeNode* root) {
		int ans = 0;
		dfs(root, root->val, ans);
		return ans;
	}
};