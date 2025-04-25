#include <bits/stdc++.h>



int main() {
   int m, n, a, b, k;
   std::cin >> m >> n >> a >> b >> k;
   std::vector<std::vector<bool>> isRadioactive(m + 1, std::vector<bool>(n + 1, false));
   for (int i = 0; i < k; ++i) {
      int x, y;
      std::cin >> x >> y;
      isRadioactive[x][y] = true;
   }
   int count = 0;
   for (int i = 1; i <= m - a + 1; ++i) {
      for (int j = 1; j <= n - b + 1; ++j) {
            bool canPlace = true;
            for (int x = i; x < i + a; ++x) {
               for (int y = j; y < j + b; ++y) {
                  if (isRadioactive[x][y]) {
                     canPlace = false;
                     break;
                  }
               }
               if (!canPlace) {
                  break;
               }
            }
            if (canPlace) {
               count++;
            }
      }
   }
   std::cout << count << std::endl;
}
