#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, k;
	cin >> a >> k;
	a = a >> k;
	if(!(a & 1)) {
		cout << 0;
	}
	else {
		cout << 1;
	}
}