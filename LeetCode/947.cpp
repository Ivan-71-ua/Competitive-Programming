#include <bits/stdc++.h>




class Solution {
	class Union_Find
	{
	private:
		std::vector<int> parent;
		std::vector<int> rank;
		std::set<int> final_parents;
		int find(int x) {
			if(parent[x] != x) {
				return parent[x] = find(parent[x]); 
			}
			return x;
		}
	public:
		Union_Find(int n) {
			parent.resize(n);
			rank.resize(n);
			for (int i = 0; i < n; i++)
			{
				final_parents.insert(i);
				parent[i] = i;
				rank[i] = 1;
			}
		}
		void make_union(int x, int y) {
			int px = find(x);
			int py = find(y);
			if(px != py) {
				if(rank[px] < rank[py])
					std::swap(px, py);
				parent[py] = px;
				rank[px] += rank[py];
				final_parents.erase(py);
			}
		}
		int get_delete_stone() {
			int ans = 0;
			for (auto &&pr : final_parents)
			{
				ans += rank[pr] - 1;
			}
			return ans;
		}
	};
public:
	int removeStones(std::vector<std::vector<int>>& stones) {
		int n = stones.size();
		Union_Find unf = Union_Find(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int x = stones[i][0];
				int y = stones[i][1];
				int x1 = stones[j][0];
				int y1 = stones[j][1];
				if(x == x1 || y == y1) {
					unf.make_union(i, j);
				}
			}
		}
		return unf.get_delete_stone();
	}
};