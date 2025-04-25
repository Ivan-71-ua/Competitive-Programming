#include <bits/stdc++.h>

int fib[46] {};


int HROZNY(int n) {
	if (n <= 1) return 1;
   if (fib[n] != 0) return fib[n];
   return fib[n] = HROZNY(n-1) + HROZNY(n - 2);
}

int main()
{
	int k;
	std::cin >> k;
	std::cout << HROZNY(k);
}