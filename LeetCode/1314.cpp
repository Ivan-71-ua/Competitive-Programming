#include <bits/stdc++.h>



class Solution {
	int get_pref_sum(int x, int y, int x1, int y1, std::vector<std::vector<int>>& pref) {
		int hole_square = pref[x1][y1];
		int first_sector = pref[x - 1][y1];
		int second_sector = pref[x1][y - 1];
		int third_sector = pref[x - 1][y - 1];
		return hole_square - first_sector - second_sector + third_sector;
	}
public:
	std::vector<std::vector<int>> matrixBlockSum(std::vector<std::vector<int>>& mat, int k) {
		std::vector<std::vector<int>> pref_sum(mat.size() + 1, std::vector<int>(mat[0].size() + 1));
		for (int i = 1; i <= mat.size(); i++)
		{
			std::vector<int> pref(mat[0].size() + 1);
			for (int j = 1; j <= mat[0].size(); j++)
			{
				pref[j] = pref[j - 1] + mat[i - 1][j - 1];
				pref_sum[i][j] = pref_sum[i - 1][j] + pref[j];
			}
		}
		for (int i = 0; i < mat.size(); i++)
		{
			for (int j = 0; j < mat[0].size(); j++)
			{
				int x = std::max(0, i - k) + 1;
				int y = std::max(0, j - k) + 1;
				int x1 = std::min(i + k, (int)mat.size() - 1) + 1;
				int y1 = std::min(j + k, (int)mat[0].size() -1) + 1;
				mat[i][j] = get_pref_sum(x, y, x1, y1, pref_sum);
			}
		}
		return mat;
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<int>> ss{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	ans.matrixBlockSum(ss, 1);
}