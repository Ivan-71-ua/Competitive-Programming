#include <iostream>
#include <vector>
using namespace std;
int main () {
	int n, temp, temp1, quantityty = 0;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		temp = a[i];
		for (int j = i + 1; j < n; j++) {
			temp1 = a[j];
			if (temp == temp1) {
				quantityty += 1;
			}
		}
	}
	cout << quantityty;
}
