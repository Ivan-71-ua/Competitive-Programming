#include <bits/stdc++.h>

class Solution {
public:
   int maxArea(std::vector<int>& height) {
		int max_val = INT32_MIN;
		int r = 0, l = height.size() - 1;
		while(r < l) {
			max_val = std::max(max_val, (std::min(height[r], height[l]) * (l - r)));
			if(height[r] < height[l])
				r++;
			else {
				l--;
			}
		}
		return max_val;
	}
};

int main() {
	Solution ANS;
	std::vector<int> aa{1, 8, 6, 2, 5, 4, 8, 3, 7};
	ANS.maxArea(aa);
}