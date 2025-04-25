#include <bits/stdc++.h>

// Функція компаратор для суфіксного масиву
bool compareSuffixes(int i, int j, int k, int n, const std::vector<int>& rank) {
	if (rank[i] != rank[j])
		return rank[i] < rank[j];
	int ri = (i + k < n) ? rank[i + k] : -1;
	int rj = (j + k < n) ? rank[j + k] : -1;
	return ri < rj;
}

// Функція для побудови суфіксного масиву
std::vector<int> buildSuffixArray(const std::string &s) {
	int n = s.size();
	std::vector<int> suffixArray(n), rank(n), temp(n);

	// Ініціалізація суфіксного масиву та рангу
	for (int i = 0; i < n; i++) {
		suffixArray[i] = i;
		rank[i] = s[i];
	}

	for (int k = 1; k < n; k *= 2) {
		std::sort(suffixArray.begin(), suffixArray.end(), [&](int i, int j) {
			return compareSuffixes(i, j, k, n, rank);
		});

		temp[suffixArray[0]] = 0;
		for (int i = 1; i < n; i++) {
			temp[suffixArray[i]] = temp[suffixArray[i - 1]] + compareSuffixes(suffixArray[i - 1], suffixArray[i], k, n, rank);
		}
		rank = temp;
	}
	return suffixArray;
}

// Компаратор для підрядків
int compareSubstrings(const std::string &s, const std::string &t, int idx) {
	int m = t.size();
	for (int i = 0; i < m; i++) {
		if (idx + i >= s.size() || s[idx + i] != t[i]) {
			return s[idx + i] - t[i];
		}
	}
	return 0;
}

// Функція для підрахунку входжень підрядка t в рядок s
int countOccurrences(const std::string &s, const std::vector<int> &suffixArray, const std::string &t) {
	int n = s.size();
	int m = t.size();

	// Знаходження нижньої межі
	int left = 0, right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		if (compareSubstrings(s, t, suffixArray[mid]) < 0) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	int lower = left;

	// Знаходження верхньої межі
	left = 0, right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		if (compareSubstrings(s, t, suffixArray[mid]) <= 0) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	int upper = left;

	return upper - lower;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;
	int Q;
	std::cin >> Q;

	// Побудова суфіксного масиву
	std::vector<int> suffixArray = buildSuffixArray(S);

	// Обробка запитів
	for (int i = 0; i < Q; i++) {
		std::string T;
		std::cin >> T;
		std::cout << countOccurrences(S, suffixArray, T) << '\n';
	}

	return 0;
}
