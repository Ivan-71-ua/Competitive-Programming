#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

std::map<int, int> fibon;

int Get_finon(int n) {
	if (n == 0 || n == 1) return 1;
   if (n == 2) return 2;
   if (fibon[n] != 0) return fibon[n];
   int k = n / 2;
   if (n % 2 == 0)
   return fibon[n] = (Get_finon(k - 1) * Get_finon(k - 1) + Get_finon(k) * Get_finon(k)) % 10;
   return fibon[n] = (Get_finon(k) * (Get_finon(k - 1) + Get_finon(k + 1))) % 10;
	}


int32_t main()
{
	fast;
	int a;
	while (std::cin >> a)
	{
		int res = Get_finon(a);
		std::cout << res << '\n';
	}
}
