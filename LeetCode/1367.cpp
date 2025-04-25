#include <bits/stdc++.h>




struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	bool res = false;
	bool can_form(ListNode* head, TreeNode* root) {
		if(root == nullptr && head == nullptr || head == nullptr) {
			return true;
		}
		if(root == nullptr)
			return false;
		bool same = root->val == head->val;
		return same && (can_form(head->next, root->left) || can_form(head->next, root->right));
	}
	void dfs(ListNode* head, TreeNode* root) {
		if(root == nullptr || res) {
			return;
		}
		if(can_form(head, root)) {
			res = true;
		}
		dfs(head, root->left);
		dfs(head, root->right);
	}
public:
	bool isSubPath(ListNode* head, TreeNode* root) {
		dfs(head, root);
		return res;
	}
};