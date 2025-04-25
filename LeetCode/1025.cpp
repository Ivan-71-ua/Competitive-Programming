#include <bits/stdc++.h>

	class Solution {
	public:
		bool divisorGame(int n) {
		if(n % 2 == 0)
			return 0;
		else {
			return 1;
		}
	}
};

int main() {
	Solution ans;
	ans.divisorGame(3);
}