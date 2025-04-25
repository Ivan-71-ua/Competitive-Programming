#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long n;
	cin >> n;
	int k = 1;
	int c = 0;
	while (k * k <= n)
	{
		cout << k * k << " ";
		k++;
	}
}