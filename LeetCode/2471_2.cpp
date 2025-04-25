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
				std::vector<int> sorted(cur_val.size());
				for (int i = 0; i < cur_val.size(); i++)
				{
					sorted[i] = cur_val[i];
				}
				std::stable_sort(sorted.begin(), sorted.end());
				std::unordered_map<int, int> num_idx;
				for (int i = 0; i < cur_val.size(); i++)
				{
					num_idx[cur_val[i]] = i;
				}
				for (int i = 0; i < cur_val.size(); i++)
				{
					if(sorted[i] != cur_val[i]) {
						res++;
					}
					int j = num_idx[sorted[i]];
					std::swap(cur_val[i], cur_val[j]);
					num_idx[cur_val[j]] = j;
				}
			}
			return res;
		}
	};  


