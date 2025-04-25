#include <bits/stdc++.h>
using namespace std;

void Soo(int a) {
	a++;
}
void Soo1(int *px) {
	*px = 2;
}
void Soo2(int &x) {
	x = 4;
}

int main()
{
	int a = 0;
	Soo(a);
	cout << a << endl;
	Soo1(&a);
	cout << a << endl;
	Soo2(a);
	cout << a << endl;
}