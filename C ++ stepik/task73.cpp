#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int n, temp = 0;
	cin >> n;
	int vec[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (vec[i][j] != vec[j][i]) {
					temp++;
				}
			}
		}
	}
	if (temp == 0) {
			cout << "YES";
	}
	else {
			cout << "NO";
	}
	
}