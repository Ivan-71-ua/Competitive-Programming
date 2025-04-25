
#include <vector>


class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* Max_tree(std::vector<int>& nums, int str, int end){
		if(str>end || str == nums.size())return NULL;
		int mx = 0, index = str;
		for(int i=str;i<=end;i++){
			if(mx<nums[i]){
				mx=nums[i];
				index=i;
			}
		}
		TreeNode* res = new TreeNode(mx);
		res->left = Max_tree(nums,str,index-1);
		res->right = Max_tree(nums,index+1,end);
		return res;
	}
	TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
		return Max_tree(nums,0,nums.size()-1);
	}
};