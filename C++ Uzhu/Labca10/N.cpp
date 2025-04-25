#include <iostream>


long long Factorial(int start, int end) {
   if (start > end) return 1;
   return start * Factorial(start + 1, end);
}

long long BinomialCoefficient(int n, int k) {
   k = std::max(k, n - k);
   long long numerator = Factorial(k + 1, n);
   long long denominator = Factorial(2, n - k);
   return numerator / denominator;
}

int main() {
   int t;
   std::cin >> t;
   while (t--) {
      int n, k;
      std::cin >> n >> k;
      std::cout << BinomialCoefficient(n, k) << std::endl;
   }
}
