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
	void dfs(TreeNode* rt,  std::vector<int> &top, int h) {
		if(rt == nullptr) {
			std::cout << '-';
			return;
		}
		
		if(top.size() < h) {
			if(rt == nullptr) std::cout << '+';
			top.push_back(rt->val);
		}
		dfs(rt->left, top, h + 1);
		dfs(rt->right, top, h + 1);
	}
public:
	int findBottomLeftValue(TreeNode* root) {
		std::vector<int> top;
		dfs(root, top, 1);
		return top.back();
	}
};