#include <iostream>
#include <cmath>
//#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n;
	while(cin >> n && n != 0) {
		int sum = 0;
		if (n > 0) {
			for (int i = 1; i <= n; i++) {
			sum += i;
			}
		}
		else {
			for (int i = 1; i >= n; i--) {
			sum += i;
			}
		}
		
		cout << sum << endl;
	}
}