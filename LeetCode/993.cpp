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
	void height(TreeNode* rt, int x, int cur_ht, int parent, std::pair<int, int> &date) {
		if(rt == nullptr)
			return;
		if(rt->val == x) {
			date.first = cur_ht;
			date.second = parent;
			return;
		}
		height(rt->left, x, cur_ht + 1, rt->val, date);
		height(rt->right, x, cur_ht + 1, rt->val, date);
	}
public:
	bool isCousins(TreeNode* root, int x, int y) {
		std::pair<int, int> xs;
		std::pair<int, int> ys;
		height(root, x, 0, -1, xs);
		height(root, y, 0, -1, ys);
		return xs.first == ys.first && xs.second != ys.second;
	}
};