#include <bits/stdc++.h>


int main() {


   std::string t, l = ""; 
	std::cin >> t;
   for (char i : t){
      if (std::count(l.begin(), l.end(), i) >= 1) continue;
      std::cout << i;
      l += i;
   }
}