#include <bits/stdc++.h>


class Solution {
public:
	int findComplement(int num) {
		std::vector<bool> res;
		while(num != 0) {
			if(num % 2 == 0) {
				res.push_back(false);
			} else {
				res.push_back(true);
			}
			num /= 2;
		}
		for (int i = 0; i < res.size(); i++)
		{
			res[i] = !res[i];
		}
		int ans = 0;
		for (int i = 0; i < res.size(); i++)
		{
			ans += res[i] ? pow(2, i) : 0;
		}
		return ans;
	}
};


int main() {
	Solution ans;
	ans.findComplement(5);
}