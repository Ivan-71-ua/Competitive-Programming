#include <iostream>
#include<string>
#include <cmath>
using namespace std;
int main() {
	long long a;
	cin >> a;
	while(1) {
		a--;
		if( a % 5 == 0) {
			cout << a;
			break;
		}
	}
}