#include <iostream>
using namespace std;

int main() {
   int t;
   cin >> t;
   while(t--) {   
      __int64 n, k;
      cin >> n >> k;
      k = max(k, n - k);
      long long r = 1;
      for (__int64 i = k + 1; i <= n; ++i) {
         r *= i;
      }
      for (__int64 i = 2; i <= n - k; ++i) {
         r /= i;
      }
      cout << r << endl;
   }
}
