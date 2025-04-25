#include <iostream>

using namespace std;

int main() {
	int a = 3, b = 3;
	bool c = !(a == b);
	int a1 = 3, b1 = 9;
	bool c1 = !(a > b);
	cout << c << " " << c1;
}