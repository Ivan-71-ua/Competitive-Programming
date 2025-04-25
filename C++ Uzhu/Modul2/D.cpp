#include <bits/stdc++.h>
#define ll long long


int main() {
   ll p, a, b;
   std::cin >> p >> a >> b;
   if ((p + a) - b < 0) 
		std::cout << p + a;
   else 
		std::cout << (p + a) - b;
}