#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int k;
	double n;
	double milk = 0;
	int asses = 0;
	cin >> k;
	while(k--) {
		cin >> n;
		if(n < 30) {
			asses++;
			milk = milk + 0.2;
		}
	}
	cout << ceil(milk / 0.9) << " " << asses;
}