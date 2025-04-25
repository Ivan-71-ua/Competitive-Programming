
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
	std::unordered_map<int, std::vector<TreeNode*>> hash;
	std::vector<TreeNode*> Built(int n) {
		if(n % 2 == 0)
			return {};
		if(n == 1) {
			return {new TreeNode()};
		}
		if(hash.find(n) != hash.end())
			return hash[n];
		std::vector<TreeNode *> nodes;
		for (int i = 1; i < n; i += 2)
		{
			std::vector<TreeNode*> left = Built(i);
			std::vector<TreeNode *> right = Built(n - i - 1);
			for (auto l_t: left)
			{
				for(auto r_t: right) {
					TreeNode *root = new TreeNode();
					root->left = l_t;
					root->right = r_t;
					nodes.push_back(root);
				} 
			}
		}
		return hash[n] = nodes;
	}
public:
	std::vector<TreeNode*> allPossibleFBT(int n) {
		return Built(n);
	}
};