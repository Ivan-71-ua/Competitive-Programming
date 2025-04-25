#include <bits/stdc++.h>

const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

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
	int deepestLeavesSum(TreeNode* root) {
		std::vector<TreeNode *> way;
		way.push_back(root);
		int ans = 0;
		while(!way.empty()) {
			std::vector<TreeNode *> tmp;
			int res = 0;
			tmp = way;
			way.clear();
			while(!tmp.empty()) {
				TreeNode *node = tmp.back();
				tmp.pop_back();
				res += node->val;
				if(node->left != nullptr)
					way.push_back(node->left);
				if(node->right != nullptr)
					way.push_back(node->right);
			}
			ans = res;
		}
		return ans;
	}
};
