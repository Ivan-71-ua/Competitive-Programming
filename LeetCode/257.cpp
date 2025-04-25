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
	void even_way(TreeNode *rt, std::string st, std::vector<std::string> &ans) {
		if(rt == nullptr) {
			return;
		}
		st += std::to_string(rt->val);
		if(rt->left == nullptr && rt->right == nullptr) {
			ans.push_back(st);
		}
		st +=  "->";
		if(rt->left != nullptr) 
			even_way(rt->left, st, ans);
		if(rt->right != nullptr)
			even_way(rt->right, st, ans);
	}
public:
	std::vector<std::string> binaryTreePaths(TreeNode* root) {
		std::string st = "";
		std::vector<std::string> ans;
		even_way(root, st, ans);
		return ans;
	}
};