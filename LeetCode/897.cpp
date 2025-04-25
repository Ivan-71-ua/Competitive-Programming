
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
	void val_tree(TreeNode* rt, std::vector<int> &res) {
		if(rt == nullptr)
			return;
		val_tree(rt->right, res);
		res.push_back(rt->val);
		val_tree(rt->left, res);
	}
public:
	TreeNode* increasingBST(TreeNode* root) {
		std::vector<int> arr;
		val_tree(root, arr);
		TreeNode *tree = new TreeNode(arr.back());
		TreeNode *tmp = tree;
		arr.pop_back();
		while(!arr.empty()) {
			tmp->right = new TreeNode(arr.back());
			tmp = tmp->right;
			arr.pop_back();
		}
		return tree;
	}
};