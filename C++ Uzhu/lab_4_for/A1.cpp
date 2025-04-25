#include <iostream>
//#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	long long n, sum = 0, k = 1;
	cin >> n;
	while(n != 0) {
		long long c;
		c = n % 10;
		n = n / 10;
		if (c % 2 != 0) {
			c--;
			sum += k * c;
			k *= 10;
		}
		else if (c % 2 == 0) {
			c++;
			sum += k * c;
			k *= 10;
		}
		
	}
	
	cout << sum;
	
}