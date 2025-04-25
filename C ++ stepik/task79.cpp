#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int n, m, max, diagonale = 0,count = 1;
	cin >> n >> m;
	max = n * m;
	int vec[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vec[i][j] = 0;
		}
	}
	while (diagonale < n + m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + j == diagonale) {
					vec[i][j] = count;
					count++;
				}
			}
		}
		diagonale++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << vec[i][j];
		}
		cout << endl;
	}
}