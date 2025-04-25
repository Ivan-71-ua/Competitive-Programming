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
	std::pair<int, int> Coins(TreeNode* rt, int &ans) {
		if(rt == nullptr)
			return {0, 0};
		auto l_t = Coins(rt->left, ans);
		auto r_t = Coins(rt->right, ans);
		int size = l_t.first + r_t.first + 1;
		int coins = rt->val + r_t.second + l_t.second;
		ans += abs(size - coins);
		return {size, coins};
	}
public:
	int distributeCoins(TreeNode* root) {
		int ans = 0;
		Coins(root, ans);
		return ans;
	}
};