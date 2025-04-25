

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
	int Count_of_ver(TreeNode *rt) {
		if(rt == nullptr)
			return 0;
		return (1 + Count_of_ver(rt->left) + Count_of_ver(rt->right));
	}
public:
	int countNodes(TreeNode* root) {
		return Count_of_ver(root);
	}
};