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
	void grandparets(TreeNode *rt, int &sum) {
		if(rt == nullptr) {
			return;
		}
		if(!(rt->val & 1)) {
			if(rt->left != nullptr) {
				if(rt->left->left != nullptr)
					sum += rt->left->left->val;
				if(rt->left->right != nullptr)
					sum += rt->left->right->val;
			}
			if(rt->right != nullptr) {
				if(rt->right->left != nullptr)
					sum += rt->right->left->val;
				if(rt->right->right != nullptr)
					sum += rt->right->right->val;
			}
		}
		grandparets(rt->left, sum);
		grandparets(rt->right, sum);
	} 
public:
	int sumEvenGrandparent(TreeNode* root) {
		int res = 0;
		grandparets(root, res);
		return res;
	}
};