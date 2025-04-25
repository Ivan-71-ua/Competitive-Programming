#include <bits/stdc++.h>
using namespace std;

int Sum(int x, int y) {
	return x + y;
}
double Sum(double x, double y) {
	return x + y;
}
int Sum(int x, int y, int z) {
	return x + y + z;
}

int main()
{
	cout << Sum(2, 5) << endl;
	cout << Sum(3.6, 8.9) << endl;
	cout << Sum(2, 5, 9) << endl;
}