#include <bits/stdc++.h>
using namespace std;


int Fibonachi(int n) {
	if(n == 1) {
		return 1;
	}
	if(n == 2) {
		return 2;
	}
	else {
		return Fibonachi(n - 1) + Fibonachi(n - 2);
	}
}

int main() {
	int n;
	cin >> n;
	cout << Fibonachi(n);
}