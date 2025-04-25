#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, h, w = 0;
	cin >> a >> h;
	for (int i = 0; i < a; i++)
	{
		int c;
		cin >> c;
		if (c > h) {
			w += 2;
		}
		else {
			w++;
		}
	}
	cout << w;
} 	