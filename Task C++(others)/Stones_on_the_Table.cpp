#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	int k = 0, n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n - 1; i++)
	{
		if(s[i] != s[i + 1]) {
			continue;
		}
		else {
			k++;
		}
	}
	cout << k;
}