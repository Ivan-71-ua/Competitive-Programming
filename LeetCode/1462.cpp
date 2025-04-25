#include <bits/stdc++.h>




class Solution {
	void dfs(int cur, int st, std::vector<std::vector<int>> &graf, std::vector<std::vector<bool>> &memo) {
		for(auto next: graf[cur]) {
			memo[st][next] = true;
			dfs(next, cur, graf, memo);
		}
	}
public:
	std::vector<bool> checkIfPrerequisite(int numCourses, std::vector<std::vector<int>>& prerequisites, std::vector<std::vector<int>>& queries) {
		std::vector<std::vector<bool>> memo(numCourses, std::vector<bool>(numCourses));
		//std::vector<std::vector<int>> graf(numCourses);
		for (int i = 0; i < prerequisites.size(); i++) {
			int a = prerequisites[i][0], b = prerequisites[i][1];
			memo[a][b] = true;
		}
		//алгоритм Флойда-Воршелла
		for (int k = 0; k < numCourses; k++) {
			for (int i = 0; i < numCourses; i++) {
				for (int j = 0; j < numCourses; j++) {
					memo[i][j] = memo[i][j] || (memo[i][k] && memo[k][j]);
				}
			}
		}

		std::vector<bool> ans(queries.size());
		for (int i = 0; i < queries.size(); i++) {
			int a = queries[i][0], b = queries[i][1];
			ans[i] = memo[a][b];
		}
		return ans;
	}
};