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
public:
	std::vector<int> preorderTraversal(TreeNode* root) {
		if(root == nullptr)
			return {};
		std::vector<int> ans;
		std::stack<TreeNode *> way;
		way.push(root);
		while (!way.empty())
		{
			TreeNode *node = way.top();
			way.pop();
			ans.push_back(node->val);
			if(node->right != nullptr) {
				way.push(node->right);
			}
			if(node->left != nullptr) {
				way.push(node->left);
			}
		}
		return ans;
	}
};