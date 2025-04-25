#include <bits/stdc++.h>
using namespace std;

void Add_one(int *pa) {
	(*pa)++;
}

int main() {
	int a = 0;
	cout << a << endl;
	Add_one(&a);
	cout << a << endl;
}
