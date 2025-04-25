#include <bits/stdc++.h>
using namespace std;




int main()
{
	int n, k = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		if (c == 1) {
			k++;
		}
	}
	if (k == 0) {
		cout << "EASY";
	}
	else {
		cout << "HARD";
	}
}