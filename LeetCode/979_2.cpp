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
	int Coins(TreeNode* rt, int &ans) {
		if(rt == nullptr)
			return 0;
		int l_t = Coins(rt->left, ans);
		int r_t = Coins(rt->right, ans);
		int extra = l_t + r_t - 1 + rt->val;
		ans += abs(extra);
		return extra;
	}
public:
	int distributeCoins(TreeNode* root) {
		int ans = 0;
		Coins(root, ans);
		return ans;
	}
};