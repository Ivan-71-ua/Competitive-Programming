
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
	void second_min(TreeNode *rt, int firts, int &second)
	{
		if(rt == nullptr)
			return;
		if(rt->val > firts) {
			if(second == -1)
				second = rt->val;
			else if(second > rt->val )
				second = rt->val;
			return;
		} 
		second_min(rt->left, firts, second);
		second_min(rt->right, firts, second);
	}
public:
	int findSecondMinimumValue(TreeNode* root) {
		int second = -1;
		second_min(root, root->val, second);
		return second;
	}
};