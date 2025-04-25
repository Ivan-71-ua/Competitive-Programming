#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double N, X, coefisient, resoult, demo_coefisient;
	//cin >> fixed >> setprecision(3);
	cin >> N >> X >> coefisient;
	demo_coefisient = coefisient;
	cin >> coefisient;
	resoult = demo_coefisient * X + coefisient;
	N -= 1;
	if (N <= 0) {
		if (resoult - (int) resoult != 0) {
			cout << fixed << resoult; }
		else { 
			cout << (int) resoult; }
	}
	else {
		while ( N > 0) {
			cin >> coefisient;
			resoult = resoult * X + coefisient;
			N -= 1;
		}
		if (resoult - (int) resoult != 0) {
			cout << fixed << resoult; }
		else { 
			cout << (int) resoult; }
	}
}