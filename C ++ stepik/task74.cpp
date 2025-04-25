#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n;
	int vec[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}
	cin >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (k > 0) {
				if(abs(i - j) == k && i > j) {
					cout << vec[i][j] << " ";
				}
			}
			if (k < 0) {
				if(abs(i - j) == -k && i < j) {
					cout << vec[i][j] << " ";
				}
			}
			if (k == 0) {
				if(abs(i - j) == 0) {
					cout << vec[i][j] << " ";
				}
			}
		}
	}
}