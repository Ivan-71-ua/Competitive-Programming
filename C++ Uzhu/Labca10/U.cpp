#include <bits/stdc++.h>
#define ll long long
int f(int n, int k)
{
   if (!n) return 0;
   int tem = 1 << (n-1);
   if (k < tem) return f(n-1,k);
   return tem + f(n-1, (1 << n) - 1 - k);
}

int main() {
	int t;
	std::cin >> t;
	while (t--)
	{
		ll n, k;
		std::cin >> n >> k;
		std::cout << f(n, k) << '\n';
	}
	
}