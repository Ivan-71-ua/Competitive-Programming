
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
	std::map<int, int> count;
	void way(TreeNode* rt, int &max) {
		if(rt == nullptr)
			return;
		count[rt->val]++;
		max = std::max(max, count[rt->val]);
		way(rt->left, max);
		way(rt->right, max);
	}
public:
	std::vector<int> findMode(TreeNode* root) {
		int max = 0;
		way(root, max);
		std::vector<int> res;
		for (auto now: count)
		{
			if(now.second == max) {
				res.push_back(now.first);
			}
		}
		return res;
	}
};