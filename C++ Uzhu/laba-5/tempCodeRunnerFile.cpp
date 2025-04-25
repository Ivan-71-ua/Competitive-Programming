#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int k = n;
	int k1 = 2;
	int k2 = ceil((2 * n - 1) / 2.0);
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i <= k2) {
				if(j == k ) {
					cout << "<";
					k--;
				}
				
				else {
					cout << " ";
				}
			}
			else if (i > k2) {
				if (k1 > 5) {
					k1 = k1 - n;
				}
				if (k1 == j && k1 <= n) {
					cout << "<";
				}
				else {
					cout << " ";
				}
			}
			
		}
		k1++;
		cout << endl;
	}
}
