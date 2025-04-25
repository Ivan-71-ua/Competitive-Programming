#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	int sum = 0;
	int k = 0;
	cin >> n;
	for (int i = 0; i < n * n;i++) {
		int c;
		cin >> c;
		if(c < 0 && c % 2 == 0) {
			sum += c;
			k++;
		}
	}
	cout << k << " " << sum;
}