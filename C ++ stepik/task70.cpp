#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int vec[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				cout << "* ";
			}
			else if ((i + 1) == (n/ 2) + 1) {
				cout << "* ";
			}
			else if ((j + 1) == (n/ 2) + 1) {
				cout << "* ";
			}
			else if ((i + j) == (n - 1)) {
				cout << "* ";
			}
			else {
				cout << ". ";
			}
		}
		cout << endl;
	}
}