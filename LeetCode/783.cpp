
#include <bits/stdc++.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void way(TreeNode* rt, std::vector<int> &res) {
	if(rt == nullptr)
		return;
	way(rt->left, res);
	res.push_back(rt->val);
	way(rt->right, res);
}
class Solution {
public:
	int minDiffInBST(TreeNode* root) {
		std::vector<int> res;
		way(root, res);
		int min = INT32_MAX;
		for (int i = 1; i < res.size(); i++)
		{
			min = std::min(min, res[i] - res[i - 1]);
		}
		return min;
	}
};