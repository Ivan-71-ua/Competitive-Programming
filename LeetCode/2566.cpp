#include <bits/stdc++.h>



class Solution {
public:
	int minMaxDifference(int num) {
		std::string s = std::to_string(num);
		char maxDigit = '9';
		for (char c : s) {
			if (c != '9') {
				maxDigit = c;
				break;
			}
		}
		char minDigit = s[0]; 
		int maxn = 0, minn = 0;
		for (char c : s) {
			maxn = maxn * 10 + (c == maxDigit ? 9 : (c - '0'));
			minn = minn * 10 + (c == minDigit ? 0 : (c - '0'));
		}
		
		return maxn - minn;
	}
};

int main() {
Solution sol;
sol.minMaxDifference(456);

}