#include<bits/stdc++.h>


void d_w(int v, int p, std::vector<std::vector<int>> &edgs, std::vector<int> &w) {
	w[v] = 1;
	for(auto next : edgs[v]) {
		if(next != p) {
			d_w(next, v, edgs, w);
			w[v] += w[next];
		}
	}
}


int dfs(int v, int p,  std::vector<std::vector<int>> &edgs, std::vector<int> &w, int size) {
	for (int next : edgs[v]) {
		if (next != p && w[next] > size / 2) {
			return dfs(next, v, edgs, w, size);
		}
	}
	return v;
}


int main()
{
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> edgs(n +1);
	std::vector<int> w(n + 1);
	for(int i = 0; i < n -1; i++) {
		int a, b;
		std::cin >> a >> b;
		edgs[b].push_back(a);
		edgs[a].push_back(b);
	}
	d_w(1, -1, edgs, w);
	std::cout << dfs(1, -1, edgs, w, n);

}

