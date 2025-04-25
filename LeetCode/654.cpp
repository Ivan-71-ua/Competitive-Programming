#include <vector>


class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int MAX(const std::vector<int>& nums, int i, int j) {
		if(i < 0 || i >= nums.size() || j < 0 || j >= nums.size()) {
			return -1;
		}
		int res = -1;
		int idx = -1;
		for (; i <= j; i++) {
			if(nums[i] > res) {
				res = nums[i];
				idx = i;
			}
		}
		return idx;
	}
	
	TreeNode* Max_tree(const std::vector<int> &nums, int st, int fn) {
		if(st > fn) {
			return nullptr;
		}
		int idx = MAX(nums, st, fn);
		if(idx == -1)
			return nullptr;
		TreeNode *ans = new TreeNode(nums[idx]);
		ans->left = Max_tree(nums, st, idx - 1);
		ans->right = Max_tree(nums, idx + 1, fn);
		return ans;
	}

public:
	TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
		return Max_tree(nums, 0, nums.size() - 1);
	}
};
