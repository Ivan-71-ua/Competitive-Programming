#include <bits/stdc++.h>



int main() {
   int f =0, l=0, k=0, p=0, n;
   std::cin >> n;
   int m[n];
   for (int i =0; i < n; i++){
      std::cin >> m[i];
   }
   for (int i : m) {
      if( i >= 10) f++;
      else if (i >=7) l++;
      else if( i >=4) k++;
      else p++;
   }
   std::cout << f << " " << l << " " << k << " " << p;
}