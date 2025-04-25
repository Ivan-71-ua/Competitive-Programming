#include <bits/stdc++.h>

const long long N = 2e5 + 2;
const long long C = 10 + 1;

std::vector<long long> parent(N), size(N, 0);
std::vector<std::vector<long long>> dp(N, std::vector<long long>(C, 0)), 
												ind(N, std::vector<long long>(C, 0)), 
												start_count(N, std::vector<long long>(C, 0)), 
												end_count(N, std::vector<long long>(C, 0));

long long find_parent(long long a) {
	if (parent[a] == a) 
		return a;
	return parent[a] = find_parent(parent[a]);  
}

void unite(long long a, long long b) {
	a = find_parent(a);
	b = find_parent(b);
	
	if (a == b) return;  

	if (size[b] > size[a]) 
		std::swap(a, b);  

	size[a] += size[b];  
	parent[b] = a; 
}

void reset(long long n) {
	for (long long i = 1; i <= n; i++) {
		parent[i] = i;  
		size[i] = 1;  
		for (long long j = 1; j < C; j++) {
			dp[i][j] = start_count[i][j] = end_count[i][j] = 0;  
			ind[i][j] = i; 
		}
	}
}

void solve() {
	long long n, m;
	std::cin >> n >> m;  
	reset(n);  

	for (long long i = 0; i < m; i++) {
		long long a, d, k;
		std::cin >> a >> d >> k;  
		start_count[a][d]++;  
		end_count[a + k * d][d]++;  
	}

	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j < C; j++) {
			dp[i][j] = start_count[i][j] - end_count[i][j];  // оновлюємо dp для поточної точки
			if (i - j < 1) 
				continue;  // якщо виходимо за межі індексів

			if (dp[i - j][j]) {  // якщо є попередня точка у цьому кроці
				unite(ind[i - j][j], i);  // об'єднуємо компоненти
				ind[i][j] = ind[i - j][j];  // оновлюємо індекс компоненти
				dp[i][j] += dp[i - j][j];  // додаємо кількість триплетів
			}
		}
	}

	// Підрахунок кількості компонент зв'язності
	long long result = 0;
	for (long long i = 1; i <= n; i++) {
		if (find_parent(i) == i) 
			result++; 
	}

	std::cout << result << "\n";  
}


int main() {
	long long t;
	std::cin >> t;  
	while (t--) {
		solve();  
	}
}
