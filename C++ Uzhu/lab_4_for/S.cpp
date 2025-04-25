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
		cout << k << " ";
		k = k * 2;
	}
}