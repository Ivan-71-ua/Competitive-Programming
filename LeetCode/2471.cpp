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
	int minimumOperations(TreeNode* root) {
		int res = 0;
		std::deque<TreeNode *> level;
		level.push_front(root);
		while(!level.empty()) {
			std::vector<int> cur_val;
			std::deque<TreeNode *> next_level;
			while(!level.empty()) {
				TreeNode *rt = level.front();
				level.pop_front();
				cur_val.push_back(rt->val);
				if(rt->left) {
					next_level.push_back(rt->left);
				}
				if(rt->right) {
					next_level.push_back(rt->right);
				}
			}
			for (int i = 0; i < cur_val.size(); i++)
			{
				int mins = i;
				for (int j = i + 1; j < cur_val.size(); j++)
				{
					if(cur_val[mins] > cur_val[j]) {
						mins = j;
					}
				}
				if(i != mins) {
					res++;
					std::swap(cur_val[i], cur_val[mins]);
				}
			}
			level = next_level;
		}
		return res;
	}
};  



