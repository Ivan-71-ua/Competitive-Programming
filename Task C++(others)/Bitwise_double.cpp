#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	if(!(n & 1)) {
		cout << "Double";
	}
	else {
		cout << "Not double";
	}
}