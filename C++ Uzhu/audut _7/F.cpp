#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, k;
	cin >> a >> k;
	cout << (a | (1 << k) );
}