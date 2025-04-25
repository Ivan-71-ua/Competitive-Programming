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
	void give_leaf(TreeNode *rt, std::vector<int> &res) {
		if(rt == nullptr)
			return;
		if(rt->left == nullptr && rt->right == nullptr) {
			res.push_back(rt->val);
		}
		give_leaf(rt->left, res);
		give_leaf(rt->right, res);
	}
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		std::vector<int> tr1;
		std::vector<int> tr2;
		give_leaf(root1, tr1);
		give_leaf(root2, tr2);
		if(tr1.size() != tr2.size())
			return false;
		return tr1 == tr2;
	}
};