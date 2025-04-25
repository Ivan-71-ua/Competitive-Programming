#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long temp = (a + b + c) / 2;
	if (a + b == c || a + c == b || b + c == a) {
		cout << 0;
	}
	else if (temp < a) {
		cout << 1 << endl;
		cout << temp << " " << a - temp;
	}
	
	else if (temp < a + b) {
		cout << 2 << endl;
		cout << temp - a << " " << a + b - temp;
	}
	else if(a + b < temp) {
		cout << 3 << endl;
		cout << temp - a - b << temp;
	}
	else {
		cout << -1;
	}
}