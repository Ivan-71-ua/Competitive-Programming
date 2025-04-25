#include <bits/stdc++.h>
#define ll long long


int main() {
   std::string l, f;
   std::cin >> l >> f;
   ll s = 1, s1 = 1;
   for (char i : l){
        s *= (i - 64);
   }
   for (char i : f){
      s *= (i - 64);
   }
   if ( s % 47 == s1 % 47) std::cout << "GO";
   else std::cout << "STAY";
}