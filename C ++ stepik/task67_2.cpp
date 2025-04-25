#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n=8;

	vector <int> a(n);
	vector <int> b(n);
	//считывание
	for (int i = 0; i <n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++){
			if (i != j && (a[i] == a[j] || b[i] == b[j] || abs(a[i] - a[j]) == abs(b[i] - b[j]))) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}