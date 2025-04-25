#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <string>

int main() {
	int a, b;
	std::cin >> a >> b;
	int n;
	std::cin >> n;
	long long res  = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		res += tmp;
	}
	if ((res >= a && (res - a) % 2 == 0) || (res >= b && (res - b) % 2 == 0)) {
		std::cout << "YES\n";
	}
	else {
		std::cout << "NO\n";
	}
}