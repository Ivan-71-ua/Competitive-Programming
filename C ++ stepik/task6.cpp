#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a;
	b = a + (a / ((a + 1) / 2));
	cout << b;

	return 0;
}