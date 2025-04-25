#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a;
	cin >> a;
	if (a == (int)sqrt(a) * (int)sqrt(a)) {
		cout << sqrt(a);
	}
	else {
		cout << "No";
	}
}