#include <iostream>

using namespace std;

int main() {
   int n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;
	if (n3 - n1 > 1 ||  n4 - n2 > 1) {
		cout << "NO";
	}
	else if (n3 - n1 < -1 ||  n4 - n2 < -1) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}

}
