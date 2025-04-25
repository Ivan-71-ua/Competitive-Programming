#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int k = 1;
	int k1 = 2 * n - 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if(j >= k && j <= k1) {
				cout << "@";
			}
			else {
				cout << ":";
			}
			
		}
		k++;
		k1--;
		cout << endl;
		}
}