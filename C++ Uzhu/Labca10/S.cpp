#include <bits/stdc++.h>


long long p, q;

long long g(long long p)
{
   long long t = p % 10;
   if (p <= 0) return 0;
   return t * (1 + t) / 2 + p / 10 * 45 + g(p / 10);
}

long long s(long long p, long long q)
{
   return g(q) - g(p - 1);
}

int main() {
	while(std::cin >> p >> q && p > 0 && q > 0) {
	std::cout << s(p,q) << '\n';
	}
}
