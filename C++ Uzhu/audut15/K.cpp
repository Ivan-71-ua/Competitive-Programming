#include <bits/stdc++.h>

struct City {
	int people, num;
	
	City(int people = 0, int num = 0) : people(people), num(num) {}
};

bool compare(const City& a, const City& b) {
	if (a.people == b.people)
		return a.num < b.num;
	return a.people < b.people;
}

bool query(const std::vector<City>& cities, int l, int r, int x) {
	auto left = std::lower_bound(cities.begin(), cities.end(), City(x, l), compare);
	auto right = std::upper_bound(cities.begin(), cities.end(), City(x, r), compare);
	return left != right;
}

int main() {
	int n, q;
	std::cin >> n;
	
	std::vector<City> cities(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> cities[i].people;
		cities[i].num = i + 1;
	}

	std::sort(cities.begin(), cities.end(), compare);

	std::cin >> q;
	while (q--) {
		int l, r, x;
		std::cin >> l >> r >> x;
		std::cout << query(cities, l, r, x);
	}
	std::cout << std::endl;
}
