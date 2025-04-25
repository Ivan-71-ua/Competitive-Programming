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
	int maxDepth(TreeNode* root) {
		if(root == nullptr) {
			return 0;
		}
		int ans = 0;
		std::vector<TreeNode *> curLev;
		curLev.push_back(root);
		while(!curLev.empty()) {
			std::vector<TreeNode *> nexLev;
			for (auto now: curLev)
			{
				if(now->left != nullptr)
					nexLev.push_back(now->left);
				if(now->right != nullptr)
					nexLev.push_back(now->right);
			}
			std::swap(curLev, nexLev);
			ans++;
		}
		return ans;
	}
};