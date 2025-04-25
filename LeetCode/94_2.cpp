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
    std::vector<int> inorderTraversal(TreeNode* root) {
        // Initialize a vector to store the result (in-order traversal)
        std::vector<int> res;
        
        // Initialize a stack for iterative traversal
        std::stack<TreeNode*> stack;

        // Loop until either the current node is not null or the stack is not empty
        while (root != nullptr || !stack.empty()) {
            // Traverse to the leftmost node and push each encountered node onto the stack
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }

            // Pop the last node from the stack (most recently left-visited node)
            root = stack.top();
            stack.pop();
            
            // Append the value of the popped node to the result vector
            res.push_back(root->val);
            
            // Move to the right subtree to continue the in-order traversal
            root = root->right;
        }

        // Return the final result vector
        return res;        
    }
};