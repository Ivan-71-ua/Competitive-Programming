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
	void get_aver(TreeNode *rt, int &sum, int &quant) {
		if(rt == nullptr)
			return;
		sum += rt->val;
		quant++;
		get_aver(rt->left, sum, quant);
		get_aver(rt->right, sum, quant);
	}
	void Is_aver(TreeNode *rt, int &res) {
		if(rt == nullptr)
			return;
		int sum = 0, quant = 0;
		get_aver(rt, sum, quant);
		if(sum / quant == rt->val)
			res++;
		Is_aver(rt->left, res);
		Is_aver(rt->right, res);
	}
public:
	int averageOfSubtree(TreeNode * root)
	{
		int res = 0;
		Is_aver(root, res);
		return res;
	}
};