
#include <bits/stdc++.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

	std::vector<int> ans;
	int maxi = 0, freq = 1, prev = -1e6;
	void helper(TreeNode* root){
		if(!root)
			return ;
		helper(root -> left);
		if(prev == -1e6)
			prev = root -> val;
		else if(root -> val != prev){
			if(freq > maxi){
					maxi = freq;
					ans = {prev};
			}
			else if(freq == maxi)
				ans.push_back(prev);
			freq = 1;
			prev = root -> val;
		}
		else
			freq++;
		helper(root -> right);
	}
	std::vector<int> findMode(TreeNode* root) {
		helper(root);
		if(freq > maxi)
			ans = {prev};
		else if(freq == maxi)
			ans.push_back(prev);
		return ans;
	}
};