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
	int Hight_left(TreeNode* root) {
		int res = 0;
		while(root) {
			res++;
			root = root->left;
		}
		return res;
	}
	int Hight_right(TreeNode * root) {
		int res = 0;
		while (root)
		{
			res++;
			root = root->right;
		}
		return res;
	} 
	int Count_of_ver(TreeNode *rt) {
		if(rt == nullptr)
			return 0;
		int lf = Hight_left(rt);
		int rg = Hight_right(rt);
		if(lf == rg) {
			return (1 << lf) - 1;
		}
		else {
			return 1 + Count_of_ver(rt->left) + Count_of_ver(rt->right);
		}
	}
public:
	int countNodes(TreeNode* root) {
		return Count_of_ver(root);
	}
};