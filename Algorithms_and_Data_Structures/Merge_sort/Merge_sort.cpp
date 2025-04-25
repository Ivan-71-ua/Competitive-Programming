#include <bits/stdc++.h>

void merge(std::vector<int>& vec, int st, int fn) {
	int mid = st + (fn - st) / 2;
	std::vector<int> first_arr(mid - st + 1);
	std::vector<int> second_arr(fn - mid);

	for (int i = 0; i < first_arr.size(); i++) {
		first_arr[i] = vec[st + i];
	}
	for (int i = 0; i < second_arr.size(); i++) {
		second_arr[i] = vec[mid + 1 + i];
	}

	int first = 0;
	int second = 0;
	int arr = st; 

	while (first < first_arr.size() && second < second_arr.size()) {
		if (first_arr[first] <= second_arr[second]) {
			vec[arr++] = first_arr[first++];
		} else {
			vec[arr++] = second_arr[second++];
		}
	}

	while (first < first_arr.size()) {
		vec[arr++] = first_arr[first++];
	}
	
	while (second < second_arr.size()) {
		vec[arr++] = second_arr[second++];
	}
}

void merge_sort(std::vector<int>& vec, int st, int fn) {
	if (st >= fn)
		return;
	int mid = st + (fn - st) / 2;
	merge_sort(vec, st, mid);
	merge_sort(vec, mid + 1, fn);
	merge(vec, st, fn);
}

int main() {
	int n;
	std::cout << "Enter size of array: ";
	std::cin >> n;
	std::cout << '\n';
	std::vector<int> vec(n);
	std::cout << "Enter elements of array: ";
	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}
	std::cout << '\n';
	merge_sort(vec, 0, n - 1);
	std::cout << "Sorted array: \n";
	for (int i = 0; i < n; i++) {
		std::cout << vec[i] << ' ';
	}
	std::cout <<  '\n';
	return 0;
}
