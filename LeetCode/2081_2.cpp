
#include <bits/stdc++.h>


class Solution {
public:
	long long createPalindrome(long long num, bool oddLength) {
		long long result = num;
		if (oddLength) num /= 10;
		while (num > 0) {
			result = result * 10 + (num % 10);
			num /= 10;
		}
		return result;
	}

	bool isPalindrome(long long num, int base) {
		std::vector<int> digits;

		while (num > 0) {
			digits.push_back(num % base);
			num /= base;
		}
		int size = digits.size();
		for (int i = 0; i < size / 2; i++) {
			if (digits[i] != digits[size - 1 - i]) {
				return false;
			}
		}
		return true;
	}

	long long kMirror(int k, int n) {
		long long sum = 0;
		for (long long len = 1; n > 0; len *= 10) {
			for (long long i = len; n > 0 && i < len * 10; i++) {
				long long p = createPalindrome(i, true);
				if (isPalindrome(p, k)) {
					sum += p;
					n--;
				}
			}
			for (long long i = len; n > 0 && i < len * 10; i++) {
				long long p = createPalindrome(i, false);
				if (isPalindrome(p, k)) {
					sum += p;
					n--;
				}
			}
		}
		return sum;
	}
};
