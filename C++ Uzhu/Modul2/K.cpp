#include <bits/stdc++.h>
#define ll long long

int main() {
   ll p, q, k;
   std::cin >> p >> q >> k;
   k--;
   ll f=q-p;
   f *=k ;
   p += f;
   std::cout << p;
}