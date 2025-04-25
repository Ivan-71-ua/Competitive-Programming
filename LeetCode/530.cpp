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
	void min_abs(TreeNode *rt, int &min, int &pr) {
		if(rt == nullptr)
			return;
		min_abs(rt->left, min, pr);
		if(pr != -1) {
			min = std::min(min, abs(pr - rt->val));
		}
		pr = rt->val;
		min_abs(rt->right, min, pr);
	}
public:
	int getMinimumDifference(TreeNode* root) {
		int min = INT32_MAX, pref = -1;
		min_abs(root, min, pref);    
		return min;
	}
};