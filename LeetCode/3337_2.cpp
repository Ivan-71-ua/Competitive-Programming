
#include <bits/stdc++.h>






const int ALPHABET_SIZE = 26;
const int MOD = 1000000007;

struct Mat {
   long long a[ALPHABET_SIZE][ALPHABET_SIZE] = {};  
};


Mat operator*(const Mat& lhs, const Mat& rhs) {
	Mat result;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		for (int j = 0; j < ALPHABET_SIZE; j++) {
			long long sum = 0;
			for (int k = 0; k < ALPHABET_SIZE; k++) {
				sum += 1LL * (lhs.a[i][k] * rhs.a[k][j]) % MOD;
			}
			result.a[i][j] = sum % MOD;
		}
	}
	return result;
}


Mat identityMatrix() {
	Mat result;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		result.a[i][i] = 1;
	}
	return result;
}

Mat matrixPower(Mat base, int exponent) {
	Mat result = identityMatrix();
	while (exponent > 0) {
		if (exponent & 1) {
			result = result * base;
		}
		base = base * base;
		exponent >>= 1;
	}
	return result;
}

class Solution {
public:
	int lengthAfterTransformations(std::string& s, int t, std::vector<int>& nums) {
		Mat transform;
		for (int from = 0; from < ALPHABET_SIZE; from++) {
			for (int offset = 1; offset <= nums[from]; offset++) {
				int to = (from + offset) % ALPHABET_SIZE;
				transform.a[to][from] = 1;
			}
		}

		Mat powered = matrixPower(transform, t);

		std::vector<int> freq(ALPHABET_SIZE, 0);
		for (char ch : s) {
			freq[ch - 'a']++;
		}

		long long totalLength = 0;
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			long long contribution = 0;
			for (int j = 0; j < ALPHABET_SIZE; j++) {
				contribution += 1LL * powered.a[i][j] * freq[j];
			}
			totalLength = (totalLength + contribution) % MOD;
		}

		return totalLength;
	}
};
