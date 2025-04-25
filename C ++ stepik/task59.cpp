#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i ++) {
		if (a[i - 1] > 0 && a[i] > 0 || a[i - 1] < 0 && a[i] < 0) {
			if (a[i - 1] < a[i]) {
				cout << a[i - 1] << " " << a[i];
				break;
			}
			else {
				cout << a[i] << " " << a[i - 1];
				break;
			}
		}
	}
}