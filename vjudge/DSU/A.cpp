#include <bits/stdc++.h>

class Union_Find {
	std::vector<int> parent;
	std::vector<int> rank;
	int cur_max = 1;
	int cnt;
public:
	Union_Find(int n) {
		parent.resize(n);
		rank.resize(n);
		cnt = n;
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			rank[i] = 1;
		}
	}
	
	int find(int x) {  
		if(parent[x] != x)
			return parent[x] = find(parent[x]);
		return x;
	}

	std::pair<int, int> make_union(int x, int y) {  
		int px = find(x);
		int py = find(y);
		if(px != py) {
			if(parent[px] < parent[py])
				std::swap(px, py);
			parent[py] = px;
			rank[px] += rank[py];
			cur_max = std::max(cur_max, rank[px]);
			cnt--;
		}
		return {cnt, cur_max};
	}
};


int main() {
	int n, m;
	std::cin >> n >> m;
	Union_Find road(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		auto pr = road.make_union(a -1, b -1);
		std::cout << pr.first << ' ' << pr.second << '\n';
	}
	
}