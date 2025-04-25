#include <bits/stdc++.h>

const int MOD = 1000000007;


std::vector<std::vector<std::vector<std::vector<int>>>> f;

int countMegaCoolNumbers(int n, int a) {
	if (a > 9) return 0;

	f.assign(n + 1, std::vector<std::vector<std::vector<int>>>(10, std::vector<std::vector<int>>(10, std::vector<int>(10, 0))));
	for (int d = 1; d <= 9; d++)
		f[1][1][9][d] = 1;
	for (int i = 1; i < n; i++)
		for (int pow = 1; pow <= 9; pow++)
			for (int last = 1; last <= 9; last++)
				for (int d = last; d <= 9; d++) {
					f[i+1][pow][d-last][d] += f[i][pow][9][last];
					f[i+1][pow][d-last][d] %= MOD;
					for (int diff = 0; diff <= 8; diff++)
							if (d - last == diff) {
								f[i+1][pow][diff][d] += f[i][pow][diff][last];
								f[i+1][pow][diff][d] %= MOD;
							} else if (pow < 9) {
								f[i+1][pow+1][9][d] += f[i][pow][diff][last];
								f[i+1][pow+1][9][d] %= MOD;
							}
						 }
	int result = 0;
	for (int last = 1; last <= 9; last++)
		for (int diff = 0; diff <= 9; diff++)
				result = (result + f[n][a][diff][last]) % MOD;
	return result;
}

int main() {
	int n, a;
	while (std::cin >> n >> a) {
		int result = countMegaCoolNumbers(n, a);
		std::cout << result << std::endl;
	}
}
