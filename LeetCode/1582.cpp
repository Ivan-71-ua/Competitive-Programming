#include <bits/stdc++.h>

class Solution {
public:
   int numSpecial(std::vector<std::vector<int>>& mat) {
		int ans = 0;
		int m = mat.size();
		int n = mat[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int sum = 0;
				if(mat[i][j] == 1) {
					for (int l = 0; l < m; l++)
					{
						sum += mat[l][j];
						if(sum > 1) {
							break;
						}
					}
					for (int p = 0; p < n; p++)
					{
						sum += mat[i][p];
						if(sum > 2) {
							break;
						}
					}
					if(sum == 2) {
						ans++;
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<int>>  mat {{1,0,0}, {0,1,0}, {0,0,1}};
	std::cout << ans.numSpecial(mat);
}