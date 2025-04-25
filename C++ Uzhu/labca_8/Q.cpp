#include <bits/stdc++.h>
using namespace std;


int main() {
	string s, s1;
	cin >> s >> s1;
	sort(s.begin(), s.end());
	sort(s1.begin(), s1.end());
	bool ans = true;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] != s1[i]) {
			ans = false;
		}
	}
	if(ans) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}