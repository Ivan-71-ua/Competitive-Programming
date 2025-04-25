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
	std::vector<double> averageOfLevels(TreeNode* root) {
		std::vector<double> ans;
		std::queue<TreeNode *> level;
		level.push(root);
		while (!level.empty())
		{
			std::queue<TreeNode *> cur;
			int size = level.size();
			double res = 0;
			while (!level.empty())
			{
				TreeNode *tmp = level.front();
				level.pop();
				res += tmp->val;
				if(tmp->left != nullptr)
					cur.push(tmp->left);
				if(tmp->right != nullptr)
					cur.push(tmp->right);
			}
			level = cur;
			ans.push_back(res / size);
		}
		return ans;
	}
};