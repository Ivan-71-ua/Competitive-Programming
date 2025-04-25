

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
	void Same_Tree(TreeNode *rt1, TreeNode *rt2, bool &is) {
		if(rt1 == nullptr && rt2 == nullptr) {
			return;
		}
		if(rt1 == nullptr && rt2 != nullptr || rt1 != nullptr && rt2 == nullptr) {
			is = false;
			return;
		}
		if(rt1->val != rt2->val) {
			is = false;
			return;
		}
		Same_Tree(rt1->left, rt2->left, is);
		Same_Tree(rt1->right, rt2->right, is);
	}
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		bool res = true;
		Same_Tree(p, q, res);
		return res;
	}
};