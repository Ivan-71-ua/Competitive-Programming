#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n;
	cin >> n;
	if(n == 1) {
		cout << 11;
	}
	else {
		int k;
		k = (n * n) - ((n - 2) * (n - 2)) + 1 + ((n + 4) * (n + 4) - (n + 2) * (n + 2)) - 7;
		cout << k;
	}
}