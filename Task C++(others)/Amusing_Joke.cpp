#include <bits/stdc++.h>
using namespace std;


int main() {
	string s, s1, s2;
	cin >> s >> s1 >> s2;
	string result1 = s + s1;
	sort(result1.begin(), result1.end());
	sort(s2.begin(), s2.end());
	if(result1 == s2) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}