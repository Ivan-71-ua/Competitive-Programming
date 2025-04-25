#include <bits/stdc++.h>

class Solution {
public:
   std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
		int n = img.size();
		int m = img[0].size();
		std::vector<std::vector<int>> ans(n,std::vector<int> (m));
		for (int i = 0; i < n; i++)
		{
			
			for (int j = 0; j < m; j++)
			{
				int sum = 0, k = 0;
				int x_l, y_l, x_r, y_r;
				if(i - 1 < 0)
					x_l = 0;
				else
					x_l = i - 1;
				if(j - 1 < 0)
					y_l = 0;
				else
					y_l = j - 1;
				if(i + 1 > n -1)
					x_r = n-1;
				else
					x_r = i + 1;
				if(j + 1 > m -1)
					y_r = m-1;
				else
					y_r = j + 1;
				
				for (int p = x_l; p <= x_r; p++)
				{
					for (int t = y_l; t <= y_r; t++)
					{
						sum += img[p][t];
						k++;
					}
					
				}
				ans[i][j] = sum / k;
			}
			
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<int>> img{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
	ans.imageSmoother(img);
}