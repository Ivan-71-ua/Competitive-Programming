#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int n, m, x, y, temp;
	cin >> n >> m;
	int vec[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}
	cin >> x >> y;
	int step = 0;
	while  (step < n) {
		temp = vec[step][x];
		vec[step][x] = vec[step][y];
		vec[step][y] = temp;
		step++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}
