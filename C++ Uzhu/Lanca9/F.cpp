#include <bits/stdc++.h>
using namespace std;



long long fac(long long k) {
	long long i, res = 1;
 	for(i = 1; i <= k; i++) res = res * i;
   return res;
}
	
	


int main() {
	long long n, k, c =0;
	cin >> n;
	k =fac(n);
	while(k % 10 == 0) {
		c++;
		k /= 10;
	}
	cout << c;
}