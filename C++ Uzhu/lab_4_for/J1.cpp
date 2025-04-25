#include <iostream>
#include <cmath>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	long long n;
	int temp = 2;
	cin >> n;
	while(n != 1) {
		if(n % temp == 0) {
			cout << temp << "\n";
			n /= temp;
		}
		else{
			temp++;
		}
	}
}