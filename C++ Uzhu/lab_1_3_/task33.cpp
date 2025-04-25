#include <iostream>
#include<string>
#include <cmath>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if(n > 0) {
		while(1) {
			n--;
			if (n % 11 == 0) {
				cout << n;
				break;
			}
		}
	}
	else {
		while(1) {
				n--;
				if (n % 11 == 0)
				{
					cout << n;
					break;
			}
		}
	}
}