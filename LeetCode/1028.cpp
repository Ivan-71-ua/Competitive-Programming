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
	void give_pass(TreeNode* rt, std::string deep, std::string &res) {
		if(rt == nullptr)
			return;
		res += std::to_string(rt->val);
		res += deep;
		give_pass(rt->left, deep + '-', res);
		give_pass(rt->right, deep + '-', res);
	}
public:
	TreeNode* recoverFromPreorder(std::string traversal) {
		std::string prepare;
		prepare += traversal[0];
		for (int i = 1; i < traversal.size(); i++)
		{
			if(isdigit(traversal[i - 1]) && traversal[i] == '-' || traversal[i - 1] == '-' && isdigit(traversal[i])) {
				prepare += ' ';
			}
			prepare += traversal[i];
		}
		int eges;
		std::stringstream parse(prepare);
		parse >> eges;
		TreeNode *ans = new TreeNode(eges);
		std::stack<std::pair<TreeNode*, int>> tree;
		tree.push({ans, 0});
		while(parse >> prepare >> eges) {
			TreeNode *tmp = new TreeNode(eges);
			if(tree.top().second < prepare.size()) {
				tree.top().first->left = tmp;
				tree.push({tmp, prepare.size()});
			} else {
				while(tree.top().second >= prepare.size()) {
					tree.pop();
				}
				tree.top().first->right = tmp;
				tree.push({tmp, prepare.size()});
			}
		}
		return ans;
	}
};
int main() {
	Solution ans;
	ans.recoverFromPreorder("1-2--3---4-5--6---7");
}