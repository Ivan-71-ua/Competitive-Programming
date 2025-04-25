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
	std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		std::stack<TreeNode *> st1;
		std::stack<TreeNode *> st2;
		std::vector<int> ans;
		while(root1 != nullptr) {
			st1.push(root1);
			root1 = root1->left;
		}
		while(root2 != nullptr) {
			st2.push(root2);
			root2 = root2->left;
		}
		while(!st1.empty() || !st2.empty()) {
			auto &min_stack = st1.empty() ? st2 : (st2.empty() || st1.top()->val < st2.top()->val) ? st1	: st2;
			TreeNode *cur = min_stack.top();
			min_stack.pop();
			ans.push_back(cur->val);
			cur = cur->right;
			while (cur)
			{
				min_stack.push(cur);
				cur = cur->left;
			}
		}
		return ans;
	}
};