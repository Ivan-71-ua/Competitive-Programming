#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k= 0;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		sum += c;
		k++;
	}
	cout << sum / k;
}