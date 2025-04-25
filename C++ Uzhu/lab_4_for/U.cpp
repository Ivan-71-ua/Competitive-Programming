#include <iostream>
#include<string>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int k = 1;
	while (pow(k, 3) < n)
	{
		cout << pow(k, 3) << " ";
		k++;
	}
}