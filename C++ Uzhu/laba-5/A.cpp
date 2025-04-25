#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	char ch;
	cin >> ch >> n;
	int L = n, R = n;
	cout << ((n - 1)* n) / 2 + n * n << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= R; j++)
		{
			if(j >= L && j <= R) {
				cout << ch;
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
		L--;
		R++;
	}
	

}