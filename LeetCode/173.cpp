#include <bits/stdc++.h>


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class BSTIterator {
	void dfs(TreeNode* rt, std::vector<int> &res) {
		if(rt == nullptr)
			return;
		dfs(rt->left, res);
		res.push_back(rt->val);
		dfs(rt->right, res);
	}
	std::vector<int> res;
	int i = 0;
public:
	BSTIterator(TreeNode* root) {
		dfs(root, res);
	}
	int next() {
		return res[i++];
	}
	
	bool hasNext() {
		return i < res.size();
	}
};
