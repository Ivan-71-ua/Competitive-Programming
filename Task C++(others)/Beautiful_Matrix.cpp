#include <bits/stdc++.h>
using namespace std;


int main() {
	int x, y;
	for (int i = 1; i <= 5; i++)
	{
		int c;
		for (int j = 1; j <= 5; j++)
		{
			cin >> c;
			if(c != 0) {
				x = i;
				y = j;
			}
		}
	}
	cout << abs(3 - x) + abs(3 - y);
}