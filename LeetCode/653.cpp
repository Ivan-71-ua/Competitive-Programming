#include <bits/stdc++.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool Is_there(TreeNode* rt, int sum, std::unordered_set<int> &used) {
	if(rt == nullptr)
		return false;
	if(Is_there(rt->left, sum, used))
		return true;
	if(used.count(sum - rt->val))
		return true;
	used.insert(rt->val);
	return Is_there(rt->right, sum, used);
}

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		std::unordered_set<int> used;
		return Is_there(root, k, used);
	}
};