#include <bits/stdc++.h>

class Solution {
public:
	int findTheWinner(int n, int k) {
		std::vector<int> curcle(n);
		for (int i = 0; i < n; i++)
		{
			curcle[i] = i + 1;
		}
		int id = 0;
		while(curcle.size() != 1) {
			id += k - 1;
			id %= curcle.size();
			curcle.erase(curcle.begin() + id);
		}
		return curcle[0];
	}
};

int main() {
	Solution ans;
	ans.findTheWinner(6, 5);
}