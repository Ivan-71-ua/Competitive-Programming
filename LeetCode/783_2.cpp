
#include <bits/stdc++.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void way(TreeNode* rt, int &prev, bool &prevFill, int &ans) {
	if(rt == nullptr)
		return;
	way(rt->left, prev, prevFill, ans);
	if(prevFill) {
		int diff = rt->val - prev;
		ans = std::min(ans, diff);
	}
	prev = rt->val;
	prevFill = true;
	way(rt->right, prev, prevFill, ans);
}
class Solution {
public:
	int minDiffInBST(TreeNode* root) {
		int prev = 0;
		bool prevFill = false;
		int ans = INT32_MAX;
		way(root, prev, prevFill, ans);
		return ans;
	}
};