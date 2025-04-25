#include <bits/stdc++.h>

int merge(std::vector<int> &arr, int st, int mid, int fn) {
	int invers = 0;
	std::vector<int> left(mid - st + 1);
	std::vector<int> right(fn - mid);

	for (int i = 0; i < left.size(); i++) {
		left[i] = arr[st + i];
	}
	for (int i = 0; i < right.size(); i++) {
		right[i] = arr[mid + 1 + i];
	}

	int i = 0, j = 0, k = st;	
	while(i < left.size() && j < right.size()) {
		if(left[i] <= right[j]) {
			arr[k++] = left[i++];
		} else {
			invers += left.size() - i; // Кількість інверсій
			arr[k++] = right[j++];
		}
	}
	while(i < left.size()) {
		arr[k++] = left[i++];
	}
	while(j < right.size()) {
		arr[k++] = right[j++];
	}
	return invers;
}

int merge_sort(std::vector<int> &arr, int st, int fn) {
	if(st >= fn)
		return 0;
	int mid = st + (fn - st) / 2;
	int left_inv = merge_sort(arr, st, mid);
	int right_inv = merge_sort(arr, mid + 1, fn);
	int cur_inv = merge(arr, st, mid, fn);
	return left_inv + right_inv + cur_inv;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	int invers = merge_sort(arr, 0, arr.size() - 1);
	std::cout << "Count of inversions: " << invers << '\n';
}
