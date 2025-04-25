
#include <bits/stdc++.h>
using namespace std; 

long long f(int x, int y)
{
	if(x <= 0 || y <= 0) {
		return 0;
	}
	if(x <= y) {
		return 2 + f(x - 1, y - 2) + f(x - 2, y - 1);
	}
	else if(x > y) {
		return 1 + f(x - 2, y - 2);
	}
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << f(x, y);
}
