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
	int minDepth(TreeNode* root) {
		if(root == nullptr) {
			return 0;
		}
		std::stack<TreeNode *> cur;
		std::stack<TreeNode *> next;
		int level = 1;
		cur.push(root);
		while(true) {
			while (!cur.empty())
			{
				if(cur.top()->left == nullptr && cur.top()->right == nullptr) {
					return level;
				}
				if(cur.top()->right != nullptr) {
					next.push(cur.top()->right);
				}
				if(cur.top()->left != nullptr) {
					next.push(cur.top()->left);
				}
				cur.pop();
			}
			std::swap(cur, next);
			level++;
		}
	}
};