
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
	TreeNode* dfs(int rt, std::vector<std::pair<int, int>> &graf) {
		TreeNode *cur = new TreeNode(rt);
		auto [l, r] = graf[rt];
		if(!l) {
			cur->left = nullptr;
		} else {
			cur->left = dfs(l, graf);
		}
		if(!r) {
			cur->right = nullptr;
		} else {
			cur->right = dfs(r, graf);
		}
		return cur;
	}
public:
	TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
		std::vector<std::pair<int, int>> graf(10000 + 7);
		std::unordered_set<int> chiled;
		for (auto &k : descriptions) {
			int p = k[0], ch = k[1], w = k[2];
			chiled.insert(ch);
			if(w == 1)
				graf[p].first = ch;
			else
				graf[p].second = ch;
		}
		int root = -1;
		for(auto k: descriptions) {
			if(!chiled.count(k[0])) {
				root = k[0];
				break;
			}
		}
		return dfs(root, graf);
	}
};