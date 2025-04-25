#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	while(1) {
		int k, a, b, c, d;
		n++;
		k = n;
		d = k % 10;
		k = k / 10;
		c = k % 10;
		k = k / 10;
		b = k % 10;
		k = k / 10;
		a = k % 10;
		k = k / 10;
		if(a != b && b != c && c != d && a != c && a != d && b != d) {
			cout << n;
			break;
		}
	}
}