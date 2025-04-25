#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> constructRectangle(int area) {
		int W = sqrt(area);
		while(W > 0) {
			int L = area / W;
			if (L >= W && L * W == area) {
				return {L, W};
			}
			W--;
		}
		return {};
	}
};

int main() {
	Solution ans;
	ans.constructRectangle(37);
}