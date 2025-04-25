#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> plusOne(std::vector<int>& digits) {
		for (int i = digits.size() -1; i >=0; i--)
		{
			int res = digits[i] + 1;
			if(res < 10) {
				digits[i]++;
				break;
			} else {
				digits[i] = res % 10;
				if(i == 0)
					digits.insert(digits.begin(), 1);
			}
		}
		return digits;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{1, 2, 3};
	ans.plusOne(ss);
}