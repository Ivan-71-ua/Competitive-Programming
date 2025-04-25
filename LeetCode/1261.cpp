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
	void BuildTree(TreeNode* rt, int prev, int way) {
		if(rt == nullptr)
			return;
		if(prev != -1) {
			if(way == 1) {
				rt->val = prev + prev + 1;
			} else {
				rt->val = prev + prev + 2;
			}
		}
		BuildTree(rt->left, rt->val, 1);
		BuildTree(rt->right, rt->val, 2);
	}
	void find_in_tree(TreeNode* rt, int target, bool &res) {
		if(rt == nullptr)
			return;
		if(rt->val == target) {
			res = true;
			return;
		}
		find_in_tree(rt->left, target, res);
		find_in_tree(rt->right, target, res);
	}
public:
	TreeNode *tree = nullptr;
	FindElements(TreeNode* root) {
		if(root) {
			root->val = 0;
		}
		BuildTree(root, -1, -1);
		tree = root;
	}
	bool find(int target) {
		bool is = false;
		find_in_tree(tree, target, is);
		return is; 
	}
};	