#include <iostream>

#include <cstdlib>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ( b <= c) {
		cout << c - b;
	}
	else if (b > c) {
		cout << (c - b + a) % a;
	}
}