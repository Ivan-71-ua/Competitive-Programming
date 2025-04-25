#include <bits/stdc++.h>
using namespace std;



int main()
{
	int *pn = new int;
	*pn = 10;
	cout << pn << endl;
	cout << *pn << endl;
	delete pn;
	cout << pn;
}