#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int k = 0;
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == s[0]) {
			k++;
		}
	}
	cout << s[0] <<  " " << k;
}