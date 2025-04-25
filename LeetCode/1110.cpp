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
	std::set<TreeNode *> ans;
	std::set<int> deletes;
	TreeNode* dfs(TreeNode* rt) {
		if(rt == nullptr)
			return nullptr;
		TreeNode *res = rt;
		if(deletes.count(rt->val)) {
			ans.erase(rt);
			res = nullptr;
			if(rt->left)
				ans.insert(rt->left);
			if(rt->right)
				ans.insert(rt->right);
		}
		rt->left = dfs(rt->left);
		rt->right = dfs(rt->right);
		return res;
	}
public:
	std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) {
		ans.insert(root);
		for (auto now: to_delete)
		{
			deletes.insert(now);
		}
		dfs(root);
		return {ans.begin(), ans.end()};
	}
};