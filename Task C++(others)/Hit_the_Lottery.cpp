#include <bits/stdc++.h>
using namespace std;




int main()
{
	int n, k = 0;
	cin >> n;
	if(n >= 100) {
		k += n / 100;
		n -= (n / 100) * 100;
	}
	if(n >= 20) {
		k += n / 20;
		n -= (n / 20) * 20;
	}
	if(n >= 10) {
		k += n / 10;
		n -= (n / 10) * 10;
	}
	if(n >= 5) {
		k += n / 5;
		n -= (n / 5) * 5;
	}
	if(n >= 1) {
		k += n / 1;
		n -= n / 1;
	}
	cout << k;
}