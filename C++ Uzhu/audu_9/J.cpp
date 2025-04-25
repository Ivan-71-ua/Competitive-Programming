#include <bits/stdc++.h>
using namespace std;


long long Function1(long long n) {
	return 1 + n + n * n;
}		

int main() {
	long long n;
	cin >> n;
	cout << Function1(n);
}