


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
	void give_leaf(TreeNode *rt, std::vector<int> &res) {
		if(rt == nullptr)
			return;
		if(rt->left == nullptr && rt->right == nullptr) {
			res.push_back(rt->val);
		}
		give_leaf(rt->left, res);
		give_leaf(rt->right, res);
	}
	bool isSimilar(TreeNode* rt2, std::vector<int> &tr1, int &pos) {
		if(rt2 == nullptr)
			return true;
		if(rt2->left == nullptr && rt2->right == nullptr) {
			if(pos < tr1.size() && tr1[pos] == rt2->val) {
				pos++;
				return true;
			} else {
				return false;
			}
		}
		return isSimilar(rt2->left, tr1, pos) && isSimilar(rt2->right, tr1, pos);
	}
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		std::vector<int> tr1;
		give_leaf(root1, tr1);
		int pos = 0;
		bool similar = isSimilar(root2, tr1, pos);
		return similar && pos == tr1.size();
	}
};