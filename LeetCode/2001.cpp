#include <bits/stdc++.h>

class Solution {
public:
   long long interchangeableRectangles(std::vector<std::vector<int>>& rectangles) {
		std::unordered_map<long double, int> ratio_quant;
		long long ans = 0;
		for (int i = 0; i < rectangles.size(); i++)
		{
			ratio_quant[(long double)rectangles[i][0] / rectangles[i][1]]++;
		}
		for (auto now: ratio_quant)
		{
			if(now.second > 1) {
				ans += ((long long)now.second * ((long long)now.second -1)) / 2;
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<int>> rectangles{{4, 5}, {7, 8}};
	ans.interchangeableRectangles(rectangles);
}