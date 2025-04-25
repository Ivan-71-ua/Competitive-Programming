#include <bits/stdc++.h>

using namespace std;

vector<int> a; 
vector<int> f;  

int sum(int x) {
	int result = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1) {
		result += f[x];
	}
	return result;
}

int sum(int l, int r) {
	if (l) {
		return sum(r) - sum(l - 1);
	} else {
		return sum(r);
	}
}

void increase(int idx, int delta) {
	a[idx] += delta;
	for (; idx < a.size(); idx = idx | (idx + 1)) {
		f[idx] += delta;
	}
}

int main() {
	int n, q;
	cin >> n >> q;

	a.resize(n, 0);
	f.resize(n, 0); 

	for (int i = 0; i < n; i++) {  
		int t;
		cin >> t;
		increase(i, t);
	}
	for (int i = 0; i < q; i++)
	{
		char ch;
		cin >> ch;
		if(ch == '+') {
			int id, d;
			cin >> id >> d;
			increase(id - 1, d);
		} else {
			int a, b;
			cin >> a >> b;
			cout << sum(a - 1, b - 1) << '\n';
		}
	}
	return 0;
}
