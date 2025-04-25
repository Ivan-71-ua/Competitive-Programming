#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int k = 1, k2 = 2 * n - 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (j == k || j == k2) {
				cout << "@";
			}
			else if (j < k || j > k2) {
				cout << "|";
			}
			else  {
				cout << " ";
			}
		}
		k++;
		k2--;
		cout << endl;
	}
}