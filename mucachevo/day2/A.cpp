#include <bits/stdc++.h>



int main() {
	int n;
	std::cin >> n;
	std::vector<int> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	std::vector<int> a(n, 0);
	int current_value = 0;
	for (int i = 0; i < n; i++) {
		a[s[i]] = current_value++;
	}

	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";

	return 0;
}
