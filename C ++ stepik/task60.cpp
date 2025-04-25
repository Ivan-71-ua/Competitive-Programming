#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, min = 0;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			if (min == 0) {
				min = a[i];
			}
			if (a[i] < min) {
				min = a[i];
			}
		}
	}
	cout << min;
}