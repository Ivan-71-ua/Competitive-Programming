#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int k = n * a;
	int k1 = (n / m) * b + (n % m) * a;
	int k2 = (n + m - 1) / m * b;
	cout << min(min(k, k1), k2);
}