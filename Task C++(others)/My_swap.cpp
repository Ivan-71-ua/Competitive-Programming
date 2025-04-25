#include <bits/stdc++.h>
using namespace std;

void My_swap(int *px, int *py) {
	int c = *px;
	*px = *py;
	*py = c;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << "SWAP: ";
	My_swap(&a, &b);
	cout << a << " " << b;
}
