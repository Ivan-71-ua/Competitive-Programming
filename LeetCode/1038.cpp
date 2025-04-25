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
	void give_sort(TreeNode *rt, std::vector<int> &res) {
		if(rt == nullptr)
			return;
		give_sort(rt->left, res);
		res.push_back(rt->val);
		give_sort(rt->right, res);
	}
	std::vector<int> give_pref(std::vector<int> arr) {
		std::vector<int> pref(arr.size());
		pref[0] = arr[0];
		for (int i = 1; i < arr.size(); i++)
		{
			pref[i] = pref[i - 1] + arr[i];
		}
		return pref;
	}
	void bst_Gst(TreeNode *rt, std::vector<int> &arr, std::vector<int> &pref) {
		if(rt == nullptr)
			return;
		int l = 0;
		int r = arr.size() - 1;
		int mid = 0;
		while(l <= r) {
			mid = (l + r) / 2;
			if(arr[mid] > rt->val) {
				r = mid - 1;
			} else if(arr[mid] < rt->val) {
				l = mid + 1;
			} else {
				break;
			}
		}
		rt->val = pref.back() - (mid -1 > -1 ? pref[mid -1] : 0);
		bst_Gst(rt->left, arr, pref);
		bst_Gst(rt->right, arr, pref);
	}
public:
	TreeNode* bstToGst(TreeNode* root) {
		if(root == nullptr)
			return nullptr;
		std::vector<int> sorted;
		give_sort(root, sorted);
		std::vector<int> pref_sum = give_pref(sorted);
		bst_Gst(root, sorted, pref_sum);
		return root;
	}
};