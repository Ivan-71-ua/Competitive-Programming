#include <bits/stdc++.h>

void Cells(int N) {
   for (int i = 1; i <= N; ++i) {
      std::cout << i << ' ';
      if (i < N && i > 1) {
         std::cout << '-' << i - 1 << ' ';
      }
   }
   if (N > 2) {
      Cells(N - 2);
   }
}

int main() {
   int N;
   std::cin >> N;
   Cells(N);
   std::cout << std::endl;
}


