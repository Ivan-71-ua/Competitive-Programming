#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


std::vector<int> sizes;
std::vector<std::vector<int>> adj;

int dfs(int node, std::vector<std::set<int>> &v_d) {
	int size = 1;  
	for (int neighbor : adj[node]) {
		size += dfs(neighbor, v_d);
		v_d[node].merge(v_d[neighbor]);
	}
	sizes[node] = size;
	v_d[node].insert(sizes[node]);
	return size;
}

int main() {
	std::ios::sync_with_stdio(false);
         std::cin.tie(nullptr);
         std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	while (n--) {
		int n;
		std::cin >> n;

		adj.assign(n + 1, std::vector<int>());
		sizes.assign(n + 1, 0);
		std::vector<std::set<int>> v_d(n +1);

		for (int i = 0; i < n - 1; i++) {
			int a, b;
			std::cin >> a >> b;
			adj[a].push_back(b);
		}
		dfs(1, v_d);
		std::set<int> ans;
		for (int i = 1; i <= n; i++)
		{
			if(adj[i].size() == 0) {
				if(ans.empty()) {
					ans = v_d[i];
				} else {
					for (auto &n: ans)
					{
						if(!v_d[i].count(n)) {
							ans.erase(n);
						}
					}
				}
			}
		}
		std::cout << ans.size() << '\n';
		for (auto &p : ans)
		{
			std::cout << p << ' ';
		}
		std::cout << '\n';
	}
}