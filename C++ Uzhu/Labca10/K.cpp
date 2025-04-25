#include <bits/stdc++.h>
#define ll long long
std::map<long long, long long> fib;

long long HROZNY(long long n)
{
   if (n <= 1) return 1;
   if (n == 2) return 2;
   if (fib[n] != 0) return fib[n];
   long long k = n / 2;
   if (n % 2 == 0)
      return fib[n] = (HROZNY(k - 1) * HROZNY(k - 1) + HROZNY(k) * HROZNY(k)) % 10;
   return fib[n] = (HROZNY(k) * (HROZNY(k - 1) + HROZNY(k + 1))) % 10;
}

int main() {
	ll n;
	while(std::cin >> n) {
		std::cout << HROZNY(n) << "\n";
	}
	
}