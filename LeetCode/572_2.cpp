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
	bool areEqule(TreeNode *n1, TreeNode *n2) {
		if(n1 == nullptr && n2 == nullptr)
			return true;
		else if(n1 == nullptr || n2 == nullptr)
			return false;
		else {
			return n1->val == n2->val && areEqule(n1->left, n2->left) && areEqule(n1->right, n2->right);
		}
	}
public:
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if(root == nullptr)
			return false;
		else {
			return areEqule(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
		}
	}
};