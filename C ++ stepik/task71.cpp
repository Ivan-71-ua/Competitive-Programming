#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int n, temp;
	cin >> n;
	int vec[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				vec[i][j] = 0;
			}
			else if(i != j) {
				temp = abs(i - j);
				vec[i][j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}