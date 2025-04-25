#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
public:
	vector<int> parent, rank;
	
	DSU(int n) {
		parent.resize(n);
		rank.resize(n, 1);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	
	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]); 
		}
		return parent[x];
	}
	
	bool unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY) {
			if (rank[rootX] > rank[rootY]) {
					parent[rootY] = rootX;
			} else if (rank[rootX] < rank[rootY]) {
					parent[rootX] = rootY;
			} else {
					parent[rootY] = rootX;
					rank[rootX]++;
			}
			return true;
		}
		return false;  
	}
};

int main() {
	int n;
	cin >> n;
	
	DSU dsu(n);
	vector<pair<int, int>> roads;  
	vector<pair<int, int>> extra_edges;  
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;  
		
		if (!dsu.unite(u, v)) {
			extra_edges.push_back({u, v});  
		}
	}

	
	vector<int> components;
	for (int i = 0; i < n; i++) {
		if (dsu.find(i) == i) {
			components.push_back(i);
		}
	}

	
	int t = components.size() - 1;
	cout << t << endl;
	
	for (int i = 0; i < t; i++) {
		
		cout << extra_edges[i].first + 1 << " " << extra_edges[i].second + 1 << " " 
				<< components[i] + 1 << " " << components[i + 1] + 1 << endl;
	}

	return 0;
}
