#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	bool ans = true;
	for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
	{
		if(s[i] != s[j]) {
			ans = false;
			break;
		}
	}
	if(ans) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	
}