#include <bits/stdc++.h>
#define ll long long

long long mas[32][32] {};
ll k;
long long f(int n, int m)
{
   if (n == 0) return 1;
   if (n < 0 || m == 0) return 0;
   if (m * k < n) return 0;
   if (mas[n][m] != 0) return mas[n][m];
	long long res = 0;
   for(int i = 0; i <= k; i++)
      res = res + f(n-i,m-1);
   return mas[n][m] = res;
}

int main() {
	ll n, m;
	std::cin >> n >> m >> k;
	std::cout << f(n, m);
}
