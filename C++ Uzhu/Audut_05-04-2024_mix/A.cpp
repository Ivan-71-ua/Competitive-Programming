#include <bits/stdc++.h>

bool IsPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i *i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int b, c;
	std::cin >> b >> c;
	int cnt = 0; 
	int a = b;  
	for (; ; a++) {
		if (IsPrime(a)) cnt++;
		if (cnt == c) break; 
	}
	std::cout << a << std::endl;
}
