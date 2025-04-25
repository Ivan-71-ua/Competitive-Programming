
#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
		std::vector<int> add;
		while(k) {
			add.push_back(k % 10);
			k /= 10;
		}
		std::reverse(add.begin(), add.end());
		std::vector<int> res(std::max(num.size(), add.size()) + 1);
		int cur_p = 0;
		int i = num.size() - 1;
		int j = add.size() - 1;
		int ost = 0;
		while(i > -1 && j > -1) {
			res[cur_p] = num[i] + add[j] + ost;
			ost = res[cur_p] / 10;
			res[cur_p] %= 10;
			i--;
			j--;
			cur_p++;
		}
		while(i > -1) {
			res[cur_p] = num[i] + ost;
			ost = res[cur_p] / 10;
			res[cur_p] %= 10;
			i--;
			cur_p++;
		}
		while(j > -1) {
			res[cur_p] =  add[j] + ost;
			ost = res[cur_p] / 10;
			res[cur_p] %= 10;
			j--;
			cur_p++;
		}
		if(ost) {
			res[cur_p] = ost;
		} else {
			res.pop_back();
		}
		std::reverse(res.begin(), res.end());
		return res;
	}
};

