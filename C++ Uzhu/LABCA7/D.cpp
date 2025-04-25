#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,  k = 0;
	cin >> n;
	while(!(n & 1)) {
		n = n >> 1;
		k++;
	}
	cout  << (1 << k);
}