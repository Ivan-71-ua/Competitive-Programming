#include <iostream>
#include <vector>
using namespace std;
int main () {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		for (auto now : a) {
			cout << now << " ";
	}
	}
	else if (n % 2 == 0 ) {
		for (int i = 0; i < n; i += 2) {
			int temp;
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
		for (auto now : a) {
			cout << now << " ";
		}
	}
	else if(n % 2 == 1) {
		for (int i = 0; i < n-1; i += 2) {
			int temp;
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		
		}
		for (auto now : a) {
			cout << now << " ";
		}
	}
}
