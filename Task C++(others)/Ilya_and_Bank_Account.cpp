#include <bits/stdc++.h>
using namespace std;



int main() {
	int s;
	cin >> s;
	if(s >= 0) {
		cout << s;
	}
	else {
		string k = to_string(s), k2 = to_string(s);
		k.erase(k.size() - 2, 1);
		k2.erase(k2.size() - 1, 1);
		if(stoi(k) < stoi(k2)) {
			cout << stoi(k2);
		}
		else {
			cout << stoi(k);
		}
	}
}