#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long x, a, b, c;
	cin >> x;
	a = x % 10;
	x = x / 10;
	b = x % 10;
	c = x / 10;
	bool v = (a != b && b != c && a != c);
	if (v)  {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
}
