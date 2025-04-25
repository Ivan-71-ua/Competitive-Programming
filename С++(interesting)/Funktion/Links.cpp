#include <bits/stdc++.h>
using namespace std;



int main()
{
	int a;
	int *pa = &a;
	(*pa) = 5;
	cout << a << endl;
	int &aref = a;
	aref = -20;
	cout << a << endl;
}