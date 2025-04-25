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
	void get_list(TreeNode* rt, std::vector<int> &ans) {
		if(rt == nullptr)
			return;
		get_list(rt->left, ans);
		ans.push_back(rt->val);
		get_list(rt->right, ans);
	}
public:
	std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		std::vector<int> arr1;
		std::vector<int> arr2;
		std::vector<int> res;
		get_list(root1, arr1);
		get_list(root2, arr2);
		int i = 0;
		int j = 0;
		while(i < arr1.size() && j < arr2.size()) {
			if(arr1[i] < arr2[j]) {
				res.push_back(arr1[i]);
				i++;
			} else {
				res.push_back(arr2[j]);
				j++;
			}
		}
		while(i < arr1.size()) {
			res.push_back(arr1[i]);
			i++;
		}
		while(j < arr2.size()) {
			res.push_back(arr2[j]);
			j++;
		}
		return res;
	}
};