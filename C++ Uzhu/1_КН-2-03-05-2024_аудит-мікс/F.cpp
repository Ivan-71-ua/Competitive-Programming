#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


long long factorial(int n) {
	long long result = 1;
	for (int i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}


long long combination(int n, int k) {
	if (k > n) {
		return 0; 
	}
	if (k == 0 || k == n) {
		return 1;  
	}
	long long num = factorial(n);  
	long long denom = factorial(k) * factorial(n - k); 
	return num / denom;  
}

int main() {
	fast
	int n, k;
	std::cin >> n >> k;
	std::cout << combination(n, k) << std::endl;
	return 0;
}
