#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int L = 0, R = 0, S = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'R') S++;
		if (s[i] == 'L') S--;
		if (S > R) R = S;
		if (S < L) L = S;
	}
	cout << R - L + 1;
}