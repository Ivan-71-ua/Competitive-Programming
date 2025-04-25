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
	TreeNode* do_merge(TreeNode *rt1, TreeNode* rt2) {
		if(rt1 == nullptr && rt2 == nullptr)
			return nullptr;
		TreeNode *Root = new TreeNode();
		if(rt1 != nullptr && rt2 != nullptr) {
			Root->val = (rt1->val + rt2->val);
			Root->left = do_merge(rt1->left, rt2->left);
			Root->right = do_merge(rt1->right, rt2->right);
		}
		else if(rt1 != nullptr) {
			Root->val = rt1->val;
			Root->left = do_merge(rt1->left, nullptr);
			Root->right = do_merge(rt1->right, nullptr);
		}
		else if(rt2 != nullptr) {
			Root->val = rt2->val;
			Root->left = do_merge(nullptr, rt2->left);
			Root->right = do_merge(nullptr, rt2->right);
		}
		return Root;
	}
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		return do_merge(root1, root2);
	}
};