#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == ceil(n / 2.0)) {
				cout << "@";
			}
			else if (j < ceil(n / 2.0)) {
				cout << "\\";
			}
			else {
				cout << "/";
			}
		}
		cout << endl;
	}
}