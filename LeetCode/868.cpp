
#include <bits/stdc++.h>

class Solution {
public:
	int binaryGap(int n) {
		int res = 0;
		std::bitset<32> ones(n);
		int prev = -1;
		for (int i = 0; i < 32; i++)
		{
			if(ones[i] == 1) {
				if(prev == -1)
					prev = i;
				else {
					res = std::max(res, i - prev);
					prev = i;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution ans;
	ans.binaryGap(22);
}