#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long k = 1;
	while(n != 1) {
		if(n&1 == 1) {
			k++;
		}
		n = n >> 1;
	}
	cout << k;
}