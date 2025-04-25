#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b;
	long long sum_b, sum_a, sum_a_b;
	cin >> a >> b;
	if (a >= 0 && b >= 0) {
		if (a % 2 != 0) {
			a--;
		}
		if(b % 2 != 0) {
			b--;
		}
		sum_b = (b / 2) * ((b / 2) + 1);
		if (a > 2) {
			sum_a = ((a - 2) / 2) * (((a - 2) / 2) + 1);
		}
		else{
			sum_a = 0;
		}
		sum_a_b = sum_b - sum_a;
		cout << sum_a_b;
	}
	else if (a < 0 && b <= 0) {
		int i = -1;
		a = abs(a);
		b = abs(b);
		swap(a, b);
		if (a % 2 != 0) {
			a--;
		}
		if(b % 2 != 0) {
			b--;
		}	
		sum_b = (b / 2) * ((b / 2) + 1);
		if (a > 2) {
			sum_a = ((a - 2) / 2) * (((a - 2) / 2) + 1);
		}
		else{
			sum_a = 0;
		}
		sum_a_b = sum_b - sum_a;
		cout << sum_a_b * i;
	}
	if (a < 0 && b >= 0) {
		a = abs(a);
		if (a % 2 != 0) {
			a--;
		}
		if(b % 2 != 0) {
			b--;
		}
		sum_b = (b / 2) * ((b / 2) + 1);
		if (a > 2) {
			sum_a = (a / 2) * ((a / 2) + 1);
		}
		else{
			sum_a = 0;
		}
		sum_a_b = sum_b - sum_a;
		cout << sum_a_b;
	}
}