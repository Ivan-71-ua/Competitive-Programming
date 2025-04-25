#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int k = ceil((1 + 2 * n) / 2.0);
	for (int i = 1; i <= 1 + 2 * n; i++)
	{
		for (int j = 1; j <= 1 + 2 * n; j++)
		{
			if (i == k || j == k) {
				cout << "*";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
	
}