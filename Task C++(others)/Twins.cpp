#include <bits/stdc++.h>
using namespace std;
int main() {
int n, d = 0;
  cin >> n;
  int a[n], i = 0;
  for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      d += a[i];
    }
  sort (a, a + n);
  while (d >= 0)
    {
      d -= 2 * a[n - i - 1];
      i++;
    }
  cout << i << endl;
 
}