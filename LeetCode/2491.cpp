
#include <bits/stdc++.h>

class Solution {
public:
	long long dividePlayers(std::vector<int>& skill) {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		int n = skill.size();
		std::unordered_map<int, int> ost;
		long long pair_s = 0; 
		for (auto& s : skill) {
			ost[s]++;
			pair_s += s;
		}
		pair_s /= (n / 2);
		long long res = 0;
		while (!ost.empty()) {
			int a = ost.begin()->first;
			ost[a]--;
			if (ost[a] == 0) ost.erase(a);
			if (!ost.count(pair_s - a)) {
					return -1;
			}
			res += a * (pair_s - a);
			ost[pair_s - a]--;
			if (ost[pair_s - a] == 0) ost.erase(pair_s - a);
			
		}
		return res;

	}
};