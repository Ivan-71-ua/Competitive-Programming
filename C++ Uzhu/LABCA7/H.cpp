#include <bits/stdc++.h>
using namespace std;


int main() {
   int k; cin >> k;
   while (k--){
      long long a, n, b = 0; cin >> a >> n;
      if (a % n == 0) {
         cout << 0 << "\n";
         continue;
      }
      while ((a^b) % n != 0){
         b++;
      }
      cout << b << "\n";
   }
}