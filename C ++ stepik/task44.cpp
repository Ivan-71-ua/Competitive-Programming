#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double N;
	cin >> N;
	cout << floor((N - floor(N)) * 10);
}