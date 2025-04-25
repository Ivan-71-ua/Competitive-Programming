#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int n, m, max = 0, timer = 1, temp = 0;
	cin >> n >> m;
	int vec[n][m];
	max = n * m;
   for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vec[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				vec[i][j] = timer;
				timer++;
			}
		}
		else if( i % 2 != 0) {
			for (int j = m - 1; j >= 0; j--) {
				vec[i][j] = timer;
				timer++;
			}
		}
	
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << vec[i][j];
		}
		cout << endl;
	}
}