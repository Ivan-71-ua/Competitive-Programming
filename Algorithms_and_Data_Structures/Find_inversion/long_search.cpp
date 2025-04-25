#include <iostream>
#include <vector>

int countInversions(const std::vector<int>& arr) {
	int n = arr.size();
	int inversions = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				inversions += 1;
			}
		}
	}
	return inversions;
}

int main() {
	std::vector<int> arr = {6, 5, 4, 3, 2, 1};
	std::cout << "Count of inversions: " << countInversions(arr) << std::endl;
	return 0;
}
