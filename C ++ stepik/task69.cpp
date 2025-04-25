#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int n, m, max = 0, demo_max, x = 0, y = 0;
	cin >> n >> m;
	int vec[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			if (max == 0) {
				max = vec[i][j];
				x = i;
				y = j;
			}
			if (max < vec[i][j]) {
				max = vec[i][j];
				x = i;
				y = j;
			}
			else if (max == vec[i][j]) {
				continue;
			}
		}
	}
	cout << x << " " << y;
}