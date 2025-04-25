#include <iostream>
#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n, temp, k = 0;
	cin >> n;
	if (n % 2 == 0) {
		temp = 2;
	}
	else {
		temp = 3;
	}
	for (int i = temp; i <= sqrt(n); i += 2) {
		if(n % i == 0) {
			k++;
			break;
		}
	}
	if (k == 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}