#include <bits/stdc++.h>



class Solution {
	void dfs(int v, std::vector<std::vector<int>> graf, std::vector<bool> used,  int &belive) {
		used[v] = true;
		for (auto next: graf[v]) 
		{
			if(!used[next]) {
				belive = next;
				dfs(next, graf, used, belive);
			}
		}
		used[v] = false;
	}
public:
	int findJudge(int n, std::vector<std::vector<int>>& trust) {
		std::vector<int> child(n + 1);
		std::vector<int> parent(n + 1);
		for (auto now: trust)
		{
			child[now[1]]++;
			parent[now[0]]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if(child[i]== n-1 && parent[i] == 0)
				return i;
		}
		return -1;
	}
};
int main() {
	Solution ans;
	std::vector<std::vector<int>> dd{{1,3},{2,3},{3,1}};
	ans.findJudge(3, dd);
}