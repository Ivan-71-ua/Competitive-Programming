#include <bits/stdc++.h>
using namespace std;


int main() {
	string s, s1;
	while (cin >> s) {
		s1 = s1 + s;
	}
	bool ans = true;
	for (int i = 0, j = s1.size() - 1; i < s1.size() / 2; i++, j--)
	{
		if(s1[i] != s1[j]) {
			ans = false;
			break;
		}
	}
	if(ans) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}