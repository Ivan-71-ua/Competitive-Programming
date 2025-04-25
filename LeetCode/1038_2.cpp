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
		
		void bst_Gst(TreeNode *rt, int &sum) {
			if(rt == nullptr)
				return;
			bst_Gst(rt->right, sum);
			rt->val += sum;
			sum = rt->val;
			bst_Gst(rt->left, sum);
		}
	public:
		TreeNode* bstToGst(TreeNode* root) {
			int sum = 0;
			bst_Gst(root, sum);
			return root;
		}
	};