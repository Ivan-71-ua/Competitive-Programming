#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long k = (long long)sqrt(n);
	k++;
	cout << k * k;

}