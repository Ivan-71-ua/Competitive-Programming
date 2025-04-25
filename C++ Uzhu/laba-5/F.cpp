#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int k = 0;
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int c;
			cin >> c;
			if(i == j) {
				sum1 += c;
				k++;
				if(n % 2 != 0 && k == ceil(n / 2.0)) {
					sum2 += c;
				}
			}
			else if (i + j == n + 1) {
				sum2 += c;
			}
			
			}
		}
		
	
	cout << sum1 << " " << sum2;
}