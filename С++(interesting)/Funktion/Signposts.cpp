#include <bits/stdc++.h>
using namespace std;



int main() {
	int a = 5;
	cout << "a\t" <<  a << endl;
	int *pa = &a;
	int *pa2 = &a;
	cout << "pa\t" << pa << endl;
	cout << "pa2\t" << pa2 << endl;
	*pa2 = 7;
	cout << "a\t" << a << endl;
	cout << "pa\t" << *pa << endl;
}