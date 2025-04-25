#include <iostream>
#define ll long long


ll c[10001] {};

ll calculateC(ll i, ll j) {
   if (j < 0) return 0;
   return c[j] * c[i - j - 1] + calculateC(i, j - 1) ;
}

ll HROZNY(ll i, ll n, ll m) {
   if (i > n) return c[n];
   if (i > 0 && i < n + 1) {
      c[i] = calculateC(i, i - 1) % m;
   }
   return HROZNY(i + 1, n, m);
}

int main() {
   c[0] = 1;
   ll n, m;
   std::cin >> n >> m;
   std::cout << HROZNY(1, n, m);	
}
