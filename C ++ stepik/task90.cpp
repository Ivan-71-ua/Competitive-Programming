#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int Sum_REC() {
	int n;
	cin >> n;
	if (n == 0) {
		return 0;
	}
	return n + Sum_REC();
}

int main() {
	cout << Sum_REC();
}