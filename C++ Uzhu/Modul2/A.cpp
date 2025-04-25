#include <bits/stdc++.h>



int main() {
   double a, b;
   int n, p; 
	std::cin >> a >> n >> p;
   for (int i = 0; i < n; i++){
      b = sqrt(((a/2.0)*(a/2.0)) * 2);
      a = b;
   }
   if ( p == 1) {
		std::cout << (int)(b * b);
	}
   else {
		std::cout <<(int) (b * 4); 
	}
}