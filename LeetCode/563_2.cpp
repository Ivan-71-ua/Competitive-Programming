
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
	int sum_height(TreeNode* rt, int &sum) {
		if(rt == nullptr)
				return 0;
		
		int sum_l = sum_height(rt->left, sum);
		int sum_r = sum_height(rt->right, sum);
		
		sum += abs(sum_l - sum_r);
		
		return rt->val + sum_l + sum_r; 
	}
public:
	int findTilt(TreeNode* root) {
		int sum = 0;
		sum_height(root, sum);
		return sum;
	}
};
