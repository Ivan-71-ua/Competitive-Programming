#include <iostream>
#include <cmath>
//#include <iomanip>
//#include <string>
//#include <vector>
//#include <set>
using namespace std;


int main() {
	int n, sum1 = 0, sum2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c, c1;
		cin >> c >> c1;
		if (c > c1) {
			sum1++;
		}
		else if(c < c1) {
			sum2++;
		}
	}
	if (sum1 > sum2) {
		cout << 1;
	}
	else if (sum1 < sum2) {
		cout << 2;
	}
	else {
		cout << 0;
	} 

}	