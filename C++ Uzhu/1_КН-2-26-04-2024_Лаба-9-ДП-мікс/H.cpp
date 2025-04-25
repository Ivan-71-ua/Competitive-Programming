#include <bits/stdc++.h>

#define MAX 30000010
#define INF 0x3F3F3F3F

std::bitset<MAX> mask;

int main() {
	int maxWeight, numItems;
	std::cin >> maxWeight >> numItems;
	mask.set(0); 
	std::vector<int> weights(numItems);
	for (int i = 0; i < numItems; ++i) {
		std::cin >> weights[i];
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
