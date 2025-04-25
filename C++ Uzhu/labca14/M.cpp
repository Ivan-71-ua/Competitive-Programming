#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	int t;
	std::cin >> t;
	std::vector<int> res(t);
	for (int i = 0; i < t; i++)
	{
		std::cin >> res[i];
	}
	int i = 0;
	int j = t - 1;
	int hus = 0;
	int ar = 0;
	bool quen = true;
	for (; i <= j; )
	{
		if(res[i] > res[j]) {
			if(quen) {
				hus += res[i];
				i++;
				quen = false;
			} else {
				ar += res[i];
				i++;
				quen = true;
			}
		} else {
			if(quen) {
				hus += res[j];
				j--;
				quen = false;
			} else {
				ar += res[j];
				j--;
				quen = true;
			}
		}
	}
	std::cout << hus << ' ' << ar;
}