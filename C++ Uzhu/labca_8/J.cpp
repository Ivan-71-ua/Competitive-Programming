#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	for (int i = a, j = b, k = 0;k < ((b - a) + 2) / 2 ; i++, j--, k++)
	{
		swap(s[i], s[j]);
	}
	cout << s;
}