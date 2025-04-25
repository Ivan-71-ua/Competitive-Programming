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
	std::pair<int,int>solve(TreeNode* root, int &ans){
		if(root == NULL) return {0,0};
		auto left = solve(root->left, ans);
		auto right = solve(root->right, ans);
		int curSum = left.first + right.first + root->val;
		int curNodes = left.second + right.second + 1;
		if(curSum/curNodes == root->val) ans++;
		return {curSum, curNodes};
	}
	int averageOfSubtree(TreeNode* root) {
		int ans = 0;
		solve(root, ans);
		return ans;
	}
};