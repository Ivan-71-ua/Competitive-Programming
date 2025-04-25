
#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> canSeePersonsCount(std::vector<int>& heights) {
		int n = heights.size();
		std::vector<int> ans(n);
		std::stack<int> q;
		q.push(heights.back());
		for (int i = n - 2; i > -1; i--)
		{
			int count = 0;
			while(!q.empty() && q.top() < heights[i]) {
				q.pop();
				count++;
			}
			if(!q.empty()) {
				count++;
			}
			ans[i] = count;
			q.push(heights[i]);
		}
		return ans;
	}
};

int main() {
	std::vector<int> ss{10, 6, 8, 5, 11, 9};
	Solution ans;
	ans.canSeePersonsCount(ss);
}