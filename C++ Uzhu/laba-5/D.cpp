#include <bits/stdc++.h>
using namespace std;


int main() {
	double n;
	cin >> n;
	int b = ceil((n * n) / 2);
	int a = 1, k = b + 1;
	for (int i = 1; i <= (int)n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if ((i + j) % 2 == 0) {
				cout << a << " ";
				a++;
			}
			else if ((i + j) % 2 != 0) {
				cout << k << " ";
				k++;
			}
		}
		cout << endl;
		}
	
}