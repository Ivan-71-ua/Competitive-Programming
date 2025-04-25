#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

const int N = 500000 + 6;
std::vector<int> cnt(N);
std::vector<int> ans(N);

int32_t main(){
	fast;
	int n, k, m;
	std::cin >> n >> k >> m;
	for (int i = 1; i <= m; ++i){
		int a, b; 
		std::cin >> a >> b;
	}
	for (int i = 1; i<= n*k; ++i){
		int a;
		std::cin >> a;
		++cnt[a];
		ans[i] = cnt[a];
	}
	for (int i = 1; i <= n*k; ++i) {
		std::cout << ans[i] << ' ';
	}	
}
