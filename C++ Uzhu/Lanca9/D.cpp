#include <bits/stdc++.h>
using namespace std;



bool simple ( long long a){
	bool res = true;
	for (int i = 2; i < sqrt(a); i++)
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
	if(simple(n)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}