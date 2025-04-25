#include <bits/stdc++.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class FindElements {
public:
	std::unordered_set<int> used;
	void Built_tree(TreeNode* rt, int val) {
		if(rt == nullptr)
			return;
		rt->val = val;
		used.insert(val);
		if(rt->left) {
			Built_tree(rt->left, val + val + 1);
		}
		if(rt->right) {
			Built_tree(rt->right, val + val + 2);
		}
	}
	FindElements(TreeNode* root) {
		Built_tree(root, 0);
	}
	
	bool find(int target) {
		return used.count(target);
	}
};