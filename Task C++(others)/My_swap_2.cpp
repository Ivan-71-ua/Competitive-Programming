#include <bits/stdc++.h>
using namespace std;

template <class T> void Swap(T &a, T &b) {
	T c = a;
	a = b;
	b = c;

}

int main()
{
	string a = "7", b = "9";
	Swap(a, b);
	cout << a << " " << b;
}