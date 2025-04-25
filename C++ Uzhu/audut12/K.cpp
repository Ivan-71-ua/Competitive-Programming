#include <bits/stdc++.h>


void HROZNY() {
	int k, d = 0;
	std::cin >> k;
	for (int i = 1; k > 0; i++)
	{
		k -= i;
		d++;
	}
	std::cout << d;
}


int main() {
	HROZNY();
}