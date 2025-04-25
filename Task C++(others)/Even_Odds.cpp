	#include <bits/stdc++.h>
	using namespace std;


	int main() {
		long long n, k;
		cin >> n >> k;
		if(n % 2 == 0) {
			if(k > n / 2) {
				long long p = k - n / 2 ;
				cout << 2 + 2 * (p - 1);
			}
			else {
				long long p = k;
				cout << 1 + 2 * (p - 1);
			}
		}
		else {
			if(k > (n / 2) + 1) {
				long long p = k - ((n / 2) + 1);
				cout << 2 + 2 * (p - 1);
				}
			else {
				long long p = k;
				cout << 1 + 2 * (p - 1);
			}
		}
	}

