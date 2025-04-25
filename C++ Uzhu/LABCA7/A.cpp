#include <bits/stdc++.h>
using namespace std;


int main() {
   int n, k, an = 0;
	cin >> n;
   int x = 1;
   k = n;
   while ((x<<1) <= n){
      x = x<<1;
   }
   do{
      if(k&1) {
         k = k>>1;
         k = k^x;
      } else k = k>>1;
      if ( an < k) an = k;
   } while (k != n);
   cout << an;
}