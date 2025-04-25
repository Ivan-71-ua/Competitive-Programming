#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> lexicalOrder(int n) {
        std::ios::sync_with_stdio(false);
         std::cin.tie(nullptr);
         std::cout.tie(nullptr);
		std::vector<int> res;
		std::vector<std::string> curs;
		for (int i = 1; i <= n; i++)
		{
			curs.push_back(std::to_string(i));
		}
		std::sort(curs.begin(), curs.end());
		for (auto now: curs)
		{
			res.push_back(std::stoi(now));
		}
		
		return res;
	}
};