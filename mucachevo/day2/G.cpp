
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Побудова суфіксного масиву
std::vector<int> build_suffix_array(const std::vector<int> &arr) {
	int n = arr.size();
	std::vector<int> p(n), c(n), cnt(std::max(256, n), 0);
	for (int i = 0; i < n; i++) cnt[arr[i]]++;
	for (int i = 1; i < 256; i++) cnt[i] += cnt[i - 1];
	for (int i = n - 1; i >= 0; i--) p[--cnt[arr[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (arr[p[i]] != arr[p[i - 1]]) classes++;
		c[p[i]] = classes - 1;
	}
	std::vector<int> pn(n), cn(n);
	for (int h = 0; (1 << h) < n; h++) {
		for (int i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0) pn[i] += n;
		}
		std::fill(cnt.begin(), cnt.begin() + classes, 0);
		for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
		for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for (int i = 1; i < n; i++) {
			int mid1 = (p[i] + (1 << h)) % n;
			int mid2 = (p[i - 1] + (1 << h)) % n;
			if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) classes++;
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}
	return p;
}

// Побудова LCP масиву
std::vector<int> build_lcp_array(const std::vector<int> &arr, const std::vector<int> &suffix_array) {
	int n = arr.size();
	std::vector<int> rank(n), lcp(n - 1, 0);
	for (int i = 0; i < n; i++) rank[suffix_array[i]] = i;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (rank[i] > 0) {
			int j = suffix_array[rank[i] - 1];
			while (i + k < n && j + k < n && arr[i + k] == arr[j + k]) k++;
			lcp[rank[i] - 1] = k;
			if (k > 0) k--;
		}
	}
	return lcp;
}

// Знаходження найкращого приспіва
std::pair<int, std::vector<int>> find_best_refrain(const std::vector<int> &notes) {
	int n = notes.size();
	std::vector<int> extended_notes = notes;
	extended_notes.push_back(0); // Розділювальний символ
	std::vector<int> suffix_array = build_suffix_array(extended_notes);
	std::vector<int> lcp_array = build_lcp_array(extended_notes, suffix_array);

	int max_score = 0;
	int best_length = 0;
	int best_start = 0;

	for (int i = 0; i < n; i++) {
		int length = lcp_array[i];
		int count = n - suffix_array[i];
		int score = length * (i + 1);
		if (score > max_score || (score == max_score && length < best_length)) {
			max_score = score;
			best_length = length;
			best_start = suffix_array[i];
		}
	}

	std::vector<int> best_refrain(notes.begin() + best_start, notes.begin() + best_start + best_length);
	return {max_score, best_refrain};
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> notes(n);
	for (int i = 0; i < n; i++) {
		std::cin >> notes[i];
	}

	auto [max_score, best_refrain] = find_best_refrain(notes);

	std::cout << max_score << "\n";
	std::cout << best_refrain.size() << "\n";
	for (int note : best_refrain) {
		std::cout << note << " ";
	}
	std::cout << "\n";

	return 0;
}
