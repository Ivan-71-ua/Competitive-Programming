
#include <bits/stdc++.h>

std::vector<int> parent;
std::vector<int> rank;



int find_p(int x) {
	if(parent[x] != x)
		return parent[x] = find_p(parent[x]);
	return x;
}


void make_union(int x, int y) {
	int p_x = find_p(x);
	int p_y = find_p(y);
	if(p_x != p_y) {
		if(rank[p_x] < rank[p_y]) {
			std::swap(p_x, p_y);
		}
		if(rank[p_y] == 0)
			rank[p_y]++;
		parent[p_y] = p_x;
		rank[p_x] += rank[p_y];
	}
}



int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> list(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		a--;
		b--;
		list[a]++;
		list[b]++;
	}
	int res = 0;
	int max, min;
	std::cin >> min >> max;
	for (auto f : list)
	{
		if(min <= f && max >= f)
			res++;
	}
	
	std::cout << res;
}