#include <iostream>
#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n, temp;
	int k = 0;
	cin >> n;
	
	for (int i = n; i > sqrt(n); i -= 2) {
		if(n % i == 0 && n != i) {
			cout << i;
			k++;
			break;
		}
	}
	if(k == 0) {
		cout << 1;
	}
}