#include <iostream>

using namespace std;

int main() {
	int h, a, b, c;
	cin >> h >> a >> b;
	c = ((h - a) + (a - b) - 1) / (a - b) + 1;
	cout << c;
} 