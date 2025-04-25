#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int n, m, k,min = 0, temp, quantity = 0;
	bool look = false;
	cin >> n >> m;
	int vec[n][m];
	vector <int> vec_ansver;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}
   cin >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec[i][j] == 0) {
				quantity++;
			}
			if (vec[i][j] == 1) {
				quantity = 0;
			}
			if (quantity == k) {
				temp = i + 1;
				look = true;
				vec_ansver.push_back(temp);
				temp = 0;
				quantity = 0;
			}
		}
		quantity = 0;
	}
	if (look == true) {
		for (int i = 0; i < vec_ansver.size(); i++) {
			if (min == 0) {
				min = vec_ansver[i];
			}
			if (min > vec_ansver[i]) {
				min = vec_ansver[i];
			}
		}
		cout << min;
	}
	else if (look == false) {
		cout << 0;
	}
}