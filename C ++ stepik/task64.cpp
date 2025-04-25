#include <iostream>
#include <vector>
using namespace std;
int main () {
	int n, last = -1, temp1, temp2,temp3;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << a[0] << " ";
	}
	for (int i = 0; i < n - 1; i++) {
		if (last == -1) {
			cout << a[n - 1] << " ";
			last = 1;
		}
		cout << a[i] << " ";
	}
}
