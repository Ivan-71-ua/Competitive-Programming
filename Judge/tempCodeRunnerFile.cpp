#include <unordered_map>
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
#include <cstdint>


int main() {
	int res = INT32_MAX;
	int n;
	std::cin >> n;
	int h = (n / 100) * 100;
	int s = n % 100;
	int k = std::min({s * 2, 100, (s + 19) / 20 * 30, s / 20 * 30 + (s % 20) * 2});
	std::cout << h + k;
	
}