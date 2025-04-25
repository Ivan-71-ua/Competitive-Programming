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
	std::vector<int> dfs(TreeNode* rt, int dist, int &res) {
		if(!rt) {
			return std::vector<int>(dist + 1, 0);
		}
		if(!rt->left && !rt->right) {
			std::vector<int> leaves(dist + 1, 0);
			leaves[1] = 1;
			return leaves;
		}

		std::vector<int> right = dfs(rt->right, dist, res);
		std::vector<int> left = dfs(rt->left, dist, res);

		for (int l = 1; l <= dist; l++)
		{
			for (int r = 1; r <= dist - l; r++)
			{
				res += left[l] * right[r];
			}
		}
		std::vector<int> leaves(dist + 1, 0);
		for (int i = 1; i < dist; i++) {
			leaves[i + 1] = right[i] + left[i];
		}
		return leaves;
	}

public:
	int countPairs(TreeNode* root, int distance) {
		int res = 0;
		dfs(root, distance, res);
		return res;
	}
};