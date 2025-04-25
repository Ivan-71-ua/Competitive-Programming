#include <bits/stdc++.h>






class Solution {
	public:
		int countNegatives(std::vector<std::vector<int>>& grid) {
			int res = 0;
			int n = grid.size(), m = grid[0].size();
			for (int i = 0; i < n; i++)
			{
				int tmp = m - 1;
				while(tmp > -1 && grid[i][tmp] < 0) {
					res++;
						 tmp--;
				}
			}
			return res;
		}

		bool is(double num, int persent) {
			std::string st = std::to_string(num);
			int fisrt = 0, second = 0;
			int gmb = 1;
			bool seconds = true;
			while(st.back() == '0')
				st.pop_back();
			for (int i = st.size() -1; i > -1; i--) {
				if(isdigit(st[i])) {
					if(seconds) {
						second += (st[i] - '0') * gmb;
					} else {
						fisrt += (st[i] - '0') * gmb;
					}
					gmb *= 10;
				} else {
					seconds = false;
					gmb = 1;
				}
			}
			if((fisrt * persent) / 100 < second)
				return true;
			return false;
		}
	};

int main() {
	Solution ans;
	ans.is(234.845, 30);
}