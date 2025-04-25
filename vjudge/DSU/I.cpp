#include <bits/stdc++.h>

class Union_Find {
	std::vector<int> parent;
	std::vector<int> rank;

public:
	Union_Find(int n) {
		parent.resize(n);
		rank.resize(n);
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

	void make_union(int x, int y) {  
		int px = find(x);
		int py = find(y);
		if(px != py) {
			if(parent[px] < parent[py])
				std::swap(px, py);
			parent[py] = px;
			rank[px] += rank[py];
		}
	}
};


int main() {
	int n, m;
	std::cin >> n >> m;
	Union_Find road(n);
	for (int i = 0; i < m; i++)
	{
		std::string s;
		std::cin >> s;
		int a, b;
		if(s == "union") {
			std::cin >> a >> b;
			road.make_union(a - 1, b - 1);
		} else {
			std::cin >> a >> b;
			if(road.find(a -1) == road.find(b -1)) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
		}
	}
}