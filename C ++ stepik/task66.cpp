#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
   int count=0, n, k;
   cin >> n;
   vector <int> a(n);
   for (int i = 0; i < n; i++) cin >> a[i];
   for (int i = 0; i < n; i++) {
   k = 0; 
   for (int j = 0; j < n; j++) {
      if (a[j] == a[i] && i != j) k++;
   } 
   if (k == 0) cout << a[i] << " ";
   } 
   return 0;
}
