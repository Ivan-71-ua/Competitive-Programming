#include <iostream>
#include <cmath>
//#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n, m, sum = 0, sum1 = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		sum += a;
		sum1 += b;
	}
	cout << (sum + m - 1) / m + (sum1 + m - 1) / m;
}	