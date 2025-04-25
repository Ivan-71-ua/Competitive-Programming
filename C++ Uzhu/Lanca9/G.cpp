#include <bits/stdc++.h>
using namespace std;

bool simple ( long long a){
	bool res = true;
	for (int i = 2; i * i <= a; i++)
	{
		if(a % i == 0) {
			res = false;
			break;
		}
	}
	return res;
}

int main() {
	long long n;
	cin >> n;
	if (n == 4) cout << "NO";
	else {
		if (n == 1 || !simple(n)) cout << "YES";
      else cout << "NO";
	}
}

