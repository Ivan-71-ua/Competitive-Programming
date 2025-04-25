#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, now, previously;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		previously = a[i - 1];
		now = a[i];
		if (now > previously) {
			cout << now << " ";
		}
	}
}