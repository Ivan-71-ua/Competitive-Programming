#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, a, b;
	int n1, n2, n3;
	cin >> n >> a >> b;
	n2 = n - a;
	n3 = n - b;
	n1 = n - n2 - n3;
	cout << n1 << " " << n2 << " " << n3;
}