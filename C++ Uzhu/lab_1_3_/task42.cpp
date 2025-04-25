#include <iostream>
#include<string>
#include <cmath>
using namespace std;

int main() {
	int n;
	int k = 0;
	while (cin >> n && n != 0)
	{
		if(n % 2 !=  0) {
			k++;
		}
	}
	cout << k;
}