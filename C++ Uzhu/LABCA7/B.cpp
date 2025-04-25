#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,  k = 0;
	cin >> n;
	while(n != 0) {
		if((n & 1)) {
			k++;
			n = n >> 1;
		}
		else {
			n = n >> 1;
		}
	}
	cout  << k;
}