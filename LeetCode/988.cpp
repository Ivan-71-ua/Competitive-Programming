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
	std::string Min_lec(TreeNode* tr) {
		if(tr == nullptr)
			return "1";
		std::string res;
		if(tr->right != nullptr && tr->left != nullptr) {
			res += std::min(Min_lec(tr->left), Min_lec(tr->right));
		}
		if(tr->left == nullptr){
			res += Min_lec(tr->right);
		} 
		if(tr->right == nullptr) {
			res += Min_lec(tr->left);
		}
		res += ('a' + tr->val);
		return res;
	}
public:
	std::string smallestFromLeaf(TreeNode* root) {
		return Min_lec(root);
	}
};


int main() {
}   