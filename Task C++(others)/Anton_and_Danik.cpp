#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k = 0, k1 = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == 'A') {
			k++;
		}
		if(s[i] == 'D') {
			k1++;
		}
	}
	if(k > k1) {
		cout << "Anton";
	}
	else if(k < k1) {
		cout << "Danik";
	}
	else {
		cout << "Friendship";
	}
}