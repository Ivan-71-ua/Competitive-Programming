#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

int main() {
   int t;
   cin >> t;
   while (t--) {
      long long n, m;
      cin >> n >> m;
      long long arr[n * m];
      for (long long i = 0; i < n * m; i++) {
         cin >> arr[i];
      }
      long long ind = 0;
      long long brr[n][m];
      sort(arr, arr + n * m);
      for (long long i = 0; i < m; i++) {
         long long ii = i;
         for (long long j = 0; j < n && ii >= 0; j++) {

               brr[j][ii] = arr[ind];
               ind++;
               ii--;

         }

      }
      for (long long i = 1; i < n; i++) {
         long long ii = i;
         for (long long j = m - 1; j >= 0 && ii < n; j--) {
               brr[ii][j] = arr[ind];
               ind++;
               ii++;
         }
      }
      // cout << "***" << endl;
      // for (long long i = 0; i < n; i++) {
      //     for (long long j = 0; j < m; j++) {
      //         cout << brr[i][j] << " ";
      //     }
      //     cout << endl;
      // }
      // cout << "***" << endl;
      int ch = 0;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m - 1; j++) {
               //cout << brr[i][j] << " " << brr[i][j + 1] << endl;
               if (brr[i][j] >= brr[i][j + 1]) ch = 1;
         }
      }
      //cout << "***" << endl;
      for (int j = 0; j < m; j++) {
         for (int i = 0; i < n - 1; i++) {
               //cout << brr[i][j] << " " << brr[i + 1][j] << endl;
               if (brr[i][j] >= brr[i + 1][j]) ch = 1;
         }
      }
      //cout << "***" << endl;
      if (ch == 0) {
         cout << "YES" << endl;
         for (int i = 0; i < n; i++) {
               for (int j = 0; j < m; j++) {
                  cout << brr[i][j] << " ";
               }
               cout << endl;
         }
      }
      else {
         cout << "NO" << endl;
      }
   }
}
