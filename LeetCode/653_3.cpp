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
	void fill(TreeNode* rt, std::vector<int> &array) {
		if(rt == nullptr)
			return;
		fill(rt->left, array);
		array.push_back(rt->val);
		fill(rt->right, array);
	}
public:
	bool findTarget(TreeNode* root, int k) {
		std::vector<int> array;
		fill(root, array);
		int j = array.size() - 1;
		for (int i = 0; i < array.size(); i++)
		{
			while(i < j && array[i] + array[j] > k) {
				j--;
			}
			if(i == j)
				return false;
			if(array[i] + array[j] == k)
				return true;
		}
		return false;
	}
};