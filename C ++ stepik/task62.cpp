#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, resent = -1, quantity = 1;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (resent == -1) {
			resent = a[i];
		}
		if (resent != a[i]) {
			quantity++;
			resent = a[i];
		}
	}
	cout << quantity;
}