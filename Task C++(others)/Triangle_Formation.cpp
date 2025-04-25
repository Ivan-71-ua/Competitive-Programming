#include <bits/stdc++.h>




const int MAX_N = 1e5 + 5;
int n, q, a[MAX_N], p[MAX_N];

bool canForm(int l, int r) {
	int t = 0;
	for (int i = l; i <= r; i++)
		p[++t] = a[i];
	std::stable_sort(p + 1, p + t + 1);
	for (int i = 1; i <= t - 5; i++)
		for (int j = i + 1; j <= i + 5; j++)
			for (int k = j + 1; k <= i + 5; k++) {
				int q[4], c = 0;
				for (int m = i + 1; m <= i + 5; m++)
					if (m != j && m != k)
						q[++c] = p[m];
				if (p[i] + p[j] > p[k] && q[1] + q[2] > q[3])
					return true;
			}
	int triangleCount	   = 0;
	for (int i = 1; i <= t - 2; i++)
		if (p[i] + p[i + 1] > p[i + 2]) {
			i += 2;
			triangleCount++;
		}
	return triangleCount > 1;
}
int main() {
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		if (r - l + 1 >= 48 || canForm(l, r))
			std::cout << "YES" << '\n';
		else
			std::cout << "NO" << '\n';
	}
}