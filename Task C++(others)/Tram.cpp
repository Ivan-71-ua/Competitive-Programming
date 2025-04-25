#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, temp = -1, max = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if(temp == -1) {
			cin >> a >> b;
			temp = b;
			max = b;
		}
		else {
			cin >> a >> b;
			temp = temp - a + b;
			if(temp > max) {
				max = temp;
			}
		}
	}
	cout << max;
} 	