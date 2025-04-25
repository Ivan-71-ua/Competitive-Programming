#include <bits/stdc++.h>


class Solution {
	std::vector<int> rank, parent;
	int find(int x) {
		if(parent[x] == x) {
			return x;
		}
		return parent[x] = find(parent[x]);
	}
	void unite(int a, int b){
		int pa = find(a), pb = find(b);
		if(pa != pb) {
			if(rank[pa] < rank[pb])
				std::swap(pa, pb);
			parent[pb] = pa;
			rank[pa] += rank[pb];
		}
	}
public:
	int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
		rank.resize(n, 1);
		parent.resize(n);
		std::vector<int> pows(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < edges.size(); i++) {
			unite(edges[i][0], edges[i][1]);
			pows[edges[i][0]]++;
			pows[edges[i][1]]++;
		}
		int cnt = 0;
		std::unordered_map<int, std::vector<int>> mp;
		for (int i = 0; i < n; i++) {
			parent[i] = find(i);
			mp[parent[i]].push_back(i);
		}
		for(auto &v: mp) {
			bool is = true;
			for(auto &e: v.second) {
				if(pows[e] != rank[v.first] - 1) {
					is = false;
					break;
				}
			}
			if(is)
				cnt++;
		}
		return cnt;
	}
};

int main() {
	std::vector<std::vector<int>> edges{{2,0},{3,1},{3,2}};
	Solution s;
	std::cout << s.countCompleteComponents(4, edges) << '\n';
}