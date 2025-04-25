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
	void Max_lieve(TreeNode* rt, std::unordered_map<int, int> &leave, int cur_deep, int &max_deep) {
		if(rt == nullptr)
			return;
		if(rt->left == nullptr && rt->right == nullptr) {
			leave[cur_deep] += rt->val;
			max_deep = std::max(max_deep, cur_deep);
		}
		Max_lieve(rt->left, leave, cur_deep + 1, max_deep);
		Max_lieve(rt->right, leave, cur_deep + 1, max_deep);
	}
public:
	int deepestLeavesSum(TreeNode* root) {
		std::unordered_map<int, int> leaves;
		int max_deep = 0;
		Max_lieve(root, leaves, 0, max_deep);
		return leaves[max_deep];
	}
};