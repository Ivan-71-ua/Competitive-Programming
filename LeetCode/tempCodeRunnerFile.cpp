class Solution {
public:
	int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		std::vector<std::pair<int, int>> n_idxs(n * m);
		std::vector<int> xs(n, m);
		std::vector<int> ys(m, n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				n_idxs[mat[i][j] - 1] = {i, j};
			}
		}
		for (int i = 0; i < n * m; i++) {
			auto [x, y] = n_idxs[arr[i]];
			xs[x]--;
			ys[y]--;
			if(xs[x] * ys[y] == 0)
				return i;
		}
		return -1;
	}
};