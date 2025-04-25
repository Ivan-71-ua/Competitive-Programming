



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	void dfs(TreeNode* rt, int cur_val, int &ans) {
		if(rt == nullptr)
			return;
		cur_val = cur_val * 2 + rt->val;
		if(rt->left == nullptr && rt->right == nullptr)
			ans += cur_val;
		dfs(rt->left, cur_val, ans);
		dfs(rt->right, cur_val, ans);
	}
public:
	int sumRootToLeaf(TreeNode* root) {
		int sum = 0;
		dfs(root, 0, sum);
		return sum;
	}
};