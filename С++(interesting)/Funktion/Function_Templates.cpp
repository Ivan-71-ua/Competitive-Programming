#include <bits/stdc++.h>
using namespace std;

template <class T> T Sum(T a, T b) {
	return a + b;
}
template <class T, class T1> T Sub(T a, T1 b) {
	return a - b;
}

int main()
{
	cout << Sum(2, 4) << endl;
	cout << Sum(2.1, 4.6) << endl;
	cout << Sub(2, 4) << endl;
	cout << Sub(2.8, 4) << endl;
}