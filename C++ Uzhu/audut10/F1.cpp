


#include <bits/stdc++.h>
using namespace std;

int Cnk(int k, int n){
   long long res = 1;
   if (k > n - k) k = n - k;
   for (int i = 1; i <= k; i++)
      res = res * (n - i + 1) / i;
   return (int)res;
}

int main() {
	int n;
	cin >> n;
	long long res = 0;
	for (int i = 0; i <= n; i++)
	{
		res += Cnk(i, n);
	}
	cout << res;
}