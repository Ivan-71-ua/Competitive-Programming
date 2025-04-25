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
	bool Sym_Way(TreeNode *left, TreeNode *right) {	
		if(!left && !right) {
			return true;
		}
		if(!left || !right)
			return false;
		if(left->val != right->val)
				return false;
		return Sym_Way(left->left, right->right) && Sym_Way(left->right, right->left);
	}
public:
	bool isSymmetric(TreeNode* root) {
		if(!root)
			return true;
		bool is = Sym_Way(root->left, root->right);
		return is;
	}
};