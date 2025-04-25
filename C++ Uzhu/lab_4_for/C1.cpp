#include <iostream>
#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	long long n;
	int temp = 0;
	cin >> n;
	for (int i = n - 1; i >= sqrt(n); i--) {
		if(n % i == 0) {
			cout << i;
			temp++;
			break;
		}
	}
	if (temp == 0) {
		cout << 1;
	}
}