#include <bits/stdc++.h>
#define int long long

struct Sand {
	double price; 
	int weight;                
	Sand(int price, int weight) : price(1.0 * price / weight), weight(weight) {}
};

bool comp(const Sand& a, const Sand& b) {
	return a.price > b.price;
}

int32_t main() {
	int n, w;  
	std::cin >> n >> w;
	std::vector<Sand> arr;
	for (int i = 0; i < n; i++) {
		int price, weight;
		std::cin >> price >> weight;
		arr.emplace_back(price, weight);
	}
	std::sort(arr.begin(), arr.end(), comp);
	double res = 0.0;  
	for (auto sand : arr) {
		int canTake = std::min(w, sand.weight); 
		res += canTake * sand.price;
		w -= canTake; 
		if (w == 0) break;
	}
	std::cout << std::fixed;
	std::cout.precision(3);
	std::cout << res;
}
