#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	bool v1 = (a > 0 || b > 0 || c > 0);
	bool v2 = (a < 0 || b < 0 || c < 0);
	if ( v1 && v2)  {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
}
