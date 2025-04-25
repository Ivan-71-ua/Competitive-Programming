#include <bits/stdc++.h>
#define ll long long

ll cBinary(ll num) {
   ll count = 0;
   while (num != 0) {
		count += (num & 1);
      num >>= 1;
   }
   return count;
}


ll Binary(ll n) {
	if(n == 1) {
		return 1;
	}
   if(n&1)
		return 2 * Binary(n / 2) + (n + 1) / 2;
	return Binary(n - 1) + cBinary(n);
	
}

int main() {
	ll a, b, k = 1;
	while (std::cin >> a >> b && a != 0 && b != 0)
	{
		std::cout << "Case " << k << ": " << Binary(b)  - Binary(a-1) << '\n';
		k++;
	}
	
}
