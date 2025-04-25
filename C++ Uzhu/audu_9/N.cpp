#include <bits/stdc++.h>
using namespace std;

void My_min(int x, int y) {
	cout << min(x, y) << ' ' << max(x, y);
}

int main() {
	int x, y;
	cin >> x >> y;
	My_min(x, y);
}