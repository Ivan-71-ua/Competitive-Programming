#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> canSeePersonsCount(std::vector<int>& heights) {
		int n = heights.size();
		std::vector<int> ans(n);
		std::vector<int> stack;
		stack.push_back(heights.back());
		for (int i = n - 2; i > -1; i--)
		{
			int k = stack.size() - 1;
			while(k - 1 > -1 && stack[k] < heights[i]) {
				k--;
			}
			ans[i] = stack.size() - k;
			while (!stack.empty() && heights[i] > stack.back())
			{
				stack.pop_back();
			}
			stack.push_back(heights[i]);
		}
		return ans;
	}
};

int main() {
	std::vector<int> ss{10, 6, 8, 5, 11, 9};
	Solution ans;
	ans.canSeePersonsCount(ss);
}