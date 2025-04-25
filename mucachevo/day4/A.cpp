#include <bits/stdc++.h>

const long long MX = 1LL << 40;
std::map<long long, long long> random_hashes;
std::mt19937_64 rng(228);

long long get_hash(long long x) {
	if (random_hashes.count(x)) return random_hashes[x];
	return random_hashes[x] = std::uniform_int_distribution<long long>(1, MX)(rng);
}

void compute_prefix_hashes(const std::vector<int>& arr, std::vector<long long>& prefix_hashes) {
	std::set<int> seen;
	for (size_t i = 1; i <= arr.size(); i++) {
		if (seen.count(arr[i - 1]) == 0) {
			seen.insert(arr[i - 1]);
			prefix_hashes[i] = prefix_hashes[i - 1] ^ get_hash(arr[i - 1]);
		} else {
			prefix_hashes[i] = prefix_hashes[i - 1];
		}
	}
}

void solve() {
	std::ios::sync_with_stdio(false);
               std::cin.tie(nullptr);
               std::cout.tie(nullptr);
	int N;
	std::cin >> N;
	std::vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) std::cin >> A[i];
	for (int i = 0; i < N; i++) std::cin >> B[i];
	std::vector<long long> hashA(N + 1, 0), hashB(N + 1, 0);
	compute_prefix_hashes(A, hashA);
	compute_prefix_hashes(B, hashB);
	int Q;
	std::cin >> Q;
	while (Q--) {
		int x, y;
		std::cin >> x >> y;
		if (hashA[x] == hashB[y]) std::cout << "Yes\n";
		else std::cout << "No\n";
	}
}

int main() {
	solve();
	return 0;
}
