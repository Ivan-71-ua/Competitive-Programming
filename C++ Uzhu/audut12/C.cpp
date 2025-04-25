#include <bits/stdc++.h>

void HROZNY() {
	int t, p= 0, m= 0, z = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int k;
		std::cin >> k;
		if(k < 0) {
			m++;
		}
		else if(k > 0) {
			p++;
		}
		else {
			z++;
		}
	}
	std::cout << p << " " << m << " " << z;
}


int main() {
	HROZNY();
}