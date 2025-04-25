#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		int mx = 0, mn = 20000;
		for (int j = 0; j < m; j++)
		{
			int l, r;
			cin >> l >> r;
			mx = max(mx, l);
			mn = min(mn, r);
		}
		if (mx <= mn) {
			cout<<"YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}