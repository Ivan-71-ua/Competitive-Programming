#include <iostream>

using namespace std;

int f(int n){
   if (n < 3) return n-1;
   int m = n-1;
   for (int i = 1; i < n-1; ++i) {
      m = min(m, max(i, f(n - i) + 1));
   }
   return m;
}

int main() {
   int n;  
   cin >> n;  
   cout << f(n);
   return 0;
}