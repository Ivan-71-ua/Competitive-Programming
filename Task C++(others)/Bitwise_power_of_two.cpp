#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	if(!(n & (n - 1))) {
		cout << "Power of two";
	}
	else {
		cout << "Not power of two";
	}
}