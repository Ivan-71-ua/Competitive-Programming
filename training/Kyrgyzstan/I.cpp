#include <bits/stdc++.h>

std::vector<int> parent;
std::vector<int> rank;

int find(int x) {
	if(parent[x] != x)
		return parent[x] = find(parent[x]);
	return x;
}

bool make_union(int x, int y) {
	int px = find(x);
	int py = find(y);
	if(px == py) {
		return false;
	} 
	if(rank[px] < rank[py])
		std::swap(px, py);
	parent[py] = px;
	rank[px] += rank[py];
	return true;
}

int main() {
	int n;
	std::cin >> n;
	int r, b;
	std::vector<int> min_r(3, INT32_MAX);
	std::vector<int> min_b(3, INT32_MAX);
	std::vector<std::pair<int, std::pair<int, std::pair<int, int>>>> ver;
	std::cin >> r;
	for (int i = 0; i < r; i++)
	{
		int a, b, v;
		std::cin >> a >> b >> v;
		if(min_r[2] > v) {
			min_r[0] = a;
			min_r[1] = b;
			min_r[2] = v;
		}
		ver.push_back({v, {a, {b, 0}}});
	}
	std::cin >> b;
	for (int i = 0; i < b; i++)
	{
		int a, b, v;
		std::cin >> a >> b >> v;
		if(min_b[2] > v) {
			min_b[0] = a;
			min_b[1] = b;
			min_b[2] = v;
		}
		ver.push_back({v, {a, {b, 1}}});
	}
	std::stable_sort(ver.begin(), ver.end());
	parent.resize(n + 1);
	rank.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		rank[i] = 1;
	}
	int max_rs = min_r[2];
	int max_bs = min_b[2];
	make_union(min_b[0], min_b[1]);
	make_union(min_r[0], min_r[1]);
	int cnt = 2;
	for (int i = 0; i < r + b; i++) {
		int a = ver[i].second.first, b = ver[i].second.second.first, v = ver[i].first,  col = ver[i].second.second.second;
		if (make_union(a, b)) {
			if(col == 0) {
				max_rs = std::max(max_rs, v);
			} else {
				max_bs = std::max(max_bs, v);
			}
			cnt++;
		}
	}
	if(cnt != n -1) {
		std::cout << 1;
		return 0;
	}
	std::cout << max_bs + max_rs;
}