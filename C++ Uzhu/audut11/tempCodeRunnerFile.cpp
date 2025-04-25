#include <bits/stdc++.h>
#define ll long long



int main() {
	int n[32]{};
	n[1] = 2, n[2] = 4;
	int k;
	std::cin >> k;
	for (int i = 3; i <= k; i++)
	{
		n[i] = n[i - 1] + n[i - 2];
	}
	std::cout << n[k];
}
