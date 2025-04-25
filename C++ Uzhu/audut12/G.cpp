#include <bits/stdc++.h>
std::vector<std::vector> p;
void HROZNY() {
	int a, n, s;
	std::cin >> a >> n >> s;
	if(s == 0) {
		std::cout << 0;
	}
	else {
		std::cout << a + ((s + 59) / 60) * n;
	}
	
}


int main() {
	HROZNY();
}