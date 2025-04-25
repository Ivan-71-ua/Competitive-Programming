#include <bits/stdc++.h>

int minimalChanges(const std::string& file, const std::string& pattern) {
	int n = file.size();
	int m = pattern.size();
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, INT_MAX));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) f[i][0] = i;
	for (int j = 1; j <= m; j++) f[0][j] = j;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int cost = (file[i-1] == pattern[j-1] || pattern[j-1] == '?') ? 0 : 1;
			f[i][j] = std::min({f[i-1][j] + 1, f[i][j-1] + 1, f[i-1][j-1] + cost});
		}
	}
	return f[n][m];
}

int main() {
	std::string file, pattern;
	while (std::cin >> file >> pattern) {
		file = " " + file;
		pattern = " " + pattern;
		int result = minimalChanges(file, pattern);
		std::cout << result << std::endl;
	}
}
