#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	long long result = 0;
	while (a % 4 != 0 && a <= b)
	{
		result ^= a;
		a++;	
	}
	while (b % 4 != 3 && a <= b)
	{
		result ^= b;
		b--;
	}
	cout << result;
}