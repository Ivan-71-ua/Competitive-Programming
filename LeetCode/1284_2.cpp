#include <bits/stdc++.h>


class Solution {
	void flip(std::vector<std::vector<int>>& mat, int x, int y) {
		int m = mat.size();
		int n = mat[0].size();
		std::vector<std::pair<int, int>> dirs = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		for (auto pr : dirs) {
			int nx = x + pr.first;
			int ny = y + pr.second;
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				mat[nx][ny] = 1 - mat[nx][ny];
			}
		}
	}
	bool isZeroMatrix(std::vector<std::vector<int>>& mat) {
		for (auto &row : mat) {
			for (auto cell : row) {
				if (cell != 0) return false;
			}
		}
		return true;
	}
	std::string matrixToString(const std::vector<std::vector<int>>& mat) {
		std::string result;
		for (auto& row : mat) {
			for (auto cell : row) {
				result += std::to_string(cell);
			}
		}
		return result;
	}
public:
	int minFlips(std::vector<std::vector<int>>& mat) {
		int m = mat.size();
		int n = mat[0].size();
		std::queue<std::vector<std::vector<int>>> q;
		std::unordered_set<std::string> visited;
		q.push(mat);
		visited.insert(matrixToString(mat));
		int steps = 0;
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				auto current = q.front();
				q.pop();
				if (isZeroMatrix(current)) return steps;
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						flip(current, i, j);
						std::string matStr = matrixToString(current);
						if (!visited.count(matStr)) {
							q.push(current);
							visited.insert(matStr);
						}
						flip(current, i, j); 
					}
				}
			}
			steps++;
		}
		return -1;
	}
};

int main() {
	Solution sol;
	std::vector<std::vector<int>> mat = {{0, 0}, {0, 1}};
	std::cout << sol.minFlips(mat) << std::endl; // Output: 3
	return 0;
}
