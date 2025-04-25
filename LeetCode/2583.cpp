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
	int max_deep(TreeNode* rt) {
		if(rt == nullptr)
			return 0;
		return 1 + std::max(max_deep(rt->left), max_deep(rt->right));
	}
	void sum_level(TreeNode* rt, int level, std::vector<long long> &sum) {
		if(rt == nullptr)
			return;
		sum[level] += rt->val;
		sum_level(rt->left, level + 1, sum);
		sum_level(rt->right, level + 1, sum);
	}
public:
	long long kthLargestLevelSum(TreeNode* root, int k) {
		int d = max_deep(root);
		std::vector<long long> sum(d);
		sum_level(root, 0, sum);
		std::stable_sort(sum.begin(), sum.end(), std::greater());
		for (auto &n: sum)
		{
			std::cout << n << ' ';
		}
		
		if(k >= sum.size()) {
			return -1;
		}
		return sum[k - 1];
	}
};