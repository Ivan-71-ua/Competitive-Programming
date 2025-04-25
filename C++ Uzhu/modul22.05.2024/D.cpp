#include <bits/stdc++.h>

int main() {
	std::freopen("input.txt", "r", stdin);
	std::freopen("output.txt", "w", stdout);
	int n, m;
	std::cin >> n >> m;
	std::string result = "";
	if (n > m) {
		while (n > 0 && m > 0) {
			result += "B";
			result += "G";
			n--;
			m--;
		}
		while (n > 0) {
			result += "B";
			n--;
		}
	} else {
		while (n > 0 && m > 0) {
			result += "G";
			result += "B";
			n--;
			m--;
		}
		while (m > 0) {
			result += "G";
			m--;
		}
	}
	std::cout << result << '\n';
}
