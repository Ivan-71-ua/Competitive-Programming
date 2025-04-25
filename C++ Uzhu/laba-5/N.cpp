#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int k = n - 1;
	int k2 = ceil((2 * n - 1) / 2.0);

	for (int i = 1; i <= 2 * n - 1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i <= k2) {
				if (j == 1 || i == j) {
					cout << "*";
				}
				else {
					cout << " ";
				}
			}
			else if (i > k2) {
				if(j == 1 || j == k && k != 1) {
					cout << "*";
					if (j == k) {
						k--;
					}
				}
				
				else {
					cout << " ";
				}
			}
		}
		
		cout << endl;
	}
}