#include <iostream>
#define ll long long


ll cat[10001];

ll calculateCatalan(ll n, ll m) {
   if (n == 0) {
      return 1;
   }
   ll result = 0;
   for (ll j = 0; j < n; j++) {
      result = (result + calculateCatalan(j, m) * calculateCatalan(n - j - 1, m)) % m;
   }
   return result;
}

int main() {
   ll n, m;
   std::cin >> n >> m;
   cat[0] = 1;
   for (ll i = 1; i <= n; i++) {
      cat[i] = calculateCatalan(i, m);
   }
   std::cout << cat[n] << std::endl;
}
