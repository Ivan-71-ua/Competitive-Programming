
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
	void second_min(TreeNode *rt, long long firts, long long &second)
	{
		if(rt == nullptr)
			return;
		if(second > rt->val && rt->val != firts) {
			second = rt->val;
		} 
		second_min(rt->left, firts, second);
		second_min(rt->right, firts, second);
	}
public:
	int findSecondMinimumValue(TreeNode* root) {
		long long first = root->val;
		long long second = (long long)2147483647 +3;
		second_min(root, first, second);
		if(second == (long long)2147483647 +3)
			return -1;
		return second;
	}
};