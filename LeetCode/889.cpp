
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
	TreeNode* get_tree(std::vector<int>& preorder, std::vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd) {
		if(preStart > preEnd)
			return nullptr;
		TreeNode *cur = new TreeNode(preorder[preStart]);
		if(preEnd == preStart)
			return cur;
		int idxpost = postStart;
		while(postorder[idxpost] != preorder[preStart + 1])
			idxpost++;
		int len = idxpost - postStart + 1;
		cur->left = get_tree(preorder, postorder, preStart + 1, preStart + len, postStart, idxpost);
		cur->right = get_tree(preorder, postorder, preStart + len + 1, preEnd, idxpost + 1, postEnd - 1);
		return cur;
	}
public:
	TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
		return get_tree(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
	}
};