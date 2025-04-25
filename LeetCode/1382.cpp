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
	void give_sort(TreeNode* rt, std::vector<int> &res) {
		if(rt == nullptr)
			return;
		give_sort(rt->left, res);
		res.push_back(rt->val);
		give_sort(rt->right, res);
	}
	TreeNode* balance_BST( std::vector<int> &arr, int l, int r) {
		if(l > r)
			return nullptr;
		int mid = (l + r) / 2;
		TreeNode *ans = new TreeNode(arr[mid]);
		ans->left = balance_BST(arr, l, mid - 1);
		ans->right = balance_BST(arr, mid + 1, r);
		return ans;
	}
public:
	TreeNode* balanceBST(TreeNode* root) {
		std::vector<int> arr;
		give_sort(root, arr);
		return balance_BST(arr, 0, arr.size() - 1);
	}
};