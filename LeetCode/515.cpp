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
	std::vector<int> largestValues(TreeNode* root) {
		std::vector<int> ans;
		std::queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			long long min = INT64_MIN;
			while(size--) {
				TreeNode *rt = q.front();
				q.pop();
				if(!rt) continue;
				min = std::max(min, (long long)rt->val);
				q.push(rt->left);
				q.push(rt->right);
			}
			if(min != INT64_MIN)
				ans.push_back(min);
		}
		return ans;
	}
};