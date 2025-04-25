#include <bits/stdc++.h>
#define ll long long
#define db double

bool simple ( ll a){
	bool res = true;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if(a % i == 0) {
			res = false; 
			break;
		}
	}
	
	return res;
}



int main() {
	ll a, b, k = 0;
	std::cin >> a >> b;
	for (ll i = a; i <= b; i++)
	{
		if(simple(i)) {
			std::cout << i << "\n";
			k++;
		}
	}
	if(k == 0) {
		std::cout << "Absent";
	}
	
}