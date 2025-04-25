#include <iostream>
#include <cmath>
//#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n, sum = 0, k = 0;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int c;
		cin >> c;
		if(c % 6 == 0 && c > 0) {
			sum += c;
			k++;
		}
	}
	cout << k << " " << sum;
}