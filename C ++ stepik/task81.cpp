#include <iostream>
#include <iomanip>

using namespace std;

int main() {
   int n, m, i = 0, j = -1;
   //cin >> n >> m;
	n = 3;
	m = 4;
	
	int a[n][m], max = n * m;
   
   for (int c = 1, d = 0; c <= max; d++) {
      while (j < m - 1 - d && c <= max) {
         a[i][++j] = c++;
      }
      
      while (i < n - 1 - d && c <= max) {
         a[++i][j] = c++;
      }
      
      while (j > d && c <= max) {
         a[i][--j] = c++;
      }
      
      while (i > d + 1 && c <= max) {
         a[--i][j] = c++;
      }
   }

   for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
         cout << setw(4) << a[i][j];
      }
      cout << endl;
   }
}