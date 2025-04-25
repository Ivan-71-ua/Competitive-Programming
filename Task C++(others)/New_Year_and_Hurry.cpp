#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	int t = 0, t_l = 240 - k, q = 0;
	for (int i = 1; t <= t_l ; i++)
	{
		t += 5 * i;
		q++;
	}
	q--;
	if(q > n) {
		cout << n;
	}
	else {
		cout << q;
	}
}