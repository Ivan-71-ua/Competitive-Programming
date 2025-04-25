#include <iostream>


long long bC(int n, int k) {
   if (k == 0 || k == n) {
      return 1;
   } else {
      return bC(n - 1, k - 1) + bC(n - 1, k);
   }
}

int main() {
   int n;
   std::cin >> n;
   long long result = bC(n, 4);
   std::cout  << result << std::endl;
}
