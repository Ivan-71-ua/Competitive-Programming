#include <bits/stdc++.h>


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void height(TreeNode* rt, int cur_level, int &max_level, std::vector<int> &nodes) {
	if(rt == nullptr)
		return;
	max_level = std::max(max_level, cur_level);
	nodes[rt->val] = cur_level;
	height(rt->left, cur_level + 1, max_level, nodes);
	height(rt->right, cur_level + 1, max_level, nodes);
}

bool ancector(TreeNode* rt, std::set<int> leaves) {
	std::stack<TreeNode *> way;
	way.push(rt);
	while(!way.empty()) {
		TreeNode *cur = way.top();
		way.pop();
		leaves.erase(cur->val);
		if(cur->left) {
			way.push(cur->left);
		}
		if(cur->right) {
			way.push(cur->right);
		}
	}
	return leaves.size() == 0;
}

void dfs(TreeNode* rt, TreeNode* &ans, std::set<int> &leaves) {
	if(rt == nullptr)
		return;
	if(ancector(rt, leaves)) {
		ans = rt;
	}
	dfs(rt->left, ans, leaves);
	dfs(rt->right, ans, leaves);
}



class Solution {
public:
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		std::vector<int> nodes(1000 + 3);
		int max_level = 0;
		height(root, 1, max_level, nodes);
		std::set<int> leaves;
		for (int i = 0; i < 1000 + 3; i++)
		{
			if(nodes[i] == max_level)
				leaves.insert(i);
		}
		TreeNode *res = nullptr;
		dfs(root, res, leaves);
		return res;
	}
};