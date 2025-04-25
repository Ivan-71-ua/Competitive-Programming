#include <iostream>

using namespace std;

int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	if ( n1 > n2 ) {
		if (n1 > n3) {
			if (n2 + n3 > n1) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
		else {
			if (n1 + n2 > n3) {
				cout << "YES";
			}
			else {
				cout << " NO";
			}
		}
	}
	else {
		if (n2 > n3) {
			if (n1 + n3 > n2) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
		else {
			if (n1 + n2 > n3) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
	}
	
} 