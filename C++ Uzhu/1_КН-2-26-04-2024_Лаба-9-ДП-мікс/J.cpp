#include <bits/stdc++.h>

#define MAX 10010
#define INF 0x3F3F3F3F

std::bitset<MAX> mask;

int main() {
	int maxWeight;
	std::cin >> maxWeight;
	mask.set(0); 
	std::vector<int> weights;
	int tmp;
	while(std::cin >> tmp) {
		weights.push_back(tmp);
	}
	for (int w : weights) {
		for (int j = maxWeight; j >= w; --j) {
			if (mask[j - w]) {
				mask.set(j); 
			}
		}
	}
	int result = -1;
	for (int i = maxWeight; i >= 0; --i) {
		if (mask[i]) {
			result = i;
			break;
		}
	}
	std::cout << result << std::endl;
}
