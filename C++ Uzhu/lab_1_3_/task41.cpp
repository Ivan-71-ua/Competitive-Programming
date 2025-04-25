#include <iostream>
#include<string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int k = 2;
	while (k < n)
	{
		k = k * 2;
	}
	cout << k / 2;
}