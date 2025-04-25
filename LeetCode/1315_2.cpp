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
public:
	void sumEvenGrandparentImpl(TreeNode* root, TreeNode* parent, TreeNode* grandParent, int& sum)
	{
		if (root == nullptr) {
			return;
		}
		if (grandParent != nullptr && grandParent->val % 2 == 0) {
			sum += root->val;
		}
		sumEvenGrandparentImpl(root->left, root, parent, sum);
		sumEvenGrandparentImpl(root->right, root, parent, sum);
	}	
	int sumEvenGrandparent(TreeNode* root) {
		int sum = 0;
		sumEvenGrandparentImpl(root, nullptr, nullptr, sum);
		return sum;
	}
};