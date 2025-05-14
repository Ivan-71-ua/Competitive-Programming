#include <bits/stdc++.h>



using ll = long long;

class Solution {
public:
	const int mod = 1e9 + 7;
	std::vector<std::vector<ll>> multiplyMatrices(const std::vector<std::vector<ll>> &A, const std::vector<std::vector<ll>> &B) {
		int rowsA = A.size();
		int colsA = A[0].size();
		int colsB = B[0].size();
		std::vector<std::vector<__int128_t>> temp(rowsA, std::vector<__int128_t>(colsB, 0));
		std::vector<std::vector<ll>> result(rowsA, std::vector<ll>(colsB, 0));
		for (int i = 0; i < rowsA; ++i) {
			for (int j = 0; j < colsB; ++j) {
				for (int k = 0; k < colsA; ++k) {
					temp[i][j] += (__int128_t)A[i][k] * B[k][j];
				}
				result[i][j] = temp[i][j] % mod;
			}
		}
		return result;
	}


	std::vector<std::vector<ll>> powerMatrix(std::vector<std::vector<ll>> matrix, ll exponent) {
		int n = matrix.size();
		std::vector<std::vector<ll>> result(n, std::vector<ll>(n, 0));
		for (int i = 0; i < n; ++i) {
			result[i][i] = 1;
		}
		while (exponent > 0) {
			if (exponent % 2 == 1) {
				result = multiplyMatrices(result, matrix);
			}
			matrix = multiplyMatrices(matrix, matrix);
			exponent /= 2;
		}
		return result;
	}


	int lengthAfterTransformations(std::string s, int t, std::vector<int>& nums) {
		std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);      
	std::cout.tie(nullptr);
		std::vector<std::vector<ll>> transform(26, std::vector<ll>(26, 0));
		for (int i = 0; i < 26; ++i) {
			for (int shift = 0; shift < nums[i]; ++shift) {
				int target = (i + 1 + shift) % 26;
				transform[i][target]++;
			}
		}
		transform = powerMatrix(transform, t);
		std::vector<std::vector<ll>> freq(1, std:: vector<ll>(26, 0));
		for (char ch : s) {
			freq[0][ch - 'a']++;
		}
		freq = multiplyMatrices(freq, transform);
		int totalLength = 0;
		for (int count : freq[0]) {
			totalLength += count;
			if (totalLength >= mod) totalLength -= mod;
		}
		return totalLength;
	}
};
