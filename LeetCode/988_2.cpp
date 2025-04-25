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
public:
	std::string smallestFromLeaf(TreeNode* root) {
		std::string smallest;
		dfs(root, "", smallest);
		return smallest;
	}
	
	void dfs(TreeNode* node, std::string path, std::string& smallest) {
		if (node == nullptr) return;
		
		// Append current node's character to the path
		path += char('a' + node->val);
		
		// If it's a leaf node, compare and update smallest
		if (node->left == nullptr && node->right == nullptr) {
			std::reverse(path.begin(), path.end());
			if (smallest.empty() || path < smallest) {
					smallest = path;
			}
			std::reverse(path.begin(), path.end()); // backtrack by reversing again
		}
		
		// Recursively traverse left and right subtrees
		dfs(node->left, path, smallest);
		dfs(node->right, path, smallest);
	}
};


int main() {
}   