

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	int a =0;
	for(int i =0; i < n; i++) {
		int k;
		std::cin >> k;
		a += k;
	}
	cout<< a <<"\n";
}
