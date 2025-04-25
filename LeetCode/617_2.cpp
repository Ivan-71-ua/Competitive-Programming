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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1 && !t2) return nullptr;
		int val1 = t1 ? t1->val : 0;
		int val2 = t2 ? t2->val : 0;
		TreeNode* newNode = new TreeNode(val1 + val2);

		newNode->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
		newNode->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);

		return newNode;
	}
};
