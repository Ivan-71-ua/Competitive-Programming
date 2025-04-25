#include <bits/stdc++.h>

class Solution {
	int Quant_of_ones(int n) {
		int ans = 0;
		while(n != 0) {
			if(1 & n)
				ans++;
			n = n >> 1;
		}
		return ans;
	}
public:
   std::vector<int> countBits(int n) {
		std::vector<int> ans;
		for (int i = 0; i <= n; i++)
		{
			ans.push_back(Quant_of_ones(i));
		}
		return ans;
	}
};

int main() {
	Solution ans;
	ans.countBits(5);
}