


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
	TreeNode *ans = nullptr;
	int dfs(TreeNode* rt, int cur_d, int &max_d) {
		max_d = std::max(cur_d, max_d);
		if (rt == nullptr)
			return;
		int lf = dfs(rt->left, cur_d + 1, max_d);
		int rh = dfs(rt->right, cur_d + 1, max_d);
		if(lf == rh && lf == max_d)
			ans = rt;
		return std::max(lf, rh);
	}

public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		int max_d = -1;
		dfs(root, 0, max_d);
		return ans;
	}
};