#include <bits/stdc++.h>


class Solution {
public:
	bool hasAlternatingBits(int n) {
		int prev = -1;
		int cur = -1;
		while(n != 0) {
			prev = cur;
			cur = n % 2;
			n /= 2;
			if(prev == cur && (cur == 1 || cur == 0))
				return false;
		}
		return true;
	}
};


int main() {
	Solution ans;
	ans.hasAlternatingBits(5);
}