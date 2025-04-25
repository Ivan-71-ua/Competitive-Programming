#include <bits/stdc++.h>
using namespace std;

int c(int k, int n){	
	if (n == k) return 1;
   if (k == 0) return 1;
   return c(k - 1, n - 1) + c(k, n - 1);
}



int main() {
	int k;
	cin >> k;	
	int res = 0;
	for (int i = 0; i <= k; i++)
	{
		if(i > k -i) {
			res += c(k - i, k);
		}
		else {
			res += c(i, k);
		}
		
	}
	cout << res;
}