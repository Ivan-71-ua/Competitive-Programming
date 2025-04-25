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
	std::unordered_map<int, int> digit;
	void way(TreeNode* rt) {
	if(rt == nullptr)
		return;
	digit[rt->val]++;
	way(rt->left);
	way(rt->right);
}

public:
	bool findTarget(TreeNode* root, int k) {
		way(root);
		//if(digit.size() < 2)
			//return false;
		for (auto now: digit)
		{
			if(k - now.first != now.first && digit.count(k - now.first))
				return true;
		}
		return false;
	}
};