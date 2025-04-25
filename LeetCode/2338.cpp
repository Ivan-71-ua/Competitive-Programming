

#include <bits/stdc++.h>


const int mod = 1e9 + 7;
int factMemo[100000] = {};
int dp[100000][15];
class Solution {
public:
long long power(long long a, long long b, long long m = mod) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a) % m;
		a = (a * a) % m;
		b = b >> 1;
	}
	return res;
}

long long fact(long long n) {
	if (n == 0) return 1;
	if (factMemo[n]) return factMemo[n];
	factMemo[n] = (n * fact(n - 1)) % mod;
	return factMemo[n];
}

long long mod_inv(long long a, long long b) {
	return (((fact(a) * power(fact(b), mod - 2)) % mod) * power(fact(a - b), mod - 2)) % mod;
}

int idealArrays(int n, int maxi) {
	for (int i = 1; i <= maxi; i++) {
		for (int j = 1; j <= std::min(n, 14); j++) {
			dp[i][j] = 0;
		}
	}
	
	for (int i = 1; i <= maxi; i++) {
		dp[i][1] = 1;
		for (int j = 2; j * i <= maxi; j++) {
			for (int k = 1; k < std::min(n, 14); k++) {
				dp[i * j][k + 1] += dp[i][k];
			}
		}
	}
	
	long long res = 0;
	for (int i = 1; i <= maxi; i++) {
		for (int j = 1; j <= std::min(n, 14); j++) {
			res = (res + mod_inv(n - 1, n - j) * dp[i][j]) % mod;
		}
	}
	return res;
} 
};
